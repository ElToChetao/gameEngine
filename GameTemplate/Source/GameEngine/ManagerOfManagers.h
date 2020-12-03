
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
	void Update(void);
	bool Init(void);
	void Destroy(void);
};
bool ManagerOfManagers::Init() {

	// init all managers
	InputManager::CreateSingleton();

	RenderManager::CreateSingleton();

	GameObjectManager::CreateSingleton();

	if (!RenderManager::GetInstance().Init()) {
		return false;
	}

	return true;
}
void ManagerOfManagers::Update() {
	// update all managers

	//RenderManager::GetInstance();

	InputManager::GetInstance().Update();
	GameObjectManager::GetInstance().Update();

}
void ManagerOfManagers::Destroy() {
	// destroy all managers

	RenderManager::DestroySingleton();

	InputManager::DestroySingleton();

	ManagerOfManagers::DestroySingleton();
}
