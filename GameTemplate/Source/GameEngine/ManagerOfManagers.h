
#include "Singleton.h"
#include "SDL.h"
#include "InputManager.h"
#include "RenderManager.h"
#include "GameObjectManager.h"

class ManagerOfManagers :public Singleton<ManagerOfManagers>
{
	friend class Singleton<ManagerOfManagers>;
public:
	ManagerOfManagers() {
		Init();
	}
	void Update(void);
	void Init(void);
	void Destroy(void);
};
void ManagerOfManagers::Init() {
	// init all managers
	InputManager::CreateSingleton();

	RenderManager::CreateSingleton();

	GameObjectManager::CreateSingleton();
}
void ManagerOfManagers::Update() {
	// update all managers

	InputManager::GetInstance().Update();

}
void ManagerOfManagers::Destroy() {
	// destroy all managers

	RenderManager::DestroySingleton();

	InputManager::DestroySingleton();

	ManagerOfManagers::DestroySingleton();
}
