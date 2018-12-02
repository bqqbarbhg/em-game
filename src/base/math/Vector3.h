#pragma once

#include <math.h>

namespace em {

struct Vector3 {
	union {
		struct { float x, y, z; };
		float v[3];
	};

	Vector3()
	{
	}

	Vector3(float x, float y, float z)
		: x(x), y(y), z(z)
	{
	}
};

inline Vector3 operator+(const Vector3 &a, const Vector3 &b)
{
	return Vector3(a.x + b.x, a.y + b.y, a.z + b.z);
}

inline Vector3 operator-(const Vector3 &a, const Vector3 &b)
{
	return Vector3(a.x - b.x, a.y - b.y, a.z - b.z);
}

inline Vector3 operator*(const Vector3 &a, float b)
{
	return Vector3(a.x * b, a.y * b, a.z * b);
}

inline Vector3 operator*(float b, const Vector3 &a)
{
	return Vector3(a.x * b, a.y * b, a.z * b);
}

inline Vector3 operator/(const Vector3 &a, float b)
{
	return Vector3(a.x / b, a.y / b, a.z / b);
}

inline Vector3 cross(const Vector3 &a, const Vector3 &b)
{
	return Vector3(a.y*b.z - b.y*a.z, a.z*b.x - b.z*a.x, a.x*b.y - b.x*a.y);
}

inline float dot(const Vector3 &a, const Vector3 &b)
{
	return a.x*b.x + a.y*b.y + a.z*b.z;
}

inline float lengthSquared(const Vector3 &a)
{
	return a.x*a.x + a.y*a.y + a.z*a.z;
}

inline float length(const Vector3 &a)
{
	return sqrtf(a.x*a.x + a.y*a.y + a.z*a.z);
}

inline Vector3 normalize(const Vector3 &a)
{
	float rcpLen = 1.0f / length(a);
	return a * rcpLen;
}

inline float distance(const Vector3 &a, const Vector3 &b)
{
	return length(b - a);
}

inline Vector3 lerp(const Vector3 &a, const Vector3 &b, float t)
{
	return a * (1.0f - t) + b * t;
}

}

