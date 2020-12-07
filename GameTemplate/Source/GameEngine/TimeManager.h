#pragma once

#include "Singleton.h"
#include "SDL.h"

class TimeManager :public Singleton<TimeManager>
{
	friend class Singleton<TimeManager>;

private:
	int lastTime;

	TimeManager();
	~TimeManager();
public:
	int deltaTime;
	int currentTime;

	void Init(void);
	void Update(void);
};