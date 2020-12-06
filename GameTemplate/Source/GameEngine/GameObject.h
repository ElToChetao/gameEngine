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

	GameObject(string spritePath, float radius);
	void translate(Vector2 offset);
	void render();

	virtual void update() {};

	virtual void destroy() {};
	virtual void onCollision(Collider collider) {};
};