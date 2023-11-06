#include "Assets.h"
#include "Log.h"

#include <sstream>

std::map<std::string, Texture> Assets::textures; //Because it's Static, we have to Define it

Texture Assets::loadTexture(Renderer& renderer, const string& filename, const string& name)
{
	if (textures.find(name) == end(textures))
	{
		std::ostringstream loadError;
		loadError << "Textures " << name << " does not Exist in Assets Manager.";
		Log::error(LogCategory::Application, loadError.str());
	}
}

void Assets::clear()
{
	//(Properly) Delete all Textures
	for (auto iter : textures)
		iter.second.unload();
	textures.clear();
}

Texture Assets::loadTextureFromFile(Renderer& renderer, const string& filename)
{
	Texture texture;
	texture.load(renderer, filename);
	return texture;
}