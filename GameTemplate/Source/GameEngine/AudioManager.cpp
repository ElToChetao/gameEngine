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
    if (soundsQueue.size() > 0 && Mix_PlayingMusic() == 0)
    {
        printf("EEEE");
        soundsQueue[0]->Stop();
        RemoveAudio(soundsQueue[0]);

        if (soundsQueue.size() > 0)
        {
            soundsQueue[0]->Play();
        }
    }
}

void AudioManager::PlaySound(string soundPath) 
{
    Audio* audio = SearchSound(soundPath);
    if (audio == NULL)
    {
        printf("\nAudio added");
        audio = NewAudio(soundPath);
    }
    if (Mix_PlayingMusic() == 0) //No music 
    {
        audio->Play();
    }
    soundsQueue.push_back(audio);
    printf("\nAudio added to array          %i", soundsQueue.size());

    return;
}

void AudioManager::PlayCurrentSound(string soundPath)
{
    Audio* audio = SearchSound(soundPath);
    if (audio == NULL)
    {
        printf("\nAudio added");
        audio = NewAudio(soundPath);
    }
    audio->Play();
    soundsQueue.push_back(audio);
    printf("\nAudio added to array    %i", soundsQueue.size());

    return;
}

void AudioManager::RemoveAudio(Audio* audio)
{
    printf("che");
    soundsQueue.erase(remove(soundsQueue.begin(), soundsQueue.end(), audio), soundsQueue.end());
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

    Mix_Music* sound = Mix_LoadMUS(soundPath.c_str());
    if (sound != NULL)
    {
        Audio* audio = new Audio(soundPath, sound);
        sounds.push_back(audio);
    }
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