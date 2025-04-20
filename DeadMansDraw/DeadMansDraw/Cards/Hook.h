#pragma once

/*
    Hook is a card that has the ability to play the top card (i.e. the highest value) of any suit from
    your Bank into your play area. You must select one card. With point values 2,3,4,5,6,7
*/

#include "Card.h"
#include "Suit.h"

class Hook : public Card {
public:
    Hook(int value);
    Suit type();
    std::string toString(bool verbose) const override;
    void willAddToBank(const Game& game);
    int getValue();
    void play(const Game& game, Player& player);
private:
    int value;
};