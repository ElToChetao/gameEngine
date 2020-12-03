#pragma once
#include "Singleton.h"
#include "SDL.h"
#include <Texture.h>
#include <vector>

class Vector2 {
public:
	int x;
	int y;
	Vector2() {
		x = 0;
		y = 0;
	}
	Vector2(int x, int y) {
		this->x = x;
		this->y = y;
	}
	Vector2& operator+=(const Vector2& other) {
		this->x += other.x;
		this->y += other.y;
		return *this;
	}
};


class Transform {
public:
	Vector2 position;
	int rotation;

	Transform() {
		rotation = 0;
	}
};
class GameObject {
public:
	Transform transform;
	bool isActive;
	LTexture texture;

	GameObject() {
	}

	GameObject(string spritePath) {
		isActive = true;

		if (!texture.loadFromFile(spritePath))
		{
			printf("Failed to load gameobject texture!\n");
		}
		start();
	}
	void translate(Vector2 offset) {
		transform.position += offset;
	}
	void render() {
		texture.render(transform.position.x, transform.position.y);
	}
	void update() {

	}
	void start() {

	}
	void destroy() {
		texture.free();
	}
};

class GameObjectManager :public Singleton<GameObjectManager>
{
	friend class Singleton<GameObjectManager>;
private:
	vector<GameObject*> gameObjects;
	GameObjectManager() {};
public:

	void Update(void);

	void AddGameObject(GameObject*);
	vector<GameObject*> GetGameObjects() { return gameObjects; };
};
void GameObjectManager::Update() {
	for (int i = 0; i < gameObjects.size(); i++) {
		gameObjects[i]->update();
	}
}
void GameObjectManager::AddGameObject(GameObject *go) {
	gameObjects.push_back(go);
}