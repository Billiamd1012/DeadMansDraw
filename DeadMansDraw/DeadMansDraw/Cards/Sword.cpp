#include "Sword.h"

Sword::Sword(int _value) : value(_value) {
	suit = Suit::Sword;
}

int Sword::getValue() {
	return value;
}

void Sword::play(const Game& _game, Player& player) {

}

Suit Sword::type() {
	return suit;
}

std::string Sword::toString(bool verbose) const {
	if (!verbose) {
		return "Sword(" + std::to_string(value) + ")";
	}
	return "Sword("+ std::to_string(value) +")\n	Steal the top card (i.e. the highest value) of any suit from the other player’s Bank into your Play Area.You must select one card.";
}

void Sword::willAddToBank(const Game& game) {

}
