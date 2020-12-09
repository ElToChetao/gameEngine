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
	Mix_Music* gMusic = NULL;
	vector<Audio> sounds;
	vector<Audio> playingSounds;

	AudioManager();
	~AudioManager();
public:
	bool Init(void);
	void Update(void);

	void PlaySound(string soundPath);
	void StopSound(string soundPath);
	void PauseSound(string soundPath);
};