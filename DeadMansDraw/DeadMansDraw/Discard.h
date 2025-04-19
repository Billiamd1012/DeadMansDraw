#pragma once
/*
	Object that contains all of the cards that have been discarded
*/

#include "CardCollection.h"

class Discard {
public:
	void addCard(std::unique_ptr<Card> card);
private:
	CardCollection discardedCards;
};