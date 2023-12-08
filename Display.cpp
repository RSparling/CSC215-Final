#include "Display.h"

Display* Display::instance = nullptr;

Display::Display() :hConsole(GetStdHandle(STD_OUTPUT_HANDLE)),
bufferSize({ (short)120, (short)26 }),
windowSize({ 0, 0, 120, 26 })
{
	CheckConsoleHandle();
	SetBufferSize();
	SetWindowInfo();
}

Display* Display::GetInstance()
{
	if (instance == nullptr)
		instance = new Display();
	return instance;
}

void Display::SetCursorPosition(int x, int y)
{
	if (x < 0 || x > 120 || y < 0 || y > 26) {
		std::cout << "Error: INVALID COORDINATES IN DISPLAY" << std::endl;
		return;
	}
	COORD coord = { (short)x, (short)y };
	SetConsoleCursorPosition(hConsole, coord);
}

void Display::SetCursorPosition(COORD coord)
{
	if (coord.X < 0 || coord.X > 120 || coord.Y < 0 || coord.Y > 26) {
		std::cout << "Error: INVALID COORDINATES IN DISPLAY" << std::endl;
		return;
	}
	SetConsoleCursorPosition(hConsole, coord);
}

void Display::PlaceCursorAtBottom() {
	COORD bottom = { 120,26 };
	SetConsoleCursorPosition(hConsole, bottom);
}

void Display::CheckConsoleHandle()
{
	if (hConsole == INVALID_HANDLE_VALUE)
		std::cerr << "Error: Invalid console handle value in Display" << std::endl;
}

void Display::SetBufferSize()
{
	if (!SetConsoleScreenBufferSize(hConsole, bufferSize))
		std::cerr << "Error: Could not set console screen buffer size in Display" << std::endl;
}

void Display::SetWindowInfo()
{
	if (!SetConsoleWindowInfo(hConsole, TRUE, &windowSize))
		std::cerr << "Error: Could not set console window info in Display" << std::endl;
}