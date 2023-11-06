#include <iostream>
#include<SDL.h>

using namespace std;

int main(int argc, char** args)
{
	//Screen Dimensions
	constexpr int SCREEN_WIDTH = 800;
	constexpr int SCREEN_HEIGHT = 450;
	//Window Pointer
	SDL_Window* window = nullptr;

	//Initialize SDL
	SDL_Init(SDL_INIT_VIDEO);

	//Create Window
	window = SDL_CreateWindow("Window", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);

	//Wait 2 Second
	SDL_Delay(2000);

	//Destroy Window
	SDL_DestroyWindow(window);

	//Quit SDL
	SDL_Quit;

	return 0;
}