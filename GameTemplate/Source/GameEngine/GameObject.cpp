#include "GameObject.h"
#include "GameObjectManager.h"

GameObject::GameObject(string spritePath, float radius) {
	isActive = true;
	collider.radius = radius;
	if (!texture.loadFromFile(spritePath))
	{
		printf("Failed to load gameobject texture!\n");
	}
	GameObjectManager::GetInstance().AddGameObject(this);
}

void GameObject::translate(Vector2 offset) {
	transform.position += offset;
}

void GameObject::render() {
	texture.render(transform.position.x, transform.position.y);
}
void GameObject::destroy(GameObject *other) {
	GameObjectManager::GetInstance().RemoveGameObject(other);
}
