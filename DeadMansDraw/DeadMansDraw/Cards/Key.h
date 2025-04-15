#pragma once

/*
    Chest is a card that has the ability if banked with a Key card, draw as
    many bonus cards from the Discard pile as you moved into
    your Bank. With point values 2,3,4,5,6,7
*/

#include "Card.h"
#include "Suit.h"

class Key : public Card {
public:
    Key(int value);
    Suit type();
    std::string toString() const override;
    void willAddToBank(const Game& game);
    int getValue();
    void play(const Game& _game, Player& player);
private:
    int value;
};