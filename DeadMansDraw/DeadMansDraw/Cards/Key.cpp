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
	return "";
}

void Key::willAddToBank(const Game& game) {

}
