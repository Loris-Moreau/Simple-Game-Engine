#include "BackgroundSpriteComponent.h"

BackgroundSpriteComponent::BackgroundSpriteComponent(Actor* ownerP, const vector<Texture*>& texturesP, int drawOrderP)
	: SpriteComponent(ownerP, *texturesP[0], drawOrderP), scrollSpeed(0.0f), screenSize(Vector2(SCREEN_WIDTH, SCREEN_HEIGHT))
{
	setTextures(texturesP);
}

BackgroundSpriteComponent::~BackgroundSpriteComponent() 
{

}

void BackgroundSpriteComponent::setTextures(const vector<Texture*>& texturesP)
{
	int count = 0;
	for (auto tex : texturesP)
	{
		BGTexture temp{ *tex, Vector2(count * screenSize.x,0) }; //Each Texture has Screen_Width as an offset
		textures.emplace_back(temp);
		count++;
	}
}

void BackgroundSpriteComponent::setScreenSize(const Vector2& screenSizeP)
{
	screenSize = screenSizeP;
}

void BackgroundSpriteComponent::setScrollSpeed(float scrollSpeedP)
{
	scrollSpeed = scrollSpeedP;
}

void BackgroundSpriteComponent::update(float dt)
{
	SpriteComponent::update(dt);

	for (auto& bg : textures)
	{
		bg.offset.x += scrollSpeed * dt;

		//If This is Completely off the Screen, Reset Offset to the Right of the Last BG Texture
		if (bg.offset.x < -screenSize.x)
		{
			bg.offset.x = (textures.size() - 1) * screenSize.x - 1;
		}
	}
}

void BackgroundSpriteComponent::draw(Renderer& renderer)
{
	//Draw Each Background Textures
	for (auto& bg : textures)
	{
		owner.setPosition(Vector2(bg.offset.x, bg.offset.y));
		renderer.drawSprite(owner, bg.texture, Rectangle::nullRect, Vector2::zero, Renderer::Flip::None);
	}
}
