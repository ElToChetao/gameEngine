#pragma once
#include "ManagerOfManagers.h"
#include "SaveSystem.h"
#include <algorithm>
		

class Wall : public GameObject {
public:
	Wall(Vector2 startPos, Vector2 size) :GameObject() {
		transform.position.x = startPos.x;
		transform.position.y = startPos.y;
		transform.size.x = size.x;
		transform.size.y = size.y;

		addCollider();
	};
};
class Paddle : public GameObject {
private:
	float speed = 200;
public:
	string axis;
	Paddle(Vector2 startPosition, string spritePath, string axis) {
		addSprite(spritePath);
		setTag("paddle");

		transform.position.x = startPosition.x;
		transform.position.y = startPosition.y;

		transform.size.x = 32;
		transform.size.y = 32;

		addCollider();
		this->axis = axis;
	}
	void update() override {
		translate(Vector2(0, 1) * InputManager::GetInstance().GetAxis(axis) * speed);
		transform.position.y = transform.position.y < 30 ? 30 : (transform.position.y > RenderManager::GetInstance().SCREEN_HEIGHT - 60) ?
			RenderManager::GetInstance().SCREEN_HEIGHT - 60 : transform.position.y;
	}
};

class Ball : public GameObject {

private:
	Vector2 direction = Vector2::ONE;
public:

	Ball(Vector2 startPos) :GameObject() {
		addSprite("../../Media/Sprites/ball.png");
		addCollider(10);

		transform.position.x = startPos.x;
		transform.position.y = startPos.y;
	}

	void update() override{
		translate(direction * 120);

		if (transform.position.x < 0 || transform.position.x > RenderManager::GetInstance().SCREEN_WIDTH - transform.size.x)
		{
			//direction.x *= -1;
			//AudioManager::GetInstance().PlaySound("../../Media/Sounds/1.wav", 20);
			//ManagerOfManagers::GetInstance().Exit();
			destroy(this);
		}
		if (transform.position.y < 0 || transform.position.y > RenderManager::GetInstance().SCREEN_HEIGHT - transform.size.y){
			direction.y *= -1;
			AudioManager::GetInstance().PlaySound("../../Media/Sounds/1.wav", 20);
		}

		GameObject* go = PhysicsManager::GetInstance().CheckSphere(getCenterPosition(), collider->radius, this);
		if (go != NULL) {
			if (go->tag == "paddle") {
				direction.x *= -1;
			}
			AudioManager::GetInstance().PlaySound("../../Media/Sounds/1.wav", 20);
		}
	}
};

int main( int argc, char* args[] )
{
	ManagerOfManagers::CreateSingleton();

	//Start up SDL and create window
	if(!ManagerOfManagers::GetInstance().Init())
	{
		printf( "Failed to initialize!\n" );
	}
	else
	{
		// GameObject instances
		Ball ball(Vector2(200, 200));

		Paddle leftPaddle(Vector2(30, RenderManager::GetInstance().SCREEN_HEIGHT / 2), "../../Media/Sprites/paddleLeft.png", "Vertical");
		Paddle rightPaddle(Vector2(RenderManager::GetInstance().SCREEN_WIDTH - 60, RenderManager::GetInstance().SCREEN_HEIGHT / 2), "../../Media/Sprites/paddleRight.png", "Vertical Arrows");

		//While application is running
		while( ManagerOfManagers::GetInstance().gameRunning )
		{
			// update all managers and scripts
			ManagerOfManagers::GetInstance().Update();
		}
	}

	// Free memory and close program
	ManagerOfManagers::GetInstance().Destroy();
}