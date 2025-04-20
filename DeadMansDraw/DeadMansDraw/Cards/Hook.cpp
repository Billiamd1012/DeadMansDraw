#include "Hook.h"
#include "../Game.h"
#include <iostream>
#include <unordered_map>

Hook::Hook(int _value) : value(_value) {
	suit = Suit::Hook;
}

int Hook::getValue() {
	return value;
}

void Hook::play(const Game& game, Player& player) {
	Player* currentPlayer = game.currentPlayer;
	Bank* playerBank = currentPlayer->getBank();

	if (playerBank->bankedCards.size() > 0) {
		// Find the index of the largest card
		std::unordered_map<Suit, size_t> largestCardIndices;
		for (size_t i = 0; i < playerBank->bankedCards.size(); ++i) {
			Suit suit = playerBank->bankedCards[i]->type();
			if (largestCardIndices.find(suit) == largestCardIndices.end() ||
				playerBank->bankedCards[i]->getValue() > playerBank->bankedCards[largestCardIndices[suit]]->getValue()) {
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
			const std::unique_ptr<Card>& card = playerBank->bankedCards[index];
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
		std::unique_ptr<Card> removedCard = std::move(playerBank->bankedCards[selectedIndex]);
		std::cout << "\tYou hook the " << removedCard.get()->toString(false) << " out of your Bank\n";
		playerBank->bankedCards.erase(playerBank->bankedCards.begin() + selectedIndex);
		currentPlayer->playCard(std::move(removedCard));
	}
}

Suit Hook::type() {
	return suit;
}

std::string Hook::toString(bool verbose) const {
	if (!verbose) {
		return "Hook(" + std::to_string(value) + ")";
	}
	return "Hook("+ std::to_string(value) +")\n\tPlay the top card (i.e. the highest value) of any suit from your Bank into your play area.You must select one card.";
}

void Hook::willAddToBank(const Game& game) {

}
