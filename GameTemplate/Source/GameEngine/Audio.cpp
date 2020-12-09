#include "Audio.h"

Audio::Audio()
{

}

Audio::Audio(string audioPath, Mix_Chunk* sound)
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
}

void Audio::Stop()
{

}