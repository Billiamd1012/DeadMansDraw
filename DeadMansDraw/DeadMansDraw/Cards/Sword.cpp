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

std::string Sword::toString() const {
	return "";
}

void Sword::willAddToBank(const Game& game) {

}
