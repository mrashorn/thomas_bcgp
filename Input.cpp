// Handles the input functionality of Engine class.
#include "Engine.h"


void Engine::input()
{
	Event event;
	while(m_Window.pollEvent(event))
	{
		if (event.type == Event::KeyPressed)
		{
			// Handle the player quitting
			if (Keyboard::isKeyPressed(Keyboard::Escape))
			{
				m_Window.close();
			}

			// Handle the player starting the game
			if (Keyboard::isKeyPressed(Keyboard::Return))
			{
				m_Playing = true;
			}

			// Switch between Thomas and Bob
			if (Keyboard::isKeyPressed(Keyboard::Q))
			{
				m_Character1 = !m_Character1; // toggle bool
			}

			// Switch between full and split screen
			if (Keyboard::isKeyPressed(Keyboard::E))
			{
				m_SplitScreen = !m_SplitScreen; // toggle bool
			}

		} // if event keypressed
	} // while poll event
} // end input()