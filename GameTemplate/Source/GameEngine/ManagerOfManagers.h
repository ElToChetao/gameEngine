#pragma once
#include "Singleton.h"
#include "SDL.h"
#include "InputManager.h"
#include "RenderManager.h"
#include "GameObjectManager.h"
#include "PhysicsManager.h"
#include "TimeManager.h"
#include "AudioManager.h"
#include <thread>

class ManagerOfManagers :public Singleton<ManagerOfManagers>
{
	friend class Singleton<ManagerOfManagers>;
public:
	ManagerOfManagers() {};

	bool Init(void);

	void PhysicUpdate();
	void InputUpdate();
	void Update(void);

	void Destroy(void);
};
