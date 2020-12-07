#include "GameObject.h"
#include "GameObjectManager.h"

GameObject::GameObject() {
	isActive = true;
	GameObjectManager::GetInstance().AddGameObject(this);
}

void GameObject::addCollider(float radius = 0) {
	collider = new Collider(radius);
}
void GameObject::addSprite(string spritePath) {
	texture = new LTexture();
	if (!texture->loadFromFile(spritePath))
	{
		printf("Failed to load gameobject texture!\n");
	}
}

void GameObject::translate(Vector2 offset) {
	transform.position += offset;
}

void GameObject::render() {
	texture->render(transform.position.x, transform.position.y);
}
void GameObject::destroy(GameObject *other) {
	GameObjectManager::GetInstance().RemoveGameObject(other);
}
