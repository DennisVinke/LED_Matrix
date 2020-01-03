#pragma once

#include "wiringPi.h"

constexpr unsigned UP = 0;
constexpr unsigned DOWN = 1;
constexpr unsigned LEFT = 2;
constexpr unsigned RIGHT = 3;
constexpr unsigned FIRE1 = 4;
constexpr unsigned FIRE2 = 5;
constexpr unsigned AMOUNT_OF_BUTTONS = 6;

class InputManager {
public:
	InputManager();
	~InputManager();
	void updateButtonStates();
	bool getState(unsigned index);
private:
	void setupButtons();
	bool buttonStates[6] = { false, false, false, false, false, false };
	const int buttons_piloc[6] = { 35, 36, 37, 38, 31, 32 }; //Pi pin locations
	const int buttons[6] = { 24, 27, 25, 28, 22, 26 }; //WiPi pin locations

};