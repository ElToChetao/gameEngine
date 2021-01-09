#pragma once

#include "Singleton.h"
#include "SDL.h"

class TimeManager :public Singleton<TimeManager>
{
	friend class Singleton<TimeManager>;

private:
	float deltaTime;
	float timeScale;
	int currentTime;

	TimeManager();
	~TimeManager();
public:
	void Init(void);
	void Update(void);

	float getDeltaTime();
	float getUnscaledDeltaTime();
	int getCurrentTime();

	void setTimeScale(float scale);
};