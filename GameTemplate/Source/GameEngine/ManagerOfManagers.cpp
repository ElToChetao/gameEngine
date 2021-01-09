#include "ManagerOfManagers.h"

ManagerOfManagers::ManagerOfManagers() {
	gameRunning = true;
}

bool ManagerOfManagers::Init(void) {
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

void ManagerOfManagers::PhysicUpdate() {
	PhysicsManager::GetInstance().Update();
}
void ManagerOfManagers::InputUpdate() {
	TimeManager::GetInstance().Update();
	InputManager::GetInstance().Update();
}

void ManagerOfManagers::Update(void) {
	SDL_Event e;
	while (SDL_PollEvent(&e) != 0)
	{
		//User requests quit
		if (e.type == SDL_QUIT)
		{
			Exit();
		}
	}

	// update all managers
	thread inputThread(&ManagerOfManagers::InputUpdate, this);
	thread physicThread(&ManagerOfManagers::PhysicUpdate, this);

	inputThread.join();
	physicThread.join();

	GameObjectManager::GetInstance().Update();
	thread audioThread(&AudioManager::Update, &AudioManager::GetInstance());
	RenderManager::GetInstance().Update();
	audioThread.join();
}

void ManagerOfManagers::Exit() {
	gameRunning = false;
}
void ManagerOfManagers::Destroy(void) {
	AudioManager::DestroySingleton();
	RenderManager::DestroySingleton();
	GameObjectManager::DestroySingleton();
	PhysicsManager::DestroySingleton();
	InputManager::DestroySingleton();
	TimeManager::DestroySingleton();
	ManagerOfManagers::DestroySingleton();
	exit(0);
}