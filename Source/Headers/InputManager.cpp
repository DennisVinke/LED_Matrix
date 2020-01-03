#include "InputManager.hpp"

InputManager::InputManager() {

}

InputManager::~InputManager() {

}

void InputManager::updateButtonStates() {
	for (unsigned i = 0; i < AMOUNT_OF_BUTTONS;i++) {
		buttonStates[i] = digitalRead(buttons[i]);
	}
}

bool InputManager::getState(unsigned index)
{	
	return (index < AMOUNT_OF_BUTTONS) ? buttonStates[index] : false;
}

void InputManager::setupButtons()
{
	wiringPiSetup();
	for (unsigned i; i < AMOUNT_OF_BUTTONS; i++) {
		pinMode(buttons[i], INPUT); //set input 
		//pullUpDnControl(buttons[UP], PUD_UP); //set the pin to use a built-in pull up resistor
	}
}
