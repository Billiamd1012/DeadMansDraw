#pragma once

/*
    Mermaid is a card that has no ability. With point values 4,5,6,7,8,9
*/

#include "Card.h"
#include "Suit.h"

class Mermaid : public Card {
public:
    Mermaid(int value);
    Suit type();
    std::string toString(bool verbose) const override;
    void willAddToBank(const Game& game);
    int getValue();
    void play(const Game& _game, Player& player);
private:
    int value;
};