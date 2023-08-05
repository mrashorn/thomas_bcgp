#include "Engine.h"

void Engine::draw()
{
	// Rub out the last frame
	m_Window.clear(Color::White);

	if (!m_SplitScreen)
	{
		// switch to background view
		m_Window.setView(m_BGMainView);
		// draw the background
		m_Window.draw(m_BackgroundSprite);
		// switch to m_MainView 
		m_Window.setView(m_MainView);
	}
	else
	{
		// Split-screen is active
		// first draw Thomas's side of the screen
		// Switch to background view
		m_Window.setView(m_BGLeftView);
		// draw the background
		m_Window.draw(m_BackgroundSprite);
		// switch to m_LeftView
		m_Window.setView(m_LeftView);

		// Now draw Bob's side of the screen
		// Switch to background view
		m_Window.setView(m_BGRightView);
		// draw the background
		m_Window.draw(m_BackgroundSprite);
		// switch to m_LeftView
		m_Window.setView(m_RightView);
	}

	// Draw the HUD
	// Switch to m_HudView
	m_Window.setView(m_HudView);
	
	// Show everything we have just drawn
	m_Window.display();

}
