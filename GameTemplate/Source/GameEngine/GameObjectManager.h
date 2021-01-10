#pragma once
#include "Singleton.h"
#include "SDL.h"
#include "Vector2.h"
#include "GameObject.h"
#include "Manager.h"
#include <Texture.h>
#include <vector>


class GameObjectManager :public Singleton<GameObjectManager>
{
	friend class Singleton<GameObjectManager>;
private:
	vector<GameObject*> gameObjects;
	vector<Manager*> managers;
	GameObjectManager();
public:
	vector<GameObject*> GetGameObjects();

	void Init();

	void Update();
	void Destroy();

	void AddGameObject(GameObject* go);
	void RemoveGameObject(GameObject* go);

	void AddGameObject(Manager* go);
	void RemoveGameObject(Manager* go);
};

