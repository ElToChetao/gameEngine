#include "Vector2.h"

Vector2::Vector2()
{
	x = 0.0;
	y = 0.0;
}

Vector2::Vector2(float x, float y) {
	this->x = x;
	this->y = y;
}

Vector2& Vector2:: operator+=(const Vector2& other) {
	this->x += other.x;
	this->y += other.y;
	return *this;
}

Vector2& Vector2:: operator-=(const Vector2& other) {
	this->x -= other.x;
	this->y -= other.y;
	return *this;
}

Vector2& Vector2:: operator*(const int other) {
	this->x *= other;
	this->y *= other;
	return *this;
}