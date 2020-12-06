#include "PhysicsManager.h"

PhysicsManager::PhysicsManager(){}

void PhysicsManager::Update() {
	vector<GameObject*> go = GameObjectManager::GetInstance().GetGameObjects();
	for (int i = 0; i < go.size(); i++) {
		if (go[i]->pCollider != NULL) {
			for (int j = i + 1; j < go.size(); j++)
			{
				if (go[j]->pCollider != NULL && CheckCollisions(go[i], go[j]))
				{
					go[i]->onCollision(go[j]);
					go[j]->onCollision(go[i]);
				}
			}
		}
	}
}

bool PhysicsManager::CheckCollisions(GameObject* go, GameObject* other) {

	if (go->collider.isRect && other->collider.isRect)
	{
		return CheckRectCollisions(go, other);
	}
	else if (!go->collider.isRect && !other->collider.isRect)
	{
		return CheckCircleCollisions(go, other);
	}
	else
	{
		//go must always be RectCollider
		return go->collider.isRect ? CheckRectCircleCollisions(go, other) : CheckRectCircleCollisions(other, go);
	}
}

bool PhysicsManager::CheckCircleCollisions(GameObject* go, GameObject* other)
{
	float dx = (go->transform.position.x + go->collider.radius) - (other->transform.position.x + other->collider.radius);
	float dy = (go->transform.position.y - go->collider.radius) - (other->transform.position.y - other->collider.radius);
	float distance = sqrt((dx * dx) + (dy * dy));

	return distance < go->collider.radius + other->collider.radius;
}

bool PhysicsManager::CheckRectCollisions(GameObject* go, GameObject* other)
{
	return go->transform.position.x < other->transform.position.x + other->transform.size.x &&
		go->transform.position.x + other->transform.size.x > other->transform.size.x &&
		go->transform.position.y < other->transform.position.y + other->transform.size.y &&
		go->transform.size.y + go->transform.position.y > other->transform.position.y;
}

//Go always rect
bool PhysicsManager::CheckRectCircleCollisions(GameObject* rect, GameObject* circle)
{
	// temporary variables to set edges for testing
	float testX = 0;
	float testY = 0;

	// which edge is closest?
	if (circle->transform.position.x + circle->collider.radius < rect->transform.position.x)
	{
		testX = rect->transform.position.x;      // left edge
	}
	else if (circle->transform.position.x + circle->collider.radius > rect->transform.position.x + rect->transform.size.x)
	{
		testX = rect->transform.position.x + rect->transform.size.x;   // right edge
	}
	if (circle->transform.position.y - circle->collider.radius < rect->transform.position.y) {
		testY = rect->transform.position.y;      // top edge
	}
	else if (circle->transform.position.y - circle->collider.radius > rect->transform.position.y + rect->transform.size.y)
	{
		testY = rect->transform.position.y + rect->transform.size.y;   // bottom edge
	}

	// get distance from closest edges
	float distX = circle->transform.position.x + circle->collider.radius - testX;
	float distY = circle->transform.position.y - circle->collider.radius - testY;
	float distance = sqrt((distX * distX) + (distY * distY));

	// if the distance is less than the radius, collision!
	return distance <= circle->collider.radius;
}