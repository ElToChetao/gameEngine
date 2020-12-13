
#include "Singleton.h"
#include "SDL.h"
#include "InputManager.h"
#include "RenderManager.h"
#include "GameObjectManager.h"
#include "PhysicsManager.h"
#include "TimeManager.h"
#include "AudioManager.h"
#include <SDL_thread.h>

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
		AudioManager::CreateSingleton();

		GameObjectManager::GetInstance().Init();
		AudioManager::GetInstance().Init();

		if (!RenderManager::GetInstance().Init())
		{
			return false;
		}

		return true;
	}
	int TestThread(void* data) {
		RenderManager::GetInstance().Update();
		return 0;
	}
	int SDL_ThreadFunction(void* data) {
		//Print incoming data
		printf("Running thread with value = %d\n", (int)data);
		return 0;
	}


	void Update(void) {
		// update all managers
		int data = 101;
		//SDL_Thread* thread = SDL_CreateThread(SDL_ThreadFunction, "TestThread", (void*)data);

		TimeManager::GetInstance().Update();
		InputManager::GetInstance().Update();
		PhysicsManager::GetInstance().Update();
		GameObjectManager::GetInstance().Update();
		RenderManager::GetInstance().Update();
		AudioManager::GetInstance().Update();
		//SDL_WaitThread(thread, NULL);
	}
	
	void Destroy(void) {
		// destroy all manager
		AudioManager::GetInstance().
		AudioManager::DestroySingleton();
		RenderManager::DestroySingleton();
		GameObjectManager::DestroySingleton();
		PhysicsManager::DestroySingleton();
		InputManager::DestroySingleton();
		TimeManager::DestroySingleton();
		ManagerOfManagers::DestroySingleton();
	}
};
