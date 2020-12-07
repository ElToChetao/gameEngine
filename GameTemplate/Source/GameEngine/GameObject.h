#pragma once

#include "Transform.h"
#include "SDL.h"
#include "Collider.h"
#include "RenderManager.h"
#include <Texture.h>
#include <string>
using namespace std;

class GameObject {	
public:
	Transform transform;

	bool isActive;
	
	string name;
	string tag;

	LTexture* texture  = NULL;
	Collider* collider = NULL;

	GameObject();

	void translate(Vector2 offset);
	void render();
	void destroy(GameObject* other);

	void addCollider(float radius);
	void addSprite(string spritePath);

	void setActive(bool b) { isActive = b; }
	void setTag(string tag) { this->tag = tag; }

	virtual void update() {};
	virtual void onDestroy() {};
	virtual void onCollision(GameObject *other) {};
};