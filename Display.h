#pragma once
#include <iostream>
#include <windows.h>
/*
<summary>
contains utility functions to aid screens with displaying and outputting information.
</summary>
*/
class Display
{
public:
	Display();

	static Display* GetInstance();
	
	
	void SetCursorPosition(int x, int y);
	void SetCursorPosition(COORD coord);
	void PlaceCursorAtBottom();

	//Things to dress it up
	void DrawBorderAroundMainDisplay();
private:
	static Display* instance;

	//console variables
	HANDLE hConsole = NULL;
	COORD bufferSize = { (short)120,(short)26 };
	SMALL_RECT windowSize;

	//console functions for setup
	void CheckConsoleHandle();
	void SetBufferSize();
	void SetWindowInfo();
};