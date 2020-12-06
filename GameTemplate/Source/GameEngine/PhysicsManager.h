#pragma once

#include "Singleton.h"
#include "SDL.h"
#include "GameObjectManager.h"
#include <typeinfo>
#include <Math.h>

class PhysicsManager :public Singleton<PhysicsManager>
{
	/*****************************************************************************/
	friend class Singleton<PhysicsManager>;
	/*****************************************************************************/

private:

	// Keyboard state
	const Uint8* mCurrentKeyStates;

	// Private constructor to avoid more than one instance
	PhysicsManager();

	/*****************************************************************************/

public:

	void Update();
	
	bool CheckCollisions(GameObject* go, GameObject* other);

	bool CheckCircleCollisions(GameObject* go, GameObject* other);

	bool CheckRectCollisions(GameObject* go, GameObject* other);

	bool CheckRectCircleCollisions(GameObject* rect, GameObject* circle);

	/*****************************************************************************/

};