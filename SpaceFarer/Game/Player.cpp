#include "Player.h"
#include <SFML\Window\Event.hpp>
#include <SFML\Window\Keyboard.hpp>
#include "..\Engine\MathTools.h"
#include <cmath>
#include "SFML\Graphics\RenderWindow.hpp"

Player::Player()
{
}

void Player::Update(float aDeltaTime)
{
	myShip->Update(aDeltaTime);
}

void Player::Render(sf::RenderWindow & aRenderWindow)
{
	myShip->Render(aRenderWindow);
}

void Player::GiveShip(Ship * aShip)
{
	myShip = aShip;

	for (unsigned int index = 0; index < myObservers.size(); ++index)
	{
		myShip->AttatchObserver(myObservers[index]);
	}

	NotifyObservers(EVENT_PLAYER_NEW_SHIP, myShip->GetName());
}

void Player::SetTarget(const sf::Vector2f & aTargetPosition)
{
	NotifyObservers(EVENT_PLAYER_NEW_WAYPOINT, aTargetPosition.x, aTargetPosition.y);
}


Ship & Player::GetShip() const
{
	return *myShip;
}

Wallet & Player::GetWallet()
{
	return myWallet;
}
