#pragma once
#include "definitions.h"

class Vector2
{
public:
	Vector2() : x(0), y(0) {}
	Vector2(const float x, const float y) : x(x), y(y) {}
		
	float x;
	float y;
		
	inline void Clear(){x = 0; y = 0;}
	inline void Invert(){x = -x;y= -y;}
	inline float Magnitude() const;
	inline float SquareMagnitude() const;
	void Normalize();
	void AddScaledVector(const Vector2& vector, float scale);
	Vector2 ComponentProduct(const Vector2 &vector) const;
	void UpdateComponentProduct(const Vector2 &vector);

	Vector2 PerpendicularVector() const;

	float ScalarProduct(const Vector2 &vector) const;
	float operator*(const Vector2 &vector) const;

	void operator*=(const float scalar);
	Vector2 operator*(const float scalar) const;
		
	void operator+=(const Vector2 &other);
	Vector2 operator+(const Vector2 &other);

	void operator-=(const Vector2 &other);
	Vector2 operator-(const Vector2 &other);
private:
};