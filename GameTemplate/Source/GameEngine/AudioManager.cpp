#pragma once
#include "AudioManager.h"

bool AudioManager::Init() {
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
void AudioManager::Update() {

}

void AudioManager::PlaySound(string soundPath) {

}
void AudioManager::StopSound(string soundPath) {

}
void AudioManager::PauseSound(string soundPath) {

}