#include "VersionStamp.h"
#include "SFML\Graphics\RenderWindow.hpp"

namespace Debug
{
	VersionStamp::VersionStamp(DebugWidget* aDebugWidget)
		: DebugDecorator(aDebugWidget)
	{
		myDebugString = "V: " + std::to_string(MAJOR) + "." + std::to_string(MINOR) + "." + std::to_string(PATCH);
		myDebugText.setString(myDebugString);
	}

	void VersionStamp::Load(const sf::RenderWindow & aRenderWindow)
	{
		DebugDecorator::Load(aRenderWindow);
		myDebugText.setPosition(10, aRenderWindow.getView().getSize().y - 100);
	}

	void VersionStamp::Render(sf::RenderWindow& aRenderWindow)
	{
		aRenderWindow.draw(myDebugText);
	}
}