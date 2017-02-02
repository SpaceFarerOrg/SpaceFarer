#pragma once
#include <SFML\Graphics\Sprite.hpp>
#include <SFML\Graphics\Texture.hpp>
#include <SFML\Graphics\Rect.hpp>
#include "Entity.h"

namespace sf
{
	class RenderWindow;
}

class Actor : public Entity
{
public:
	void Init(const char* const aTexturePath, bool aOriginIsMiddle = false, const sf::Vector2f& aStartPosition = { 0,0});
	virtual void Update(float aDeltaTime);
	void Render(sf::RenderWindow& aRenderWindow);
protected:
	sf::Texture myTexture;
	sf::Sprite mySprite;
};