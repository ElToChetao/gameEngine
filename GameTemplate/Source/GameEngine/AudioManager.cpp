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
    // check if sprite is already loaded
    for (int i = 0; i < sounds.size(); i++) {
        if (sounds[i].audioPath._Equal(soundPath) && !sounds[i].isPlaying) {
            // sprite already loaded
            sounds[i].Play();
            playingSounds.push_back(sounds[i]);
            printf("sound founded \n");
            return;
        }
    }

    printf("adding new audio\n");
    // sprite not found
    Mix_Chunk* sound = Mix_LoadWAV(soundPath.c_str());
    if (sound != NULL)
    {
        Audio audio(soundPath, sound);
        sounds.push_back(audio);
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
        Mix_FreeChunk(sounds[i].sound);
    }

    //Free the music
    Mix_FreeMusic(gMusic);
    gMusic = NULL;

    //Quit SDL subsystems
    Mix_Quit();
}