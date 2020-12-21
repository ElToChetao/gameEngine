#pragma once
#include <string>
using namespace std;
class SaveSystem {
public:
	SaveSystem() {};
	std::string folderPath = "savedData.txt";

	bool KeyExists(std::string key);
	bool SaveExists(std::string key);
	std::string GetValue(std::string key);

	template <typename T>
	T Load(std::string key);

	template <typename T>
	void Save(T data, std::string key);
 };
