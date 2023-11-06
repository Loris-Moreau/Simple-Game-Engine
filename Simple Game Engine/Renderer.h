#pragma once

#include<SDL.h>

#include"Rectangle.h"
#include "Window.h"
#include "Vector2.h"
#include"Actor.h"

class Renderer
{
public:
	enum class Flip //Wrapper for SDL Sprite Flipping
	{
		None = SDL_FLIP_NONE,
		Horizontal = SDL_FLIP_HORIZONTAL,
		Vertical = SDL_FLIP_VERTICAL,
	};

	Renderer() = default;
	Renderer(const Renderer&) = delete;
	Renderer& operator=(const Renderer&) = delete;

	bool initialize(Window& window);

	void beginDraw();
	void draw();
	void endDraw();

	void drawRect(Rectangle& rect) const; //const Correctness
	void addSprite(class SpriteComponent* sprite);
	void removeSprite(class SpriteComponent* sprite);
	void drawSprites();
	void drawSprite(const Actor& actor, const class Texture& tex, Rectangle srcRect, Vector2 origin, Flip flip)const;

	SDL_Renderer* toSDLRenderer() const { return SDLRenderer; }
	void close();

private:
	SDL_Renderer* SDLRenderer{ nullptr };

	std::vector<SpriteComponent*> sprites;
};
