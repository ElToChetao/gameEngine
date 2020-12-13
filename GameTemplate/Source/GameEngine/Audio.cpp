#include "Audio.h"

Audio::Audio()
{
	isPlaying = false;
}

Audio::Audio(string audioPath, Mix_Chunk* sound)
{
	this->audioPath = audioPath;
	this->sound = sound;
	this->isPlaying = false;
}

void Audio::Play()
{
	isPlaying = true;
	Mix_PlayChannel(-1, sound, 0);
}

void Audio::Stop()
{
	isPlaying = false;
}

Audio::~Audio()
{

}