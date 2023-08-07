#include "PlayableCharacter.h"

void PlayableCharacter::spawn(Vector2f startPosition, float gravity)
{
	// Place the player at the starting point.
	m_Position.x = startPosition.x;
	m_Position.y = startPosition.y;

	// Initialize gravity
	m_Gravity = gravity;

	// Move the entire sprite in to position
	m_Sprite.setPosition(m_Position);
}
