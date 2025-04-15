#include "Cannon.h"

Cannon::Cannon(int _value) : value(_value){
	suit = Suit::Cannon;
}

int Cannon::getValue() {
	return value;
}

void Cannon::play(const Game& _game, Player& player) {

}

Suit Cannon::type() {
	return suit;
}

std::string Cannon::toString() const{
	return "";
}

void Cannon::willAddToBank(const Game& game) {

}
