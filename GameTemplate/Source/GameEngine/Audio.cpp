#include "Audio.h"

Audio::Audio()
{
	isPlaying = false;
}

Audio::Audio(string audioPath, Mix_Music* sound)
{
	this->audioPath = audioPath;
	this->sound = sound;
	this->isPlaying = false;
}

void Audio::Play()
{
	isPlaying = true;
	Mix_PlayMusic(sound,-1);
}

void Audio::Stop()
{
	isPlaying = false;
}

Audio::~Audio()
{

}