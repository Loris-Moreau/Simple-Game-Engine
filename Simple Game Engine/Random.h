#pragma once

#include<random>

#include"Vector2.h"

class Random
{
public:
	static void init();

	//Seed the generator with the specified int
	//Note : you shouldn't need to manually use this 
	static void seed(unsigned int seed);

	//Get a float between 0.0f & 1.0f
	static float getFloat();

	//Get a Float from the Specified Range
	static float getFloatRange(float min, float max);

	//Get an int From the Specified Range
	static int getIntRange(int min, int max);

	//Get a Random vector given the min/max Bounds
	static Vector2 getVector(const Vector2& min, const Vector2& max);

private:
	static std::mt19937 sGenerator;
};
