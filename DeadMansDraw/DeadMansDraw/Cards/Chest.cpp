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
	return "Chest("+ std::to_string(value) +")\n	No immediate effect. If banked with a Key card, draw as many bonus cards from the Discard pile as you moved into your Bank.";
}

void Chest::willAddToBank(const Game& game) {

}
