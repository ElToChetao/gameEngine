
#include "MainHeader.h"

class ManagerOfManagers :public Singleton<ManagerOfManagers>
{
	friend class Singleton<ManagerOfManagers>;
public:
	ManagerOfManagers() {
		Init();
	}
	void Update(void);
	void Init(void);
	void Destroy(void);
};
void ManagerOfManagers::Update() {
	// update all managers
}
void ManagerOfManagers::Init() {
	// init all managers
}
void ManagerOfManagers::Destroy() {
	// destroy all managers
}
