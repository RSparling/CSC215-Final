#include "Display.h"

Display* Display::instance = nullptr;

// Constructor
Display::Display() :hConsole(GetStdHandle(STD_OUTPUT_HANDLE)),
bufferSize({ (short)120, (short)26 }),
windowSize({ 0, 0, 120, 26 })
{
	CheckConsoleHandle(); // Check if the console handle is valid
	SetBufferSize(); // Set the console screen buffer size
	SetWindowInfo(); // Set the console window info
}

// Get the instance of the Display class
Display* Display::GetInstance()
{
	if (instance == nullptr)
		instance = new Display();
	return instance;
}

// Set the cursor position
void Display::SetCursorPosition(int x, int y)
{
	if (x < 0 || x > 120 || y < 0 || y > 26) {
		std::cout << "Error: INVALID COORDINATES IN DISPLAY" << std::endl;
		return;
	}
	COORD coord = { (short)x, (short)y };
	SetConsoleCursorPosition(hConsole, coord);
}

// Set the cursor position using a COORD object
void Display::SetCursorPosition(COORD coord)
{
	if (coord.X < 0 || coord.X > 120 || coord.Y < 0 || coord.Y > 26) {
		std::cout << "Error: INVALID COORDINATES IN DISPLAY" << std::endl;
		return;
	}
	SetConsoleCursorPosition(hConsole, coord);
}

// Place the cursor at the bottom of the display
void Display::PlaceCursorAtBottom() {
	COORD bottom = { 120,26 };
	SetConsoleCursorPosition(hConsole, bottom);
}

// Draw a border around the main display
void Display::DrawBorderAroundMainDisplay()
{
	SetCursorPosition(0, 0);
	for (int i = 0; i < 120; i++)
		std::cout << '_';

	for (int i = 1; i < 26; i++) {
		SetCursorPosition(0, i);
		std::cout << '|';
		SetCursorPosition(119, i);
		std::cout << '|';
	}

	SetCursorPosition(0, 26);
	for (int i = 0; i < 120; i++)
		std::cout << '_';
}

// Check if the console handle is valid
void Display::CheckConsoleHandle()
{
	if (hConsole == INVALID_HANDLE_VALUE)
		std::cerr << "Error: Invalid console handle value in Display" << std::endl;
}

// Set the console screen buffer size
void Display::SetBufferSize()
{
	if (!SetConsoleScreenBufferSize(hConsole, bufferSize))
		std::cerr << "Error: Could not set console screen buffer size in Display" << std::endl;
}

// Set the console window info
void Display::SetWindowInfo()
{
	if (!SetConsoleWindowInfo(hConsole, TRUE, &windowSize))
		std::cerr << "Error: Could not set console window info in Display" << std::endl;
}