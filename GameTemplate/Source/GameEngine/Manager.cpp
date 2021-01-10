#include "Manager.h"
#include "GameObjectManager.h"

Manager::Manager() {
	GameObjectManager::GetInstance().AddGameObject(this);
}

Manager::Manager(string tag) {
	setTag(tag);
	GameObjectManager::GetInstance().AddGameObject(this);
}

void Manager::destroy(GameObject* other) {
	GameObjectManager::GetInstance().RemoveGameObject(other);
}
