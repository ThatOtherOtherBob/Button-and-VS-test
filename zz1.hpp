#pragma once
#include "game.hpp"
#include<vector>

class ButtonStates
{
public:
	ButtonStates();
	ButtonStates(blit::ButtonState buttons);

	bool Up, Down, Left, Right, A, B, X, Y, Home, Menu, Stick;
};

enum ButtonEvents
{
	Up_Pressed,
	Up_Released,
	Down_Pressed,
	Down_Released,
	Left_Pressed,
	Left_Released,
	Right_Pressed,
	Right_Released,
	A_Pressed,
	A_Released,
	B_Pressed,
	B_Released,
	X_Pressed,
	X_Released,
	Y_Pressed,
	Y_Released,
	Home_Pressed,
	Home_Released,
	Menu_Pressed,
	Menu_Released,
	Stick_Pressed,
	Stick_Released
};


class ButtonHandler
{
public:
	ButtonStates Current;

	std::vector<ButtonEvents> UpdateStates(blit::ButtonState buttons);
private:
	ButtonStates _last;
};