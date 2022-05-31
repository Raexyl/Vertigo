#include "Vec2.h"

#include <cmath>

namespace Impact 
{
	Vec2::Vec2(void)
	{
	}

	Vec2::Vec2(float X, float Y)
	{
		x = X;
		y = Y;
	}

	Vec2::~Vec2(void)
	{
	}

	Vec2 Vec2::operator+(Vec2 v)
	{
		return Vec2(x + v.x, y + v.y);
	}

	Vec2 Vec2::operator-(Vec2 v)
	{
		return Vec2(x - v.x, y - v.y);
	}

	Vec2 Vec2::operator*(float s)
	{
		return Vec2(x * s, y * s);
	}

	Vec2 Vec2::operator/(float s)
	{
		return Vec2(x / s, y / s);
	}

	void Vec2::operator+=(Vec2 v)
	{
		x += v.x;
		y += v.y;
	}

	void Vec2::operator-=(Vec2 v)
	{
		x -= v.x;
		y -= v.y;
	}

	void Vec2::operator*=(float s)
	{
		x *= s;
		y *= s;
	}

	void Vec2::operator/=(float s)
	{
		x /= s;
		y /= s;
	}

	float Vec2::SizeSquared(void)
	{
		return (x*x) + (y*y);
	}

	float Vec2::Size(void)
	{
		return sqrt(SizeSquared());
	}

	void Vec2::Normalize(void)
	{
		float size = Size();
		x /= size;
		y /= size;
	}

	Vec2 Vec2::Normalized(void)
	{
		float size = Size();
		return Vec2(x / size, y / size);
	}
}