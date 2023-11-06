#include "Game.h"

bool Game::initialize()
{
	bool isWindowInit = window.initialize();
	bool isRendererInit = renderer.initialize(window);

	int windowWidth = window.GetWidth();
	int windowHeight = window.GetHeight();

	topWall = { 0,0,static_cast<float>(windowWidth), wallThickness };
	bottomWall = { 0, windowHeight - wallThickness, static_cast<float>(windowWidth),wallThickness };
	rightWall = { windowWidth - wallThickness,0,wallThickness, static_cast<float>(windowHeight) };

	return isWindowInit && isRendererInit; //Return bool && bool && bool... to detect error
}

void Game::loop()
{
	Timer timer;
	float dt = 0;

	while (isRunning)
	{
		float dt = timer.computeDeltaTime() / 1000.0f;

		processInput();
		update(dt);
		render();

		timer.delayTime();
	}
}

void Game::close()
{
	renderer.close();
	window.close();
	SDL_Quit();
}

void Game::processInput()
{
	//SDL Event
	SDL_Event event;
	while (SDL_PollEvent(&event))
	{
		switch (event.type)
		{
		case SDL_QUIT:
			isRunning = false;
			break;
		}
	}
	//Keyboard State
	const Uint8* keyboardState = SDL_GetKeyboardState(nullptr);
	//Escape Key = Quit Game
	if (keyboardState[SDL_SCANCODE_ESCAPE])
	{
		isRunning = false;
	}

	//Paddle Move
	if (keyboardState[SDL_SCANCODE_W])
	{
		paddleDirection = -1;
	}
	if (keyboardState[SDL_SCANCODE_S])
	{
		paddleDirection = 1;
	}
}

void Game::update(float dt)
{
	//Paddle Move 
	paddlePos += paddleVelocity * dt * paddleDirection;
	if (paddlePos.y < paddleHeight / 2 - wallThickness)
	{
		paddlePos.y = paddleHeight / 2 + wallThickness;
	}
	if (paddlePos.y > window.GetHeight() - paddleHeight / 2 - wallThickness)
	{
		paddlePos.y = window.GetHeight() - paddleHeight / 2 - wallThickness;
	}

	//Ball Move
	ballPos += ballVelocity * dt;
	if (ballPos.y < ballSize / 2 + wallThickness)
	{
		ballPos.y = ballSize / 2 + wallThickness;
		ballVelocity.y *= -1;
	}
	else if (ballPos.y > window.GetHeight() - ballSize / 2 - wallThickness)
	{
		ballPos.y = window.GetHeight() - ballSize / 2 - wallThickness;
		ballVelocity.y *= -1;
	}
	if (ballPos.x > window.GetWidth() - ballSize / 2 - wallThickness)
	{
		ballPos.x = window.GetWidth() - ballSize / 2 - wallThickness;
		ballVelocity.x *= -1;
	}
}

void Game::render()
{
	renderer.beginDraw();

	renderer.drawRect(topWall);
	renderer.drawRect(bottomWall);
	renderer.drawRect(rightWall);

	Rectangle ballRect = { ballPos.x * ballSize / 2, ballPos.y * ballSize / 2, ballSize };
	renderer.drawRect(ballRect);	
	
	Rectangle paddleRect = { paddlePos.x - paddleWidth / 2, paddlePos.y - paddleHeight / 2, paddleWidth, paddleHeight };
	renderer.drawRect(paddleRect);

	renderer.endDraw();
}