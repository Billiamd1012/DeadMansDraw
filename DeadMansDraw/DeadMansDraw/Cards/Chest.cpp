#include "Chest.h"
#include "../Game.h"

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

std::string Chest::toString(bool verbose) const {
	if (!verbose) {
		return "Chest(" + std::to_string(value) + ")";
	}
	return "Chest("+ std::to_string(value) +")\n	No immediate effect. If banked with a Key card, draw as many bonus cards from the Discard pile as you moved into your Bank.";
}

void Chest::willAddToBank(const Game& game) {
	//check if there is a key in the play area
	bool key = false;
	PlayArea* playArea = game.currentPlayer->getPlayArea();
	for (size_t i = 0; i < playArea->playedCards.size(); ++i) {
		if (playArea->playedCards[i].get()->type() == Suit::Key) {
			key = true;
		}
	}

	//if there is
	if (key) {
		Bank* playerBank = game.currentPlayer->getBank();
		Discard* discard = game.currentPlayer->getDiscardPile();
		//get the total number of cards in the play area
		int totalCards = playArea->playedCards.size();
		int maxToAdd = std::min((int)discard->discardedCards.size(), totalCards);

		std::vector<std::string> addedCards;

		//move that number or all of the cards in the bank (whichever is lower) from the discard pile into the bank
		for (int i = 0; i < maxToAdd; ++i) {
			addedCards.push_back(discard->discardedCards[i].get()->toString(false));
			playerBank->bankedCards.push_back(std::move(discard->discardedCards[i]));
		}
		if (addedCards.size() == 0) {
			std::cout << "No cards in the discard pile.";
		}
		else if (addedCards.size() == 1) {
			std::cout << "Chest and key activated. Added " << addedCards[0] << " to your bank.";
		}
		else {
			std::cout << "Chest and key activated. Added ";
			for (size_t i = 0; i < addedCards.size(); ++i) {
				std::cout << addedCards[i];
				if (i < addedCards.size() - 1) {
					std::cout << ", ";
				}
			}
			std::cout << " to your bank.";
		}
		
	}
}
