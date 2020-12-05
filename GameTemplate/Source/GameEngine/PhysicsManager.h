#pragma once

#include "Singleton.h"
#include "SDL.h"
#include "GameObjectManager.h"
#include <typeinfo>

class PhysicsManager :public Singleton<PhysicsManager>
{
	/*****************************************************************************/
	friend class Singleton<PhysicsManager>;
	/*****************************************************************************/

private:

	// Keyboard state
	const Uint8* mCurrentKeyStates;

	// Private constructor to avoid more than one instance
	PhysicsManager() {};

	/*****************************************************************************/

public:

	void Update() {
		vector<GameObject*> go = GameObjectManager::GetInstance().GetGameObjects();
		for (int i = 0; i < go.size(); i++) {
			//Collider colGo = go[i].collider;
			for (int j = i; j < go.size(); j++){
			}
		}
	}
	void CheckCollisions(Collider go, Collider other) {
		string goType = typeid(go).name();
		string otherType = typeid(go).name();
		if (goType == "CircleCollider" && otherType == "CircleCollider") {

		}
	}
	void CheckCircleCollisions(CircleCollider go, CircleCollider other) {

	}

	/*****************************************************************************/

};