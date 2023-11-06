#pragma once
#include<SDL.h>

#include"Rectangle.h"
#include "Window.h"

class Renderer
{
public:
	Renderer() = default;
	Renderer(const Renderer&) = delete;

	bool initialize(Window& window);
	void beginDraw();
	void drawRect(Rectangle& rect);
	void endDraw();
	void close();

private:
	SDL_Renderer* SDLRenderer{ nullptr };
};

