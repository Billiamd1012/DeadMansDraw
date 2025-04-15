#pragma once

/*
    Sword is a card that has the ability to steal the top card (i.e. the highest value) of any suit from
    the other player’s Bank into your Play Area. You must select
    one card. With point values 2,3,4,5,6,7
*/

#include "Card.h"
#include "Suit.h"

class Sword : public Card {
public:
    Sword(int value);
    Suit type();
    std::string toString() const override;
    void willAddToBank(const Game& game);
    int getValue();
    void play(const Game& _game, Player& player);
private:
    int value;
};