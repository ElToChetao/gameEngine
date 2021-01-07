#pragma once
#include "ManagerOfManagers.h"
#include "SaveSystem.h"

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
		translate(direction * 150);
	}

	void onCollisionEnter(GameObject* other) override {

		if (other->tag == "vertical" || other->tag == "paddle") {
			direction.x *= -1;
		}
		else if (other->tag == "horizontal") {
			direction.y *= -1;
		}
		AudioManager::GetInstance().PlaySound("../../Media/Sounds/1.wav");
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
		// gameObject instances
		Ball ball(Vector2(200, 200));
		Wall wall(Vector2(10, 20), Vector2(30, 400));
		Wall wall1(Vector2(10, 20), Vector2(400, 30));
		Wall wall2(Vector2(400, 20), Vector2(30, 400));
		Wall wall3(Vector2(10, 300), Vector2(400, 30));

		wall.setTag("vertical");
		wall1.setTag("horizontal");
		wall2.setTag("vertical");
		wall3.setTag("horizontal");

		Paddle leftPaddle(Vector2(30, 200), "../../Media/Sprites/paddleLeft.png", "Vertical");
		Paddle rightPaddle(Vector2(350, 200), "../../Media/Sprites/paddleRight.png", "Vertical Arrows");

		bool quit = false;

		//Event handler
		SDL_Event e;

		//While application is running
		while( !quit )
		{
			//Handle events on queue
			while( SDL_PollEvent( &e ) != 0 )
			{
				//User requests quit
				if( e.type == SDL_QUIT )
				{
					quit = true;
				}
			}

			// update all managers and scripts
			ManagerOfManagers::GetInstance().Update();
		}
	}
	// free memory and close program
	ManagerOfManagers::GetInstance().Destroy();
	return 0;
}