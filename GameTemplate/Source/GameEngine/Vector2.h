#pragma once

class Vector2 {
public:
	static const Vector2 ZERO;
	static const Vector2 ONE;

	float x;
	float y;

	Vector2();
	Vector2(float x, float y);
	Vector2& operator+=(const Vector2& other);
	Vector2& operator-=(const Vector2& other);
	Vector2& operator*(const int other);
};
//const Vector2 Vector2::ZERO = Vector2();
//const Vector2 Vector2::ONE = Vector2(1, 1);
