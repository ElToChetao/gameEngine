#pragma once

#include "Singleton.h"
#include "SDL.h"
#include <vector>
#include <SDL_mixer.h>

class AudioManager :public Singleton<AudioManager>
{
	friend class Singleton<AudioManager>;

private:
	//vector<SDL_audio_h_>
	AudioManager();
	~AudioManager();
public:
	bool Init(void);
	void Update(void);

	void PlaySound(string soundPath);
	void StopSound(string soundPath);
	void PauseSound(string soundPath);
};