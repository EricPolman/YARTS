#include "StdAfx.h"
#include "Vector2.h"

/*
 *	Vector functions
 */

void Vector2::Normalize()
{
	float L = Magnitude();
	if(L > 0)
	{
		(*this) *= ((float)1) / L;
	}
}


void Vector2::AddScaledVector(const Vector2& vector, float scale)
{
	x += vector.x * scale;
	y += vector.y * scale;
}


float Vector2::Magnitude() const
{
	 return sqrtf(x*x + y*y);
}


float Vector2::SquareMagnitude() const
{
	 return x*x + y*y;
}


Vector2 Vector2::PerpendicularVector() const
{
	return Vector2(-y, x);
}


Vector2 Vector2::ComponentProduct(const Vector2 &vector) const
{
	return Vector2(x * vector.x, y * vector.y);
}


void Vector2::UpdateComponentProduct(const Vector2 &vector)
{
	x *= vector.x;
	y *= vector.y;
}


float Vector2::ScalarProduct(const Vector2 &vector) const
{
	return x * vector.x + y * vector.y;
}


/*
 *	Operator overloading
 */

float Vector2::operator*(const Vector2 &vector) const
{
	return x * vector.x + y * vector.y;
}


void Vector2::operator*=(const float scalar)
{
	x *= scalar;
	y *= scalar;
}
Vector2 Vector2::operator*(const float scalar) const
{
	return Vector2(x * scalar, y * scalar);
}


void Vector2::operator+=(const Vector2 &other)
{
	x += other.x;
	y += other.y;
}
Vector2 Vector2::operator+(const Vector2 &other)
{
	return Vector2(x + other.x, y + other.y);
}


void Vector2::operator-=(const Vector2 &other)
{
	x -= other.x;
	y -= other.y;
}
Vector2 Vector2::operator-(const Vector2 &other)
{
	return Vector2(x - other.x, y - other.y);
}