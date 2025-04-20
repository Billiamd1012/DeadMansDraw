#include "Cannon.h"
#include "../Game.h"
#include <iostream>

using namespace std;



Cannon::Cannon(int _value) : value(_value){
	suit = Suit::Cannon;
}

int Cannon::getValue() {
	return value;
}


/*
	Discard the top card (i.e. the highest value) of any suit from
	the other player’s Bank to the Discard Pile.
*/
void Cannon::play(const Game& game, Player& player) {
	//other player
	Player* otherPlayer = game.otherPlayer;
	Bank* otherBank = otherPlayer->getBank();

	//get largest card from other bank
	if (otherBank->bankedCards.size() > 0) {
		// Find the index of the largest card
		size_t largestIndex = 0;
		for (size_t i = 1; i < otherBank->bankedCards.size(); ++i) {
			if (otherBank->bankedCards[i]->getValue() >= otherBank->bankedCards[largestIndex]->getValue()) {
				largestIndex = i;
			}
		}

		// Move the largest card out of the bank
		std::unique_ptr<Card> removedCard = std::move(otherBank->bankedCards[largestIndex]);

		// Erase the empty spot from the vector
		otherBank->bankedCards.erase(otherBank->bankedCards.begin() + largestIndex);

		// Discard it
		otherPlayer->discardCard(std::move(removedCard));

	}
	else {
		std:cout << "No cards found in "<< game.otherPlayer->playerName <<"'s bank.";
	}
}

Suit Cannon::type() {
	return suit;
}

std::string Cannon::toString(bool verbose) const{
	if (!verbose) {
		return "Cannon(" + std::to_string(value) + ")";
	}
	return "Cannon("+ std::to_string(value) +")\n	Discard the top card (i.e. the highest value) of any suit from the other player’s Bank to the Discard Pile.";
}


void Cannon::willAddToBank(const Game& game) {

}
