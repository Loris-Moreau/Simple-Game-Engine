#include "Asteroid.h"
#include"Random.h"
#include"Window.h"
#include"Maths.h"
#include"SpriteComponent.h"
#include"MoveComponent.h"
#include"Assets.h"

Asteroid::Asteroid() : Actor()
{
	Vector2 randPos = Random::getVector(Vector2::zero, Vector2(WINDOW_WIDTH, WINDOW_HEIGHT));
	setPosition(randPos);
	setRotation(Random::getFloatRange(0.0f, Maths::twoPi));

	SpriteComponent* sc = new SpriteComponent(this, Assets::getTexture("Asteroid"));
	MoveComponent* mc = new MoveComponent(this); //Having our Own Class for Asteroid Allows to Easily Create Their Components Structure
	mc->setForwardSpeed(150.f);
}
