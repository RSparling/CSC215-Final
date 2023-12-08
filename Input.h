#pragma once
#include <iostream>
#include <vector>
#include <conio.h>

enum KeyCode {
	Arrow_Up,
	Arrow_Down,
	Arrow_Left,
	Arrow_Right,
	Esc,
	Enter,
	LAST_ELEMENT
};

class Input
{
public:
	Input(); //constructor
	void Update();//update instance
	static Input* GetInstance();//

	bool GetKeyDown(KeyCode key);
	static bool SuspendInput; //used when input shouldnt be retrieved.
private:
	static Input* instance;
	std::vector<bool> inputs;
};