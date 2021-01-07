#pragma once

class Collider {
public:
	float radius;
	bool isRect;
	bool isOnCollision;

	Collider();
	Collider(float radius);
};