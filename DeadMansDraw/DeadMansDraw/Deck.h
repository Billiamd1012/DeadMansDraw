#pragma once

/*
	The deck holds at most 54 cards. 
	It manages these cards and passes them to the game whenever it is asked to.
*/
#include "CardCollection.h"

class Card;

class Deck {
public:
	Deck();
	void shuffleCards();
	std::unique_ptr<Card> getCard();
	Card* showNext() const;
private:
	CardCollection cards;
	void createCards();
};