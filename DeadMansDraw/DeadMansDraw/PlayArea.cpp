#include "PlayArea.h"

void PlayArea::play(std::unique_ptr<Card> card) {
	playedCards.push_back(std::move(card));
}

std::string PlayArea::toString() {
    std::string result;

    for (size_t i = 0; i < playedCards.size(); ++i) {
        result += "\t" + playedCards[i]->toString(false) + "\n";
    }

    return result + "\n";
}
