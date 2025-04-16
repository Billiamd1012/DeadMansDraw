#include "Key.h"

Key::Key(int _value) : value(_value) {
	suit = Suit::Key;
}

int Key::getValue() {
	return value;
}

void Key::play(const Game& _game, Player& player) {

}

Suit Key::type() {
	return suit;
}

std::string Key::toString() const {
	return "Key("+ std::to_string(value) +")\n	No immediate effect. If banked with a Chest card, draw as many bonus cards from the Discard pile as you moved into your Bank.";
}

void Key::willAddToBank(const Game& game) {

}
