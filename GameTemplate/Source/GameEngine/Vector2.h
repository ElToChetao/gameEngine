#pragma once

class Vector2 {
public:
	static const Vector2 ZERO;
	static const Vector2 ONE;
	static const Vector2 RIGHT;
	static const Vector2 DOWN;
	static const Vector2 LEFT;
	static const Vector2 UP;

	float x;
	float y;

	Vector2();
	Vector2(float x, float y);

	Vector2 direction(Vector2 a, Vector2 b);
	float module(Vector2 a, Vector2 b);
	Vector2 moduledDirection(Vector2 a, Vector2 b);
	float distance(Vector2 a, Vector2 b);

	Vector2& operator+=(const Vector2& other);
	Vector2& operator-=(const Vector2& other);
	Vector2& operator*(const float other);
};
