#include "Audio.h"

Audio::Audio()
{

}

Audio::Audio(string audioPath, Mix_Music* sound)
{
	this->audioPath = audioPath;
	this->sound = sound;
}

Audio::~Audio()
{

}

void Audio::Play()
{
	isPlaying = true;
	Mix_PlayMusic(sound, -1);
}

void Audio::Stop()
{

}