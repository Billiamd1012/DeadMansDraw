#pragma once

/*
	Play area holds all of the cards for that turn
*/
#include "CardCollection.h"

class Card;

class PlayArea {
public:
	void play(std::unique_ptr<Card> card);
	std::string toString();
private:
	CardCollection playedCards;
};