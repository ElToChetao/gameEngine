#pragma once

#include "Singleton.h"
#include "Audio.h"
#include "SDL.h"
#include <vector>
#include <SDL_mixer.h>
#include <stdio.h>

class AudioManager :public Singleton<AudioManager>
{
	friend class Singleton<AudioManager>;

private:
	AudioManager();
	~AudioManager();
public:
	Mix_Music* backgroundMusic;
	vector<Audio*> sounds;
	
	bool Init(void);
	void Update(void);

	Audio* SearchSound(string soundPath);
	Audio* NewAudio(string soundPath);

	void PlaySound(string soundPath);
};