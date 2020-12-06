#include "PhysicsManager.h"

PhysicsManager::PhysicsManager(){}

void PhysicsManager::Update() {
	vector<GameObject*> go = GameObjectManager::GetInstance().GetGameObjects();
	for (int i = 0; i < go.size(); i++) {
		for (int j = 0; j < go.size(); j++)
		{
			if (i != j)
			{
				bool collision = CheckCollisions(go[i], go[j]);
				if (collision == true)
				{
					go[i]->onCollision(go[j]->collider);
					go[j]->onCollision(go[i]->collider);
				}
			}
		}
	}
}

bool PhysicsManager::CheckCollisions(GameObject* go, GameObject* other) {

	if (go->collider.isRect == true && other->collider.isRect == true)
	{
		return CheckRectCollisions(go, other);
	}
	else if (go->collider.isRect == false && other->collider.isRect == false)
	{
		return CheckCircleCollisions(go, other);
	}
	else
	{
		//go must always be RectCollider
		if (go->collider.isRect == true)
		{
			return CheckRectCircleCollisions(go, other);
		}
		else
		{
			return CheckRectCircleCollisions(other, go);
		}
	}
}

bool PhysicsManager::CheckCircleCollisions(GameObject* go, GameObject* other)
{
	float dx = (go->transform.position.x + go->collider.radius) - (other->transform.position.x + other->collider.radius);
	float dy = (go->transform.position.y - go->collider.radius) - (other->transform.position.y - other->collider.radius);
	float distance = sqrt((dx * dx) + (dy * dy));

	if (distance < go->collider.radius + other->collider.radius)
	{
		return true;
	}
	return false;
}

bool PhysicsManager::CheckRectCollisions(GameObject* go, GameObject* other)
{
	if (go->transform.position.x < other->transform.position.x + other->transform.size.x &&
		go->transform.position.x + other->transform.size.x > other->transform.size.x &&
		go->transform.position.y < other->transform.position.y + other->transform.size.y &&
		go->transform.size.y + go->transform.position.y > other->transform.position.y) {

		return true;
	}
	return false;
}

//Go always rect
bool PhysicsManager::CheckRectCircleCollisions(GameObject* rect, GameObject* circle)
{
	// temporary variables to set edges for testing
	float testX = 0;
	float testY = 0;

	// which edge is closest?
	if (circle->transform.position.x < rect->transform.position.x)
	{
		testX = rect->transform.position.x;      // left edge
	}
	else if (circle->transform.position.x > rect->transform.position.x + rect->transform.size.x)
	{
		testX = rect->transform.position.x + rect->transform.size.x;   // right edge
	}
	if (circle->transform.position.y < rect->transform.position.y) {
		testY = rect->transform.position.y;      // top edge
	}
	else if (circle->transform.position.y > rect->transform.position.y + rect->transform.size.y)
	{
		testY = rect->transform.position.y + rect->transform.size.y;   // bottom edge
	}

	// get distance from closest edges
	float distX = circle->transform.position.x - testX;
	float distY = circle->transform.position.y - testY;
	float distance = sqrt((distX * distX) + (distY * distY));

	// if the distance is less than the radius, collision!
	if (distance <= circle->collider.radius) {
		return true;
	}
	return false;
}