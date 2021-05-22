#include "zz1.hpp"

ButtonStates::ButtonStates()
{
	Up = false;
	Down = false;
	Left = false;
	Right = false;
	A = false;
	B = false;
	X = false;
	Y = false;
	Home = false;
	Menu = false;
	Stick = false;
}

ButtonStates::ButtonStates(blit::ButtonState buttons)
{
	Up = (buttons & blit::Button::DPAD_UP) != 0;
	Down = (buttons & blit::Button::DPAD_DOWN) != 0;
	Left = (buttons & blit::Button::DPAD_LEFT) != 0;
	Right = (buttons & blit::Button::DPAD_RIGHT) != 0;
	A = (buttons & blit::Button::A) != 0;
	B = (buttons & blit::Button::B) != 0;
	X = (buttons & blit::Button::X) != 0;
	Y = (buttons & blit::Button::Y) != 0;
	Home = (buttons & blit::Button::HOME) != 0;
	Menu = (buttons & blit::Button::MENU) != 0;
	Stick = (buttons & blit::Button::JOYSTICK) != 0;
}

std::vector<ButtonEvents> ButtonHandler::UpdateStates(blit::ButtonState buttons)
{
	std::vector<ButtonEvents> events;

	_last = Current;
	Current = ButtonStates(buttons);

	if (_last.Up != Current.Up) events.push_back(Current.Up ? Up_Pressed : Up_Released);
	if (_last.Down != Current.Down) events.push_back(Current.Down ? Down_Pressed : Down_Released);
	if (_last.Left != Current.Left) events.push_back(Current.Left ? Left_Pressed : Left_Released);
	if (_last.Right != Current.Right) events.push_back(Current.Right ? Right_Pressed : Right_Released);
	if (_last.A != Current.A) events.push_back(Current.A ? A_Pressed : A_Released);
	if (_last.B != Current.B) events.push_back(Current.B ? B_Pressed : B_Released);
	if (_last.X != Current.X) events.push_back(Current.X ? X_Pressed : X_Released);
	if (_last.Y != Current.Y) events.push_back(Current.Y ? Y_Pressed : Y_Released);
	if (_last.Home != Current.Home) events.push_back(Current.Home ? Home_Pressed : Home_Released);
	if (_last.Menu != Current.Menu) events.push_back(Current.Menu ? Menu_Pressed : Menu_Released);
	if (_last.Stick != Current.Stick) events.push_back(Current.Stick ? Stick_Pressed : Stick_Released);

	return events;
}