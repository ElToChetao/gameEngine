#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include <thread>
#include <sstream>
using namespace std;

string folderPath = "savedData.txt";

bool KeyExists(string key);
bool SaveExists(string key);
string GetValue(string key);

template <typename T>
T Load(string key);

template <typename T>
void Save(T data, string key);