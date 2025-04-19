/*
	Bank holds all of the cards that have previously been played by a player
*/
#include "Bank.h"

std::string Bank::printBank() {
    std::string result;
    int score = 0;

    for (size_t i = 0; i < bankedCards.size(); ++i) {
        result += "\t" + bankedCards[i]->toString(false) + "\n";
        score += bankedCards[i]->getValue();
    }

    return result + "|Score: "+ std::to_string(score) + "\n";
}