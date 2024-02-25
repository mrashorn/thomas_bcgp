#include "Engine.h"

void Engine::loadLevel()
{
	m_Playing = false;

	// Delete the previously allocated memory
	for (int i = 0; i < m_LM.getLevelSize().y; ++i)
	{
		delete[] m_ArrayLevel[i];
	}
	delete[] m_ArrayLevel;

	// Load the next 2D array with the map for the level
	// and repopulate the vertex array as well
	m_ArrayLevel = m_LM.nextLevel(m_VALevel);

	// How long is this new time limit
	m_TimeRemaining = m_LM.getTimeLimit();

	// Spawn Thomas and Bob
	m_Thomas.spawn(m_LM.getStartPosition(), GRAVITY, "Thomas");
	m_Bob.spawn(m_LM.getStartPosition(), GRAVITY, "Bob");

	// Make sure this code isn't run again
	m_NewLevelRequired = false;
}
