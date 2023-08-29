#pragma once
#include "PlayableCharacter.h"

class Bob : public PlayableCharacter
{
	public:
		// constructor specific to Bob
		Bob();

		// Overridden input handler for Bob
		bool virtual handleInput();
};
