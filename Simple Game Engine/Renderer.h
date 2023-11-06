#pragma once

#include<SDL.h>

#include"Rectangle.h"
#include "Window.h"

class Renderer
{
public:
	Renderer() = default;

	inline SDL_Renderer* toSDLRenderer() const { return SDLRenderer; }

	bool initialize(Window& window);

	void beginDraw();
	void drawRect(Rectangle& rect);
	void endDraw();

	void close();

private:
	SDL_Renderer* SDLRenderer{ nullptr };

	Renderer(const Renderer&) = delete;
	Renderer& operator=(const Renderer&) = delete;
};
