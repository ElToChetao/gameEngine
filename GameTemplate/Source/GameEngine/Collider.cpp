#include "Collider.h"

Collider::Collider()
{
	this->radius = 0;
	isRect = true;
}

Collider::Collider(float radius)
{
	this->radius = radius;
	isRect = false;
}