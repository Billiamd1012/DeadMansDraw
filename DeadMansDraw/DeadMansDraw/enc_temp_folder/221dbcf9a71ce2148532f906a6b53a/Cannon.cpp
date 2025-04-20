#include "Cannon.h"
#include "../Game.h"
#include <iostream>
#include <unordered_map>


using namespace std;


Cannon::Cannon(int _value) : value(_value) {
	suit = Suit::Cannon;
}
int Cannon::getValue() {
	return value;
}


/*
	Discard the top card (i.e. the highest value) of any suit from
	the other player’s Bank to the Discard Pile.
*/
void Cannon::play(const Game& game, Player& player) {
	//other player
	Player* otherPlayer = game.otherPlayer;
	Bank* otherBank = otherPlayer->getBank();

	//get largest card from every suit from the other bank
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

		for (size_t index : indicesToRemove) {
			// Remove and discard the card
			std::unique_ptr<Card> removedCard = std::move(otherBank->bankedCards[index]);
			otherBank->bankedCards.erase(otherBank->bankedCards.begin() + index);
			otherPlayer->discardCard(std::move(removedCard));
		}

	}
	else {
		std::cout << "No cards found in "<< game.otherPlayer->playerName <<"'s bank.";
	}
}

Suit Cannon::type() {
	return suit;
}

std::string Cannon::toString(bool verbose) const{
	if (!verbose) {
		return "Cannon(" + std::to_string(value) + ")";
	}
	return "Cannon("+ std::to_string(value) +")\n	Discard the top card (i.e. the highest value) of any suit from the other player’s Bank to the Discard Pile.";
}


void Cannon::willAddToBank(const Game& game) {

}
