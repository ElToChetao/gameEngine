#pragma once
#include "AudioManager.h"

bool AudioManager::Init() 
{
	if (SDL_Init(SDL_INIT_AUDIO) < 0) {
		printf("SDL could not initialize! SDL Error: %s\n", SDL_GetError());
		return false;
	}
	if (Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048) < 0)
	{
		return false;
	}
	return true;
}

void AudioManager::Update() 
{

}

void AudioManager::PlaySound(string soundPath) 
{
    printf("\nPlaying Sound Stored in : %s", soundPath);

    // check if audio is already loaded
   for (int i = 0; !sounds.empty() && i < sounds.size(); i++) 
   {
       printf("jejeje");
   
       if (sounds[i]->audioPath._Equal(soundPath) && !sounds[i]->isPlaying) {
           // audio already loaded
           sounds[i]->Play();
           soundsPlaying.push_back(sounds[i]);
           printf("sound founded \n");
           return;
       }
   }

    printf("\n adding new audio\n");
    // audio not found

    Mix_Music* sound = Mix_LoadMUS(soundPath.c_str());
    if (sound == NULL)
    {
        printf("\nError loading the file");
    }
    else
    {
        Audio audio(soundPath, sound);
        audio.isPlaying = true;
        audio.Play();
        sounds.push_back(&audio);
        soundsPlaying.push_back(&audio);
        

        printf("audio loaded succesfully");
    }
}

void AudioManager::StopSound(string soundPath) 
{

}

void AudioManager::PauseSound(string soundPath) 
{

}

AudioManager::~AudioManager()
{    
    for (int i = 0; i < sounds.size(); i++)
    {
        Mix_FreeMusic(sounds[i]->sound);
    }

    //Quit SDL subsystems
    Mix_Quit();
}