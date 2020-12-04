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
	Vector2& operator-=(const Vector2& other) {
		this->x -= other.x;
		this->y -= other.y;
		return *this;
	}
	Vector2& operator*(const int other) {
		this->x *= other;
		this->y *= other;
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
	string name;

	GameObject(){
		start();
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

	virtual void start() {

	}
	virtual void update() {

	}
	
	virtual void destroy() {
		texture.free();
	}
	virtual void onCollision() {

	}
};

class GameObjectManager :public Singleton<GameObjectManager>
{
	friend class Singleton<GameObjectManager>;
private:
	vector<GameObject*> gameObjects;
	GameObjectManager() {};
public:
	vector<GameObject*> GetGameObjects() {
		return gameObjects; 
	}

	void Init() {
	}

	void Update() {
		for (int i = 0; i < gameObjects.size(); i++) {
			gameObjects[i]->update();
		}
	}
	void AddGameObject(GameObject *go) {
		gameObjects.push_back(go);
	}
};