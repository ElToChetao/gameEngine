#pragma once
#include "AudioManager.h"
AudioManager::AudioManager()
{

}

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

void AudioManager::PlaySound(string soundPath, float volume)
{
    Audio* audio = SearchSound(soundPath);
    if (audio == NULL)
    {
        audio = NewAudio(soundPath);
    }
    audio->sound->volume = volume;
    audio->Play();
}


Audio* AudioManager::SearchSound(string soundPath)
{
    for (int i = 0; i < sounds.size(); i++)
    {
        if (sounds[i]->audioPath._Equal(soundPath))
        {
            return sounds[i];
        }
    }
    return NULL;
}

Audio* AudioManager::NewAudio(string soundPath)
{
    printf("\nAdding new audio\n");

    Mix_Chunk* sound = Mix_LoadWAV(soundPath.c_str());
    if (sound != NULL)
    {
        Audio* audio = new Audio(soundPath, sound);
        sounds.push_back(audio);
        return audio;
    }
    return NULL;
}

void AudioManager::SetBackgroundMusic(string soundPath)
{
    backgroundMusic = Mix_LoadMUS(soundPath.c_str());
    Mix_PlayMusic(backgroundMusic, -1);
}

void AudioManager::StopMusic()
{
    Mix_HaltMusic();
}

AudioManager::~AudioManager()
{    
    for (int i = 0; i < sounds.size(); i++)
    {
        Mix_FreeChunk(sounds[i]->sound);
    }
    Mix_FreeMusic(backgroundMusic);

    //Quit SDL subsystems
    Mix_Quit();
}