#pragma once

#include "Singleton.h"
#include "SDL.h"
#include "Vector2.h"

/**
Input Manager class
*/
class InputManager :public Singleton<InputManager>
{
	/*****************************************************************************/
	friend class Singleton<InputManager>;
	/*****************************************************************************/

private:
  
	// Keyboard state
	const Uint8*  mCurrentKeyStates;

	// Private constructor to avoid more than one instance
	InputManager() {};

	/*****************************************************************************/

public:
	int mouseX;
	int mouseY;
	void Update( void );

	bool GetKey( int scanCode );

	Vector2 GetMousePosition();

	float GetAxis(string axis);

	/*****************************************************************************/

};