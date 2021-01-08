#include "PhysicsManager.h"

PhysicsManager::PhysicsManager(){}

void PhysicsManager::Update() {
	vector<GameObject*> go = GameObjectManager::GetInstance().GetGameObjects();

	for (int i = 0; i < go.size(); i++) {
		if (go[i]->collider != NULL)
		{
			for (int j = i + 1; j < go.size(); j++)
			{
				if (go[j]->collider != NULL)
				{
					bool isColliding = CheckCollisions(go[i], go[j]);

					UpdateState(go[i], isColliding, go[j]);
					UpdateState(go[j], isColliding, go[i]);
				}
			}
		}
	}
}

void PhysicsManager::UpdateState(GameObject* go, bool collision, GameObject* go2)
{
	if (!go->collider->isOnCollision && collision)
	{
		go->onCollisionEnter(go2);
	}
	else if (go->collider->isOnCollision && collision)
	{
		go->onCollisionStay(go2);
	}
	else if (go->collider->isOnCollision && !collision)
	{
		go->onCollisionExit(go2);
	}

	go->collider->isOnCollision = collision;
}

bool PhysicsManager::CheckCollisions(GameObject* go, GameObject* other) {

	if (go->collider->isRect && other->collider->isRect)
	{
		return CheckRectCollisions(go, other);
	}
	else if (!go->collider->isRect && !other->collider->isRect)
	{
		return CheckCircleCollisions(go, other);
	}
	else
	{
		//go must always be RectCollider
		if (go->collider->isRect)
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
	Vector2 centerCircle1 = go->getCenterPosition();
	Vector2 centerCircle2 = other->getCenterPosition();

	//Calculate total radius squared
	int totalRadiusSquared = go->collider->radius + other->collider->radius;
	totalRadiusSquared = totalRadiusSquared * totalRadiusSquared;

	//If the distance between the centers of the circles is less than the sum of their radii
	return (distanceSquared(centerCircle1.x, centerCircle1.y, centerCircle2.x, centerCircle2.y) < (totalRadiusSquared));
}

bool PhysicsManager::CheckCircleCollisions(Vector2 position, float radius, GameObject* other)
{
	Vector2 centerCircle2 = other->getCenterPosition();

	//Calculate total radius squared
	int totalRadiusSquared = radius + other->collider->radius;
	totalRadiusSquared = totalRadiusSquared * totalRadiusSquared;

	//If the distance between the centers of the circles is less than the sum of their radii
	return (distanceSquared(position.x, position.y, centerCircle2.x, centerCircle2.y) < (totalRadiusSquared));
}

double PhysicsManager::distanceSquared(int x1, int y1, int x2, int y2)
{
	int deltaX = x2 - x1;
	int deltaY = y2 - y1;
	return deltaX * deltaX + deltaY * deltaY;
}

bool PhysicsManager::CheckRectCollisions(GameObject* go, GameObject* other)
{
	return (go->transform.position.x < other->transform.position.x + other->transform.size.x &&
		    go->transform.position.x + other->transform.size.x > other->transform.size.x &&
		    go->transform.position.y < other->transform.position.y + other->transform.size.y &&
		    go->transform.size.y + go->transform.position.y > other->transform.position.y);
}

bool PhysicsManager::CheckRectCircleCollisions(GameObject* rect, GameObject* circle)
{
	Vector2 centerCircle = circle->getCenterPosition();
	// temporary variables to set edges for testing
	int testX = 0;
	int testY = 0;

	// which edge is closest?
	if (centerCircle.x < rect->transform.position.x)
	{
		testX = rect->transform.position.x;      // left edge
	}
	else if (centerCircle.x > rect->transform.position.x + rect->transform.size.x)
	{
		testX = rect->transform.position.x + rect->transform.size.x;   // right edge
	}
	else
	{
		testX = centerCircle.x;
	}

	if (centerCircle.y < rect->transform.position.y) {
		testY = rect->transform.position.y;      // top edge
	}
	else if (centerCircle.y > rect->transform.position.y + rect->transform.size.y)
	{
		testY = rect->transform.position.y + rect->transform.size.y;   // bottom edge
	}
	else
	{
		testY = centerCircle.y;
	}

	// if the distance is less than the radius, collision!
	return distanceSquared(centerCircle.x, centerCircle.y, testX, testY) < (circle->collider->radius * circle->collider->radius);
}

bool PhysicsManager::CheckRectCircleCollisions(GameObject* rect, Vector2 centerCircle, float radius)
{
	// temporary variables to set edges for testing
	int testX = 0;
	int testY = 0;

	// which edge is closest?
	if (centerCircle.x < rect->transform.position.x)
	{
		testX = rect->transform.position.x;      // left edge
	}
	else if (centerCircle.x > rect->transform.position.x + rect->transform.size.x)
	{
		testX = rect->transform.position.x + rect->transform.size.x;   // right edge
	}
	else
	{
		testX = centerCircle.x;
	}

	if (centerCircle.y < rect->transform.position.y) {
		testY = rect->transform.position.y;      // top edge
	}
	else if (centerCircle.y > rect->transform.position.y + rect->transform.size.y)
	{
		testY = rect->transform.position.y + rect->transform.size.y;   // bottom edge
	}
	else
	{
		testY = centerCircle.y;
	}

	// if the distance is less than the radius, collision!
	return distanceSquared(centerCircle.x, centerCircle.y, testX, testY) < (radius * radius);
}

GameObject* PhysicsManager::CheckSphere(Vector2 position, float radius, GameObject* self = NULL)
{
	vector<GameObject*> go = GameObjectManager::GetInstance().GetGameObjects();
	
	for (int i = 0; i < go.size(); i++) {
		if (go[i] != self && go[i]->collider != NULL)
		{
			if (go[i]->collider->isRect)
			{
				if (CheckRectCircleCollisions(go[i], position, radius))
				{
					return go[i];
				} 
			}
			else
			{
				if (CheckCircleCollisions(position, radius, go[i]))
				{
					return go[i];
				}
			}
		}
	}
	return NULL;
}