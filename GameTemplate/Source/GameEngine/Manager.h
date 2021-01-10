#pragma once

#include <string>
#include "GameObject.h"
using namespace std;

class Manager {

public:
	string name;
	string tag;

	Manager();
	Manager(string tag);

	void destroy(GameObject* other);

	void setTag(string tag) { this->tag = tag; }

	virtual void update() {};
};