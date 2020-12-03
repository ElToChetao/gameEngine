#include "InputManager.h"

/*****************************************************************************/

void InputManager::Update(void)
{
  mCurrentKeyStates = SDL_GetKeyboardState(NULL);
}
/*****************************************************************************/

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
		input = mCurrentKeyStates[SDL_SCANCODE_RIGHT] - mCurrentKeyStates[SDL_SCANCODE_LEFT];
	}
	else if (axis == "Vertical")
	{
		input = mCurrentKeyStates[SDL_SCANCODE_DOWN] - mCurrentKeyStates[SDL_SCANCODE_UP];
	}
	return input;
}