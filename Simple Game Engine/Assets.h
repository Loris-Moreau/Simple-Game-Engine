#pragma once

#include<map>
#include<string>

#include"Texture.h"

using std::map;
using std::string;

//A Static Singleton Assets class that Hosts Several Functions to Load Ressources is also Stored for Future Reference by String handles.
//All Functions and Ressourcess are Static and no Public Constructor is Defined

class Assets
{
public:
	static std::map<std::string, Texture> textures;

	//Loads a Texture from File
	static Texture loadTexture(Renderer& renderer, const string& filename, const string& name);

	//Retrieves a Stored Texture
	static Texture& getTexture(const std::string& name);

	//Propperlly Deallocate all Loaded Resources
	static void clear();

private:
	Assets() {}

	//Loads a Single Texture From File
	static Texture loadTextureFromFile(Renderer& renderer, const string& filename);
};
