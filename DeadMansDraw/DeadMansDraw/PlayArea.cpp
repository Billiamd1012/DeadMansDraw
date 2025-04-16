#include "PlayArea.h"

void PlayArea::play(std::unique_ptr<Card> card) {
	playedCards.push_back(std::move(card));
}

std::string PlayArea::toString() {

}