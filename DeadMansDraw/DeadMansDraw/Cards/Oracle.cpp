#include "Oracle.h"

Oracle::Oracle(int _value) : value(_value) {
	suit = Suit::Oracle;
}

int Oracle::getValue() {
	return value;
}

void Oracle::play(const Game& _game, Player& player) {

}

Suit Oracle::type() {
	return suit;
}

std::string Oracle::toString() const {
	return "Oracle("+ std::to_string(value) +")\n	Peek at the top card of the deck before choosing whether to draw.";
}

void Oracle::willAddToBank(const Game& game) {

}
