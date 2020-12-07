/*This source code copyrighted by Lazy Foo' Productions (2004-2015)
and may not be redistributed without written permission.*/

//Using SDL, SDL_image, standard IO, and strings
#include "MainHeader.h"

class Go : public GameObject {
private:
	static const int speed = 4;
public:
	Go(Vector2 startPos) :GameObject() {
		addSprite("../../Media/Sprites/dot.bmp");
		addCollider(10);

		transform.position.x = startPos.x;
		transform.position.y = startPos.y;
	};

	void update() override{
		move();
	}
	void onCollision(GameObject *other) override {
		destroy(other);
	}

	void move()
	{
		float hInput = InputManager::GetInstance().GetAxis("Horizontal");
		float vInput = InputManager::GetInstance().GetAxis("Vertical");
		
		Vector2 vec(hInput, vInput);
		translate(vec * speed);
	}
};
class Wall : public GameObject {
public:
	Wall(Vector2 startPos) :GameObject() {
		addSprite("../../Media/Sprites/dot.bmp");
		addCollider(10);

		transform.position.x = startPos.x;
		transform.position.y = startPos.y;
	};
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
		Go go(Vector2(200, 300));
		Wall wall(Vector2(100, 100));
		Wall wall2(Vector2(200, 100));
		Wall wall3(Vector2(100, 200));
		Wall wall4(Vector2(100, 300));

		bool quit = false;

		//Event handler
		SDL_Event e;

		// float lastDt = SDL_GetTicks();
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
			/*float dt = SDL_GetTicks() - lastDt;
			lastDt = SDL_GetTicks();*/

			// update all managers and scripts
			ManagerOfManagers::GetInstance().Update();
		}
	}
	// free memory and close program
	ManagerOfManagers::GetInstance().Destroy();
	return 0;
}