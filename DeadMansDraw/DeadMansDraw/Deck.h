#pragma once

/*
	The deck holds at most 54 cards. 
	It manages these cards and passes them to the game whenever it is asked to.
*/

class Deck {
public:
	Deck();
	void shuffleCards();
	void getCard();
};