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
	vector<Audio*> sounds;
	vector<Audio*> soundsPlaying;


	bool Init(void);
	void Update(void);

	void PlaySound(string soundPath);
	void StopSound(string soundPath);
	void PauseSound(string soundPath);
};