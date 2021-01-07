#include "Collider.h"

Collider::Collider()
{
	this->radius = 0;
	isRect = true;
	isOnCollision = false;
}

Collider::Collider(float radius)
{
	this->radius = radius;
	isRect = false;
	isOnCollision = false;
}