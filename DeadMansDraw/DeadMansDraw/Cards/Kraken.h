#pragma once

/*
    Kraken is a card that must draw and play three cards consecutively. With point values 2,3,4,5,6,7
*/

#include "Card.h"
#include "Suit.h"

class Kraken : public Card {
public:
    Kraken(int value);
    Suit type();
    std::string toString(bool verbose) const override;
    void willAddToBank(const Game& game);
    int getValue();
    void play(const Game& _game, Player& player);
private:
    int value;
};