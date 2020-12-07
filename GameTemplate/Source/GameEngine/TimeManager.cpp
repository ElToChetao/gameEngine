#pragma once
#include "TimeManager.h"


TimeManager::TimeManager()
{

}

TimeManager::~TimeManager()
{

}

void TimeManager::Init() {
	deltaTime = 0;
	currentTime = 0;
}

void TimeManager::Update() {

	deltaTime = SDL_GetTicks() - currentTime;
	currentTime = SDL_GetTicks();
}

float TimeManager::getDeltaTime()
{
	return (deltaTime/1000);
}