#pragma once
#include "Singleton.h"
#include "SDL.h"
#include <Texture.h>
#include <vector>

class Vector2 {
public:
	static const Vector2 ZERO;
	static const Vector2 ONE;
	
	float x;
	float y;

	Vector2() {
		x = 0.0;
		y = 0.0;
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
// meter en cpp
//const Vector2 Vector2::ZERO = Vector2();
//const Vector2 Vector2::ONE = Vector2(1, 1);

class Collider {
public:
	
	Collider() {};
};

class CircleCollider : public Collider{
public:
	float radius;
	CircleCollider(float radius) :Collider() {
		this->radius = radius;
	}
};
class RectCollider : public Collider {
public:
	int width;
	int height;
	RectCollider(int width, int height) :Collider() {
		this->width = width;
		this->height = height;
	}
};

class Transform {
public:
	Vector2 position;
	float rotation;

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
	Collider collider;

	GameObject(string spritePath) {
		isActive = true;

		if (!texture.loadFromFile(spritePath))
		{
			printf("Failed to load gameobject texture!\n");
		}
	}
	void translate(Vector2 offset) {
		transform.position += offset;
	}
	void render() {
		texture.render(transform.position.x, transform.position.y);
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
	void RemoveGameObject(GameObject *go) {
	}
};