#pragma once
#include "PlayableCharacter.h"

class Thomas : public PlayableCharacter
{
	public:
		// a constructor specific to Thomas
		Thomas();

		// The overridden input handler for Thomas
		bool virtual handleInput();

};
