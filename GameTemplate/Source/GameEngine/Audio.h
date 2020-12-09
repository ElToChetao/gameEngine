#pragma once
#include "SDL.h"
#include <SDL_mixer.h>
#include <string>

using namespace std;

class Audio 
{
	public:
		string audioPath;
		Mix_Chunk* sound;
		bool isPlaying;

		Audio();
		Audio(string audioPath, Mix_Chunk* sound );
		~Audio();

		void Play();
		void Stop();
};