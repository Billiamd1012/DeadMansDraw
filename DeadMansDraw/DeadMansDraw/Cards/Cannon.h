#pragma once

/*
	Cannon is a card that has the ability to discard the top card (i.e. the highest value) of any suit from
	the other player’s Bank to the Discard Pile. With point values 2,3,4,5,6,7
*/

#include "Card.h"
#include "Suit.h"

class Cannon : public Card {
public:
    Cannon(int value);
    Suit type();
    std::string toString() const override;
    void willAddToBank(const Game& game);
    int getValue();
    void play(const Game& _game, Player& player);
private:
    int value;
};