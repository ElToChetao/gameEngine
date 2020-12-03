
#include "Singleton.h"
#include "SDL.h"
#include "InputManager.h"
#include "RenderManager.h"
#include "GameObjectManager.h"

class ManagerOfManagers :public Singleton<ManagerOfManagers>
{
	friend class Singleton<ManagerOfManagers>;
public:
	ManagerOfManagers() {};

	bool Init(void) {
		// init all managers

		InputManager::CreateSingleton();
		RenderManager::CreateSingleton();
		GameObjectManager::CreateSingleton();

		if (!RenderManager::GetInstance().Init())
		{
			return false;
		}

		return true;
	}
	void Update(void) {
		// update all managers

		InputManager::GetInstance().Update();
		GameObjectManager::GetInstance().Update();
		RenderManager::GetInstance().Update();
	}
	
	void Destroy(void) {
		// destroy all managers

		RenderManager::DestroySingleton();
		InputManager::DestroySingleton();
		ManagerOfManagers::DestroySingleton();
	}
};
