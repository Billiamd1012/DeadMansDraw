#include "Hook.h"

Hook::Hook(int _value) : value(_value) {
	suit = Suit::Hook;
}

int Hook::getValue() {
	return value;
}

void Hook::play(const Game& _game, Player& player) {

}

Suit Hook::type() {
	return suit;
}

std::string Hook::toString() const {
	return "Hook( "+ std::to_string(value) +")";;
}

void Hook::willAddToBank(const Game& game) {

}
