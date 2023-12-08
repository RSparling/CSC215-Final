#pragma once
#ifndef MAP_H
#define MAP_H

#include <iostream>
#include <vector>
#include "Display.h"
using std::vector;

/*
<summary>
This struct represents a tile in the game world.
</summary>
*/
struct Tile {
public:
	Tile(bool isWalkable = false, char symbol = '?') : isWalkable(isWalkable), symbol(symbol) {}
	bool IsWalkable() { return isWalkable; }
	char GetSymbol() { return symbol; }
private:
	bool isWalkable;
	char symbol;
};

/*
	<summary>
	This class is used to store all the tiles in the game world.
	</summary>
*/
class TileDictionary {
public:
	TileDictionary() {
		dictionary = vector<Tile>();
		dictionary.push_back(Tile());
		dictionary.push_back(Tile(true, '.')); //floor
		dictionary.push_back(Tile(true, '#')); //wall
	}

	Tile GetTile(int id) {
		if (id >= 0 && id < dictionary.size())
			return dictionary[id];
		else
			return Tile();
	}
private:
	vector<Tile> dictionary; //vector since the size is unknown
};

class Map
{
public:
	Map(int sizeX = 200, int sizeY = 200, int viewportX = 120, int viewportY = 26);

	//Singleton Getter
	static Map* GetInstance() {
		if (instance == nullptr)
			instance = new Map();
		return instance;
	}

	//print only the tiles that have changed
	void PrintMap();

	//print the entire map
	void PrintMapFull();

	//set the viewport position
	void SetViewportPosition(int x, int y);

	//getters
	int GetViewportPositionX() { return viewportPositionX; }
	int GetViewportPositionY() { return viewportPositionY; }
	int GetMapSizeX() { return mapSizeX; }
	int GetMapSizeY() { return mapSizeY; }
	//see if tile is walkable
	bool IsTileWalkableAt(int x, int y);
private:
	//tile dictionary
	TileDictionary tileDictionary;

	int viewport[120][26] = {}; //array since console size is known;

	//viewport size
	int viewportSizeX = 120;
	int viewportSizeY = 26;

	//map data
	vector<vector<int>> mapData;

	//utility functions
	bool isInMapBounds(int x, int y);

	//map size
	int mapSizeX = 200;
	int mapSizeY = 200;

	//player position
	int viewportPositionX = 0;
	int viewportPositionY = 0;

	//singleton
	static Map* instance;
};

#endif // MAP_H