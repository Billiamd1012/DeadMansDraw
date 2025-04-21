#include "Map.h"
#include "../Game.h"
#include <iostream>


Map::Map(int _value) : value(_value) {
	suit = Suit::Map;
}

int Map::getValue() {
	return value;
}

void Map::play(const Game& _game, Player& player) {
	Discard* discardPile = _game.currentPlayer->getDiscardPile();
	//if size of 
	if (discardPile->discardedCards.size() > 0) {
		//draw top 3 cards from the discard pile
		int maxToAdd = std::min((int)discardPile->discardedCards.size(), 3);

		for (int i = 0; i < maxToAdd; ++i) {
			std::cout<< "\t(" << i+1 << ")" << (discardPile->discardedCards[i].get()->toString(false))<<"\n";
		}

		// Ask the player to choose one to discard
		int choice = -1;
		do {
			std::cout << "\tWhich card do you pick? ";
			std::cin >> choice;
		} while (choice < 0 || static_cast<size_t>(choice - 1) >= discardPile->discardedCards.size());

		// Remove and move the card
		std::unique_ptr<Card> removedCard = std::move(discardPile->discardedCards[choice-1]);
		std::cout << "\tYou played the " << removedCard.get()->toString(true) << "\n";
		discardPile->discardedCards.erase(discardPile->discardedCards.begin() + choice-1);
		_game.currentPlayer->playCard(std::move(removedCard));
	}
	else {
		std::cout << "No cards in the discard pile.";
	}
}

Suit Map::type() {
	return suit;
}

std::string Map::toString(bool verbose) const {
	if (!verbose) {
		return "Map(" + std::to_string(value) + ")";
	}
	return "Map("+ std::to_string(value) +")\n	Draw 3 cards from discard pile. You must play one of the cards drawn into your play area.";
}

void Map::willAddToBank(const Game& game) {

}
