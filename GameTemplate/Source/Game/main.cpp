/*This source code copyrighted by Lazy Foo' Productions (2004-2015)
and may not be redistributed without written permission.*/

//Using SDL, SDL_image, standard IO, and strings
#include "MainHeader.h"

class Go : public GameObject {
private:
	static const int speed = 4;
public:
	Go(string path) :GameObject(path) {};

	void start() override {
		transform.position.x = 100;
		transform.position.y = 200;
		printf("hola");
	}
	void update() override {
		move();
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
	Wall(string path) :GameObject(path) {};
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
		Go go("../../Media/dot.bmp");
		GameObjectManager::GetInstance().AddGameObject(&go);
		go.start();

		Wall wall("../../Media/dot.bmp");
		GameObjectManager::GetInstance().AddGameObject(&wall);

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

	ManagerOfManagers::GetInstance().Destroy();
	return 0;
}