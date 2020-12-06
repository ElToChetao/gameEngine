#pragma once
#include "Singleton.h"
#include "SDL.h"
#include "Vector2.h"
#include "GameObject.h"
#include <Texture.h>
#include <vector>


class GameObjectManager :public Singleton<GameObjectManager>
{
	friend class Singleton<GameObjectManager>;
private:
	vector<GameObject*> gameObjects;
	GameObjectManager();
public:
	vector<GameObject*> GetGameObjects();

	void Init();

	void Update();
	void Destroy();

	void AddGameObject(GameObject* go);
	void RemoveGameObject(GameObject* go);
};

