#include "Map.h"

Map* Map::instance = nullptr;

Map::Map(int sizeX, int sizeY, int viewportX, int viewportY)
	: mapSizeX(sizeX), mapSizeY(sizeY), viewportSizeX(viewportX), viewportSizeY(viewportY) {
	tileDictionary = TileDictionary();

	mapData = vector<vector<int>>(mapSizeX, vector<int>(mapSizeY, 1));

	int startX = mapSizeX / 2;
	int startY = mapSizeY / 2;
	for (int x = 0; x < 10; x++)
		for (int y = 0; y < 10; y++) {
			if (x < 0 || x > mapSizeX || y < 0 || y > mapSizeY)
				continue;
			mapData[startY + y][startX + x] = 2;
		}

	SetViewportPosition(mapSizeX / 2, mapSizeY / 2);
}

void Map::PrintMap()
{
	// Iterate over the viewport and compare with the current map data
	for (int y = 0; y < viewportSizeY; y++) {
		for (int x = 0; x < viewportSizeX; x++) {
			int mapX = viewportPositionX + x;
			int mapY = viewportPositionY + y;

			// Check if the position is within map bounds
			if (isInMapBounds(mapX, mapY)) {
				int tileID = mapData[mapY][mapX];

				// Compare with the previous state of the viewport
				if (viewport[x][y] != tileID) {
					viewport[x][y] = tileID;

					// Update the display only for changed tiles
					Display::GetInstance()->SetCursorPosition(x, y);
					std::cout << tileDictionary.GetTile(tileID).GetSymbol();
				}
			}
			else {
				// If out of map bounds, use a default tile ID (e.g., 9)
				if (viewport[x][y] != 9) {
					viewport[x][y] = 9;
					Display::GetInstance()->SetCursorPosition(x, y);
					std::cout << tileDictionary.GetTile(9).GetSymbol();
				}
			}
		}
	}
	Display::GetInstance()->SetCursorPosition(0, 26);
	std::cout << viewportPositionX << " , " << viewportPositionY;
	Display::GetInstance()->PlaceCursorAtBottom();
}

void Map::PrintMapFull() {
	Display::GetInstance()->SetCursorPosition(0, 0);

	// Ensure that the loop iterates over the correct range
	for (int y = 0; y < viewportSizeY; y++) {
		for (int x = 0; x < viewportSizeX; x++) {
			// Ensure x and y are within map bounds before accessing mapData
			if (isInMapBounds(viewportPositionX + x, viewportPositionY + y))
				viewport[x][y] = mapData[viewportPositionY + y][viewportPositionX + x];
			else
				viewport[x][y] = 0; // debug tile
		}
	}

	// Print the contents of the viewport
	for (int y = 0; y < viewportSizeY; y++) {
		for (int x = 0; x < viewportSizeX; x++) {
			std::cout << tileDictionary.GetTile(viewport[x][y]).GetSymbol();
		}
		std::cout << std::endl; // Add a newline at the end of each row for proper formatting
	}
	std::cout << viewportPositionX << " , " << viewportPositionY;
	Display::GetInstance()->PlaceCursorAtBottom();
}

//used to set viewport
void Map::SetViewportPosition(int x, int y)
{
	//if the viewport would extend past the map, don't let it
	if (x < 0)
		x = 0;
	if (x > mapSizeX - viewportSizeX)
		x = mapSizeX - viewportSizeX;
	if (y < 0)
		y = 0;
	if (y > mapSizeY - viewportSizeY)
		y = mapSizeY - viewportSizeY;

	viewportPositionX = x;
	viewportPositionY = y;
}

bool Map::IsTileWalkableAt(int x, int y)
{
	if (!isInMapBounds(x, y))
		return false;

	return tileDictionary.GetTile(mapData[y][x]).IsWalkable();
}

//makes sure it's in bounds
bool Map::isInMapBounds(int x, int y)
{
	if (x >= 0 && x < mapSizeX && y >= 0 && y < mapSizeY)
		return true;
	else
		return false;
}