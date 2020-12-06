#include "Collider.h"

Collider::Collider()
{

}

Collider::Collider(float radius)
{
	this->radius = radius;
	if (radius > 0)
	{
		isRect = true;
	}
	else
	{
		isRect = false;
	}
}