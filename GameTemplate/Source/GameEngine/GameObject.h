#pragma once

#include "Transform.h"
#include "SDL.h"
#include "Collider.h"
#include <Texture.h>
#include <string>
using namespace std;

class GameObject {
public:
	Transform transform;
	bool isActive;
	LTexture texture;
	string name;
	Collider collider;
	Collider* pCollider = &collider;

	GameObject(string spritePath, float radius);

	void translate(Vector2 offset);
	void render();
	void destroy(GameObject *other);

	virtual void update() {};
	virtual void onDestroy() {};
	virtual void onCollision(GameObject *other) {};
};