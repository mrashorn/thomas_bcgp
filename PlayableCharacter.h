#pragma once
#include <SFML/Graphics.hpp>

using namespace sf;

class PlayableCharacter {
	protected:
		Sprite m_Sprite;
		std::string m_Name;

		// how long does a jump last
		float m_JumpDuration;

		// is character currently jumping or falling
		bool m_IsJumping;
		bool m_IsFalling;

		// Which direction is the character currently moving?
		bool m_LeftPressed;
		bool m_RightPressed;

		// How long has this jump lasted for?
		float m_TimeThisJump;

		// Has the player just initiated a jump?
		bool m_JustJumped = false;


	private:
		// what is the gravity?
		float m_Gravity;

		// how fast is the character?
		float m_Speed = 400;

		// where is the player?
		Vector2f m_Position;

		// Where are the characters various body parts?
		FloatRect m_Feet;
		FloatRect m_Head;
		FloatRect m_Right;
		FloatRect m_Left;

		// And a texture
		Texture m_Texture;

	public:
		void spawn(Vector2f startPosition, float gravity, std::string name);

		// This is a pure virtual function
		bool virtual handleInput() = 0;
		// This class is now abstract and cannot be instantiated

		// Where is the player?
		FloatRect getPosition();

		// A rectangle representing the position of different parts of the sprite
		FloatRect getFeet();
		FloatRect getHead();
		FloatRect getRight();
		FloatRect getLeft();

		void printPosition();

		// Send a copy of sprite to main
		Sprite getSprite();

		// Make the character stand firm
		void stopFalling(float position);
		void stopRight(float position);
		void stopLeft(float position);
		void stopJump();

		// Where is the center of the character
		Vector2f getCenter();

		// We will call this function once every frame
		void update(float elapsedTime);

}; // end of class
