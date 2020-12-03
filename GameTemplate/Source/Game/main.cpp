/*This source code copyrighted by Lazy Foo' Productions (2004-2015)
and may not be redistributed without written permission.*/

//Using SDL, SDL_image, standard IO, and strings
#include "MainHeader.h"

//The dot that will move around on the screen

class Go : public GameObject {
public:
	static const int DOT_WIDTH = 20;
	static const int DOT_HEIGHT = 20;

	//Maximum axis velocity of the dot
	static const int DOT_VEL = 10;
	Go(string path):GameObject(path) {
	}

	void update() override{
		move();
	}
	void render() {
		SDL_SetRenderDrawColor(RenderManager::GetInstance().GetRenderer(), 0xFF, 0xFF, 0xFF, 0xFF);
		GameObject::render();
	}
	void move()
	{
		float hInput = InputManager::GetInstance().GetAxis("Horizontal");
		float vInput = InputManager::GetInstance().GetAxis("Vertical");

		Vector2 vec(hInput, vInput);
		translate(vec);
	}
};

int main( int argc, char* args[] )
{
	ManagerOfManagers::CreateSingleton();

	//Start up SDL and create window
	if( !ManagerOfManagers::GetInstance().Init())
	{
		printf( "Failed to initialize!\n" );
	}
	else
	{
		Go go("../../Media/dot.bmp");
		GameObjectManager::GetInstance().AddGameObject(&go);

		//Load media
		/*if( !loadMedia() )
		{
			printf( "Failed to load media!\n" );
		}
		else
		{	*/
			//Main loop flag
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
				//Move the dot
				//dot.move();

				//Clear screen
				ManagerOfManagers::GetInstance().Update();

				//Render objects
				//dot.render();

				//Update screen
				SDL_RenderPresent(RenderManager::GetInstance().GetRenderer());
			}
		//}
	}

	ManagerOfManagers::GetInstance().Destroy();
	return 0;
}