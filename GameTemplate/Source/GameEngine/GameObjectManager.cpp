#include "GameObjectManager.h"

GameObjectManager::GameObjectManager() {}

vector<GameObject*> GameObjectManager::GetGameObjects() {
	vector<GameObject*> activeObjects;
	for (int i = 0; i < gameObjects.size(); i++) {
		if (gameObjects[i]->isActive) {
			activeObjects.push_back(gameObjects[i]);
		}
	}
	return activeObjects;
}

void GameObjectManager::Init() {
}

void GameObjectManager::Update() {
	for (int i = 0; i < managers.size(); i++) {
		managers[i]->update();
	}
	for (int i = 0; i < gameObjects.size(); i++) {
		gameObjects[i]->update();
	}
}

void GameObjectManager::Destroy() {

}

void GameObjectManager::AddGameObject(GameObject* go) {
	gameObjects.push_back(go);
}

void GameObjectManager::RemoveGameObject(GameObject* go) {
	gameObjects.erase(remove(gameObjects.begin(), gameObjects.end(), go), gameObjects.end());
}