#include "Texture.h"
#include "Log.h"

#include <SDL_image.h>

Texture::~Texture()
{

}

void Texture::unload()
{
	if (SDLTexture)
	{
		SDL_DestroyTexture(SDLTexture);
	}
}

bool Texture::load(Renderer& renderer, const string& filenameP)
{
	filename = filenameP;
	//Load From File
	SDL_Surface* surf = IMG_Load(filename.c_str()); //SDL Load a Surface, wich is on an array of pixel color, then Convert it to a GPU Optimized Texture
	if (!surf)
	{
		Log::error(LogCategory::Application, "Failed to Load Texture File" + filename);
		return false;
	}
	width = surf->w;
	height = surf->h;

	//Create Texture from Surface
	SDLTexture = SDL_CreateTextureFromSurface(renderer.toSDLRenderer(), surf);
	SDL_FreeSurface(surf); // Once Converted, we don't need the surface Anymore
	if (!SDLTexture)
	{
		Log::error(LogCategory::Render, "Failed to Convert Surface to Texture for " + filename);
		return false;
	}
	Log::info("Loaded Texture " + filename);

	return true;
}

void Texture::updateInfo(int& widthOut, int& heightOut)
{
	widthOut = width;
	heightOut = height;
}
