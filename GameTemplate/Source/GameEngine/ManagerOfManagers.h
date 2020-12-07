
#include "Singleton.h"
#include "SDL.h"
#include "InputManager.h"
#include "RenderManager.h"
#include "GameObjectManager.h"
#include "PhysicsManager.h"
#include "TimeManager.h"

class ManagerOfManagers :public Singleton<ManagerOfManagers>
{
	friend class Singleton<ManagerOfManagers>;
public:
	ManagerOfManagers() {};

	bool Init(void) {
		// init all managers
		TimeManager::CreateSingleton();
		InputManager::CreateSingleton();
		GameObjectManager::CreateSingleton();
		RenderManager::CreateSingleton();
		PhysicsManager::CreateSingleton();

		GameObjectManager::GetInstance().Init();

		if (!RenderManager::GetInstance().Init())
		{
			return false;
		}

		return true;
	}
	void Update(void) {
		// update all managers
		TimeManager::GetInstance().Update();
		InputManager::GetInstance().Update();
		PhysicsManager::GetInstance().Update();
		GameObjectManager::GetInstance().Update();
		RenderManager::GetInstance().Update();
	}
	
	void Destroy(void) {
		// destroy all managers
		RenderManager::DestroySingleton();
		GameObjectManager::DestroySingleton();
		PhysicsManager::DestroySingleton();
		InputManager::DestroySingleton();
		TimeManager::GetInstance().DestroySingleton();
		ManagerOfManagers::DestroySingleton();
	}
};
