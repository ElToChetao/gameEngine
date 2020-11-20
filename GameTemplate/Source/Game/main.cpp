/*This source code copyrighted by Lazy Foo' Productions (2004-2015)
and may not be redistributed without written permission.*/

//Using SDL, SDL_image, standard IO, and strings
#include "MainHeader.h"

//The dot that will move around on the screen
class Dot
{
    public:
		//The dimensions of the dot
		static const int DOT_WIDTH = 20;
		static const int DOT_HEIGHT = 20;

		//Maximum axis velocity of the dot
		static const int DOT_VEL = 10;

		//Initializes the variables
		Dot();

		//Takes key presses and adjusts the dot's velocity
		void handleEvent( SDL_Event& e );

		//Moves the dot
		void move();

		//Shows the dot on the screen
		void render();

    private:
		//The X and Y offsets of the dot
		int mPosX, mPosY;

		//The velocity of the dot
		int mVelX, mVelY;
};

//Starts up SDL and creates window
bool init();

//Loads media
bool loadMedia();

//Frees media and shuts down SDL
void close();




//Scene textures
LTexture gDotTexture;


Dot::Dot()
{
    //Initialize the offsets
    mPosX = 0;
    mPosY = 0;

    //Initialize the velocity
    mVelX = 0;
    mVelY = 0;
}

void Dot::handleEvent( SDL_Event& e )
{
    //If a key was pressed
	if( e.type == SDL_KEYDOWN && e.key.repeat == 0 )
    {
        //Adjust the velocity
        switch( e.key.keysym.sym )
        {
            case SDLK_UP: mVelY -= DOT_VEL; break;
            case SDLK_DOWN: mVelY += DOT_VEL; break;
            case SDLK_LEFT: mVelX -= DOT_VEL; break;
            case SDLK_RIGHT: mVelX += DOT_VEL; break;
        }
    }
    //If a key was released
    else if( e.type == SDL_KEYUP && e.key.repeat == 0 )
    {
        //Adjust the velocity
        switch( e.key.keysym.sym )
        {
            case SDLK_UP: mVelY += DOT_VEL; break;
            case SDLK_DOWN: mVelY -= DOT_VEL; break;
            case SDLK_LEFT: mVelX += DOT_VEL; break;
            case SDLK_RIGHT: mVelX -= DOT_VEL; break;
        }
    }
}

void Dot::move()
{
  mVelX = 0;
  mVelY = 0;
  if (InputManager::GetInstance().GetKey(SDL_SCANCODE_UP)) {
    mVelY -= DOT_VEL;
  }
  if (InputManager::GetInstance().GetKey(SDL_SCANCODE_DOWN)) {
    mVelY += DOT_VEL;
  }
  if (InputManager::GetInstance().GetKey(SDL_SCANCODE_LEFT)) {
    mVelX -= DOT_VEL;
  }
  if (InputManager::GetInstance().GetKey(SDL_SCANCODE_RIGHT)) {
    mVelX += DOT_VEL;
  }

  //Move the dot left or right
  mPosX += mVelX;

  //If the dot went too far to the left or right
  if( ( mPosX < 0 ) || ( mPosX + DOT_WIDTH > RenderManager::SCREEN_WIDTH ) )
  {
      //Move back
      mPosX -= mVelX;
  }

  //Move the dot up or down
  mPosY += mVelY;

  //If the dot went too far up or down
  if( ( mPosY < 0 ) || ( mPosY + DOT_HEIGHT > RenderManager::SCREEN_HEIGHT ) )
  {
      //Move back
      mPosY -= mVelY;
  }
}

void Dot::render()
{
    //Show the dot
	gDotTexture.render( mPosX, mPosY );
}

bool loadMedia()
{
	//Loading success flag
	bool success = true;

	//Load dot texture
	if( !gDotTexture.loadFromFile( "../../Media/dot.bmp" ) )
	{
		printf( "Failed to load dot texture!\n" );
		success = false;
	}

	return success;
}

void close()
{
	//Free loaded images
	gDotTexture.free();
}

int main( int argc, char* args[] )
{
  InputManager::CreateSingleton();

  RenderManager::CreateSingleton();

  GameObjectManager::CreateSingleton();


	//Start up SDL and create window
	if( !RenderManager::GetInstance().Init() )
	{
		printf( "Failed to initialize!\n" );
	}
	else
	{
		GameObject go("../../Media/dot.bmp");

		//Load media
		if( !loadMedia() )
		{
			printf( "Failed to load media!\n" );
		}
		else
		{	
			//Main loop flag
			bool quit = false;

			//Event handler
			SDL_Event e;

			//The dot that will be moving around on the screen
			Dot dot;

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

					//Handle input for the dot
					dot.handleEvent( e );
				}

				InputManager::GetInstance().Update();

				//Move the dot
				dot.move();

				//Clear screen
				SDL_SetRenderDrawColor( RenderManager::GetInstance().GetRenderer(), 0xFF, 0xFF, 0xFF, 0xFF );
				SDL_RenderClear(RenderManager::GetInstance().GetRenderer());

				//Render objects
				dot.render();

				//Update screen
				SDL_RenderPresent(RenderManager::GetInstance().GetRenderer());
			}
		}
	}

	//Free resources and close SDL
	close();

	RenderManager::DestroySingleton();

	InputManager::DestroySingleton();

	return 0;
}