#include "RenderManager.h"
#include "GameObjectManager.h"

/*****************************************************************************/

RenderManager::RenderManager(void)
{
}

/*****************************************************************************/

RenderManager::~RenderManager(void)
{
  //Destroy window	
  SDL_DestroyRenderer(mRenderer);
  SDL_DestroyWindow(mWindow);
  mWindow = NULL;
  mRenderer = NULL;

  //Quit SDL subsystems
  IMG_Quit();
  SDL_Quit();
}

/*****************************************************************************/

bool RenderManager::Init()
{
  //Initialization flag
  bool success = true;

  //Initialize SDL
  if (SDL_Init(SDL_INIT_VIDEO) < 0)
  {
    printf("SDL could not initialize! SDL Error: %s\n", SDL_GetError());
    success = false;
  }
  else
  {
    //Set texture filtering to linear
    if (!SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "1"))
    {
      printf("Warning: Linear texture filtering not enabled!");
    }

    //Create window
    mWindow = SDL_CreateWindow("SDL Tutorial", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
    if (mWindow == NULL)
    {
      printf("Window could not be created! SDL Error: %s\n", SDL_GetError());
      success = false;
    }
    else
    {
      //Create vsynced renderer for window
      mRenderer = SDL_CreateRenderer(mWindow, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
      if (mRenderer == NULL)
      {
        printf("Renderer could not be created! SDL Error: %s\n", SDL_GetError());
        success = false;
      }
      else
      {
        //Initialize renderer color
        SDL_SetRenderDrawColor(mRenderer, 0xFF, 0xFF, 0xFF, 0xFF);

        //Initialize PNG loading
        int imgFlags = IMG_INIT_PNG;
        if (!(IMG_Init(imgFlags) & imgFlags))
        {
          const char *error = IMG_GetError();
          printf("SDL_image could not initialize! SDL_image Error: %s\n", error);
          success = false;
        }
      }
    }
  }
    
  //Load all images

  return success;
}

/*****************************************************************************/

void RenderManager::Update()
{
    // clear screen
    SDL_RenderClear(GetRenderer());

    //get al rendereable objets form gameobjectmanager
    vector<GameObject*> go = GameObjectManager::GetInstance().GetGameObjects();
    for (int i = 0; i < go.size(); i++) {
        if (go[i]->texture != NULL) {
            go[i]->texture->render(go[i]->transform.position.x, go[i]->transform.position.y);
        }
    }

    //render screen
    SDL_RenderPresent(GetRenderer());
}
LTexture* RenderManager::GetSprite(string spritePath)
{
    // check if sprite is already loaded
    for (int i = 0; i < sprites.size(); i++) {
        if (sprites[i]->spritePath._Equal(spritePath)) {
            // sprite already loaded
            return sprites[i];
        }
    }

    printf("adding new sprite\n");
    // sprite not found
    LTexture *tempSprite = new LTexture();
    if (!tempSprite->loadFromFile(spritePath)) {
        printf("Path not found");
    }
    else 
    {
        int index = sprites.size();
        sprites.push_back(tempSprite);
        printf("Sprite loaded succesfully");
        return sprites[index];
    }
}

/*****************************************************************************/

/*****************************************************************************/
