#include "Mermaid.h"

Mermaid::Mermaid(int _value) : value(_value) {
	suit = Suit::Mermaid;
}

int Mermaid::getValue() {
	return value;
}

void Mermaid::play(const Game& _game, Player& player) {

}

Suit Mermaid::type() {
	return suit;
}

std::string Mermaid::toString(bool verbose) const {
	if (!verbose) {
		return "Mermaid(" + std::to_string(value) + ")";
	}
	return "Mermaid("+ std::to_string(value) +")\n	No ability but the cards have a higher point value.";
}

void Mermaid::willAddToBank(const Game& game) {

}
