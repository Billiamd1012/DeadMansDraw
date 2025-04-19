
#include "Discard.h"

void Discard::addCard(std::unique_ptr<Card> card) {
	discardedCards.push_back(std::move(card));

}
