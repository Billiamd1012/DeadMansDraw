#include "Map.h"

Map::Map(int _value) : value(_value) {
	suit = Suit::Map;
}

int Map::getValue() {
	return value;
}

void Map::play(const Game& _game, Player& player) {

}

Suit Map::type() {
	return suit;
}

std::string Map::toString() const {
	return "Map("+ std::to_string(value) +")";;
}

void Map::willAddToBank(const Game& game) {

}
