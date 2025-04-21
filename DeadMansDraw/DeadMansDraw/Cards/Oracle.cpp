#include "Oracle.h"
#include "../Game.h"
#include <iostream>


Oracle::Oracle(int _value) : value(_value) {
	suit = Suit::Oracle;
}

int Oracle::getValue() {
	return value;
}

void Oracle::play(const Game& _game, Player& player) {
	Card* nextCard = _game.deck.showNext();
	std::cout << "\tThe oracle shows you the next card is a " << nextCard->toString(false) << "\n";
}

Suit Oracle::type() {
	return suit;
}

std::string Oracle::toString(bool verbose) const {
	if (!verbose) {
		return "Oracle(" + std::to_string(value) + ")";
	}
	return "Oracle("+ std::to_string(value) +")\n	Peek at the top card of the deck before choosing whether to draw.";
}

void Oracle::willAddToBank(const Game& game) {

}
