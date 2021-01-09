#include "InputManager.h"

/*****************************************************************************/

void InputManager::Update(void)
{
  mCurrentKeyStates = SDL_GetKeyboardState(NULL);
  SDL_GetMouseState(&mouseX, &mouseY);
}
/*****************************************************************************/

Vector2 InputManager::GetMousePosition() {
	return Vector2(mouseX, mouseY);
}

bool InputManager::GetKey(int scanCode)
{
  return mCurrentKeyStates[scanCode] != 0;
}

/*****************************************************************************/

float InputManager::GetAxis(string axis)
{
	float input = 0;
	if (axis == "Horizontal")
	{
		input = mCurrentKeyStates[SDL_SCANCODE_A] - mCurrentKeyStates[SDL_SCANCODE_D];
	}
	else if (axis == "Vertical")
	{
		input = mCurrentKeyStates[SDL_SCANCODE_S] - mCurrentKeyStates[SDL_SCANCODE_W];
	}
	else if (axis == "Horizontal Arrows")
	{
		input = mCurrentKeyStates[SDL_SCANCODE_RIGHT] - mCurrentKeyStates[SDL_SCANCODE_LEFT];
	} 
	else if (axis == "Vertical Arrows")
	{
		input = mCurrentKeyStates[SDL_SCANCODE_DOWN] - mCurrentKeyStates[SDL_SCANCODE_UP];
	}
	return input;
}