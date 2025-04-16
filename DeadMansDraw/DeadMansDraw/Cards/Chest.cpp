#include "Chest.h"

Chest::Chest(int _value) : value(_value) {
	suit = Suit::Chest;
}

int Chest::getValue() {
	return value;
}

void Chest::play(const Game& _game, Player& player) {

}

Suit Chest::type() {
	return suit;
}

std::string Chest::toString() const {
	return "Chest("+ std::to_string(value) +")";;
}

void Chest::willAddToBank(const Game& game) {

}
