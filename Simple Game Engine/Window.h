#pragma once
#include <SDL.h>

//Screen Dimensions
constexpr int SCREEN_WIDTH = 1024;
constexpr int SCREEN_HEIGHT = 768;

class Window
{
public:
	Window() = default;
	Window(const Window&) = delete;
	Window& operator = (const Window&) = delete;

	bool initialize();
	void close();

	SDL_Window* getSDLWindow() const { return SDLWindow; } //const Correctness : getters do not modify the object
	
	int GetWidth() const { return width; }
	int GetHeight() const { return height; }

private:
	SDL_Window* SDLWindow{ nullptr };

	int width{ SCREEN_WIDTH };
	int height{ SCREEN_HEIGHT };
};

