#include "Kraken.h"
#include "../Game.h"

Kraken::Kraken(int _value) : value(_value) {
	suit = Suit::Kraken;
}

int Kraken::getValue() {
	return value;
}

void Kraken::play(const Game& _game, Player& player) {
	player.drawNCards(3);
}

Suit Kraken::type() {
	return suit;
}

std::string Kraken::toString(bool verbose) const {
	if (!verbose) {
		return "Kraken(" + std::to_string(value) + ")";
	}
	return "Kraken("+ std::to_string(value) +")\n	Must draw and play three cards consecutively.";
}

void Kraken::willAddToBank(const Game& game) {

}
