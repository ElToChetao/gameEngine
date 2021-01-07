#pragma once

#include "Singleton.h"
#include "SDL.h"
#include "GameObjectManager.h"

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
	
	double distanceSquared(int x1, int y1, int x2, int y2);

	bool CheckCollisions(GameObject* go, GameObject* other);
	GameObject* CheckSphere (Vector2 position, float radius);

	void UpdateState(GameObject* go, bool collision, GameObject* go2);

	bool CheckCircleCollisions(GameObject* go, GameObject* other);
	bool CheckCircleCollisions(Vector2 position, float radius, GameObject* other);

	bool CheckRectCollisions(GameObject* go, GameObject* other);

	bool CheckRectCircleCollisions(GameObject* rect, GameObject* circle);
	bool CheckRectCircleCollisions(GameObject* rect, Vector2 centerCircle, float radius);

	/*****************************************************************************/

};