#include <iostream>
#include<SDL.h>

#include "Game.h"

using namespace std;

int main(int argc, char** args)
{
	bool isGameInit = Game::instance().initialize();
	if (isGameInit)
	{
		Game::instance().loop();
	}

	Game::instance().close();

	return 0;
}