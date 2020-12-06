#include "Vector2.h"

const Vector2 Vector2::ZERO = Vector2();
const Vector2 Vector2::ONE = Vector2(1, 1);
const Vector2 Vector2::RIGHT = Vector2(1, 0);
const Vector2 Vector2::DOWN = Vector2(0, 1);
const Vector2 Vector2::LEFT = Vector2(-1, 0);
const Vector2 Vector2::UP = Vector2(0, -1);

Vector2::Vector2()
{
	x = 0.0;
	y = 0.0;
}

Vector2::Vector2(float x, float y) {
	this->x = x;
	this->y = y;
}

Vector2 Vector2::direction(Vector2 a, Vector2 b) {
	return Vector2(b.x - a.x, b.y - a.y);
}
float Vector2::module(Vector2 a, Vector2 b) {
	return 0;
}
Vector2 Vector2::moduledDirection(Vector2 a, Vector2 b) {
	return Vector2();
}
float Vector2::distance(Vector2 a, Vector2 b) {
	Vector2 dir = direction(b, a);
	return 0;
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