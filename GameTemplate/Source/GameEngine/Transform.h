#pragma once
#include "Vector2.h"

class Transform {
public:
	Vector2 position;
	Vector2 size;
	Vector2 scale;

	float rotation;

	Transform();
};