#pragma once

/*
	Bank holds all of the cards that have previously been played by a player
*/
#include "CardCollection.h"


class Bank {
public:
	CardCollection bankedCards;
	std::string printBank();
};