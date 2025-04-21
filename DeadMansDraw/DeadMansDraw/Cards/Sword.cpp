#include "Sword.h"
#include "../Game.h"
#include <iostream>
#include <unordered_map>

Sword::Sword(int _value) : value(_value) {
	suit = Suit::Sword;
}

int Sword::getValue() {
	return value;
}

void Sword::play(const Game& game, Player& player) {
	Player* otherPlayer = game.otherPlayer;
	Bank* otherBank = otherPlayer->getBank();

	if (otherBank->bankedCards.size() > 0) {
		// Find the index of the largest card
		std::unordered_map<Suit, size_t> largestCardIndices;
		for (size_t i = 0; i < otherBank->bankedCards.size(); ++i) {
			Suit suit = otherBank->bankedCards[i]->type();
			if (largestCardIndices.find(suit) == largestCardIndices.end() ||
				otherBank->bankedCards[i]->getValue() > otherBank->bankedCards[largestCardIndices[suit]]->getValue()) {
				largestCardIndices[suit] = i;
			}
		}

		//get all of the indicies that aren't the highest and remove them
		std::vector<size_t> indicesToRemove;
		for (const auto& pair : largestCardIndices) {
			indicesToRemove.push_back(pair.second);
		}
		std::sort(indicesToRemove.begin(), indicesToRemove.end(), std::greater<size_t>());

		//for each of the highest card print them out and as the player which index they want to remove
		for (size_t i = 0; i < indicesToRemove.size(); ++i) {
			size_t index = indicesToRemove[i];
			const std::unique_ptr<Card>& card = otherBank->bankedCards[index];
			std::cout << "\t(" << i + 1 << ") " << card->toString(false) << "\n";
		}

		// Ask the player to choose one to discard
		int choice = -1;
		do {
			std::cout << "\tWhich card do you pick? ";
			std::cin >> choice;
		} while (choice < 0 || static_cast<size_t>(choice - 1) >= indicesToRemove.size());

		// Get the chosen card's index in the original bankedCards vector
		size_t selectedIndex = indicesToRemove[choice - 1];
		// Remove and move the card
		std::unique_ptr<Card> removedCard = std::move(otherBank->bankedCards[selectedIndex]);
		std::cout << "\tYou swipe the " << removedCard.get()->toString(false) << " out of the other player's Bank\n";
		std::cout << removedCard.get()->toString(true);
		otherBank->bankedCards.erase(otherBank->bankedCards.begin() + selectedIndex);
		game.currentPlayer->playCard(std::move(removedCard));
	}
	else {
		std::cout << "No cards in the other players bank.\n";
	}
}

Suit Sword::type() {
	return suit;
}

std::string Sword::toString(bool verbose) const {
	if (!verbose) {
		return "Sword(" + std::to_string(value) + ")";
	}
	return "Sword("+ std::to_string(value) +")\n	Steal the top card (i.e. the highest value) of any suit from the other player's Bank into your Play Area.You must select one card.";
}

void Sword::willAddToBank(const Game& game) {

}
