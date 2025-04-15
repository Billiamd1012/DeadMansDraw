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

std::string Mermaid::toString() const {
	return "";
}

void Mermaid::willAddToBank(const Game& game) {

}
