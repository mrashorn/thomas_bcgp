#include "PlayableCharacter.h"
#include <iostream>

void PlayableCharacter::spawn(Vector2f startPosition, float gravity, std::string name)
{
	// Place the player at the starting point.
	m_Position.x = startPosition.x;
	m_Position.y = startPosition.y;

	// Initialize gravity
	m_Gravity = gravity;

	// Move the entire sprite in to position
	m_Sprite.setPosition(m_Position);

	m_Name = name;
}

void PlayableCharacter::update(float elapsedTime)
{

	if (m_RightPressed)
		m_Position.x += m_Speed * elapsedTime;
	if (m_LeftPressed)
		m_Position.x -= m_Speed * elapsedTime;

	// Handle jumping
	if (m_IsJumping)
	{
		// Update how long the jump has been going
		m_TimeThisJump += elapsedTime;

		// IS the jump going upwards?
		if (m_TimeThisJump < m_JumpDuration)
		{
			// Move up at twice gravity
			m_Position.y -= m_Gravity * 2 * elapsedTime; // remember negative goes up on y coords
		}
		else
		{
			m_IsJumping = false;
			m_IsFalling = true;
		}
	} // end if(m_IsJumping)

	// Apply gravity
	if (m_IsFalling)
		m_Position.y += m_Gravity * elapsedTime;

	// Update the rect for all body parts
	FloatRect r = getPosition();


	// Feet
	m_Feet.left = r.left + 3;
	m_Feet.top = r.top + r.height - 1;
	m_Feet.width = r.width - 6;
	m_Feet.height = 10;

	// Head
	m_Head.left = r.left;
	m_Head.top = r.top + (r.height * .3);
	m_Head.width = r.width;
	m_Head.height = 1;

	// Right
	m_Right.left = r.left + r.width - 2;
	m_Right.top = r.top + r.height * .35; // .35
	m_Right.width = 1;
	m_Right.height = r.height * .3;

	// Left
	m_Left.left = r.left; 
	m_Left.top = r.top + r.height * .5;
	m_Left.width = 1;
	m_Left.height = r.height * .3;

	// Move the sprite into position
	m_Sprite.setPosition(m_Position);

}

FloatRect PlayableCharacter::getPosition()
{
	return m_Sprite.getGlobalBounds();
}

std::string PlayableCharacter::getName()
{
	return m_Name;
}

Vector2f PlayableCharacter::getCenter()
{
	return Vector2f(
			m_Position.x + m_Sprite.getGlobalBounds().width / 2,
			m_Position.y + m_Sprite.getGlobalBounds().height / 2);
}

FloatRect PlayableCharacter::getFeet()
{
	return m_Feet;
}

FloatRect PlayableCharacter::getHead()
{
	return m_Head;
}

FloatRect PlayableCharacter::getLeft()
{
	return m_Left;
}

FloatRect PlayableCharacter::getRight()
{
	return m_Right;
}

Sprite PlayableCharacter::getSprite()
{
	return m_Sprite;
}

void PlayableCharacter::stopFalling(float position)
{
	m_Position.y = position - getPosition().height;
	m_Sprite.setPosition(m_Position);
	m_IsFalling = false;
}

void PlayableCharacter::stopRight(float position)
{
	m_Position.x = position - m_Sprite.getGlobalBounds().width;
	m_Sprite.setPosition(m_Position);
}

void PlayableCharacter::stopLeft(float position)
{
	m_Position.x = position + m_Sprite.getGlobalBounds().width;
	m_Sprite.setPosition(m_Position);
}

void PlayableCharacter::stopJump()
{
	// Stop a jump early
	m_IsJumping = false;
	m_IsFalling = true;
}

void PlayableCharacter::printPosition()
{
	FloatRect r = getPosition();
	std::cout << "r.left: " << r.left << std::endl;
	std::cout << "r.top: " << r.top << std::endl;
	std::cout << "r.width: " << r.width << std::endl;
	std::cout << "r.height: " << r.height << std::endl;


	std::cout << "head.left: " << getHead().left << std::endl;
	std::cout << "head.top: " << getHead().top << std::endl;
	std::cout << "head.width: " << getHead().width << std::endl;
	std::cout << "head.height: " << getHead().height << std::endl;

	std::cout << "feet.left: " << getFeet().left << std::endl;
	std::cout << "feet.top: " << getFeet().top << std::endl;
	std::cout << "feet.width: " << getFeet().width << std::endl;
	std::cout << "feet.height: " << getFeet().height << std::endl;

	std::cout << "right.left: " << getRight().left << std::endl;
	std::cout << "right.top: " << getRight().top << std::endl;
	std::cout << "right.width: " << getRight().width << std::endl;
	std::cout << "right.height: " << getRight().height << std::endl;

	std::cout << "left.left: " << getLeft().left << std::endl;
	std::cout << "left.top: " << getLeft().top << std::endl;
	std::cout << "left.width: " << getLeft().width << std::endl;
	std::cout << "left.height: " << getLeft().height << std::endl;
}





