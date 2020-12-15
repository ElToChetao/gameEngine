#include "ManagerOfManagers.h"
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

void ManagerOfManagers::Destroy(void) {
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