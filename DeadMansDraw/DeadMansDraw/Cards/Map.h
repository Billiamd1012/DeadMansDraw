#pragma once

/*
    Map is a card that has the ability to draw 3 cards from discard pile. You must play one of the
    cards drawn into your play area. With point values 2,3,4,5,6,7
*/

#include "Card.h"
#include "Suit.h"

class Map : public Card {
public:
    Map(int value);
    Suit type();
    std::string toString() const override;
    void willAddToBank(const Game& game);
    int getValue();
    void play(const Game& _game, Player& player);
private:
    int value;
};