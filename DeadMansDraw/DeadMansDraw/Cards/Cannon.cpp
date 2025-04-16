#include "Cannon.h"

Cannon::Cannon(int _value) : value(_value){
	suit = Suit::Cannon;
}

int Cannon::getValue() {
	return value;
}

void Cannon::play(const Game& _game, Player& player) {

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
