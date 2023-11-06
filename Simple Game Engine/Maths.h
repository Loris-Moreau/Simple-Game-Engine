#pragma once
#include <limits>
#include <cmath>

namespace Maths
{
	//Value of pi : 3,14 15 92 65 35 89 79 32 38 46 26 43 38 32 79 50 28 84 19 71 69 39 93 75 10 5 82
	const float pi = 3.14159265358979323846264338327950288419716939937510582f;
	const float twoPi = pi * 2.0f;
	const float piOverTwo = pi / 2.0f;
	float infinity = std::numeric_limits<float>::infinity();
	float negInfinity = -std::numeric_limits<float>::infinity();

	inline float toRadians(float degrees)
	{
		return degrees * pi / 180.0f;
	}
	inline float toDegrees(float radians)
	{
		return radians * 180.0f / pi;
	}
	inline bool nearZero(float val, float epsilon = 0.001f)
	{
		if (fabs(val) <= epsilon)
		{
			return true;
		}
		else 
		{
			return false;
		}
	}

	template <typename T>
	T max(const T& a, const T& b)
	{
		return (a < b ? b : a);
	}
	template <typename T>
	T min(const T& a, const T& b)
	{
		return (a < b ? a : b);
	}

	template <typename T>
	T clamp(const T& value, const T& lower, const T& upper)
	{
		return min(upper, max(lower, value));
	}

	inline float abs(float value)
	{
		return fabs(value);
	}
	inline float cos(float angle)
	{
		return cosf(angle);
	}
	inline float sin(float angle)
	{
		return sinf(angle);
	}
	inline float tan(float angle)
	{
		return tanf(angle);
	}
	inline float accos(float value)
	{
		return acosf(value);
	}
	inline float atan2(float y, float x)
	{
		return atan2f(y, x);
	}
	inline float cot(float angle)
	{
		return 1.0f / tan(angle);
	}
	inline float lerp(float a, float b, float f)
	{
		return a + f * (b - a);
	}
	inline float sqrt(float value)
	{
		return sqrtf(value);
	}
	inline float fmod(float number, float denom)
	{
		return std::fmod(number, denom);
	}
	inline int round(float num)
	{
		return static_cast<int>(std::round(num));
	}
}