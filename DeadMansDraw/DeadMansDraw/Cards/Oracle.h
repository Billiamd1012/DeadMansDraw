#pragma once

/*
    Oracle is a card that has the ability to peek at the top card of the deck before choosing whether to
    draw. With point values 2,3,4,5,6,7
*/

#include "Card.h"
#include "Suit.h"

class Oracle : public Card {
public:
    Oracle(int value);
    Suit type();
    std::string toString(bool verbose) const override;
    void willAddToBank(const Game& game);
    int getValue();
    void play(const Game& _game, Player& player);
private:
    int value;
};