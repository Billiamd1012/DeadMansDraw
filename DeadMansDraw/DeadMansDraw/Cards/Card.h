#pragma once

/*
	Card is an abstract class that is in charge of performing the suite specific actions, storing type and playing itself.
*/

#include <string>
#include <memory>
#include "Suit.h"
#include <iostream>
#include <algorithm>

class Game;
class Player;

class Card {
public:
	virtual void play(const Game& game, Player& player) = 0;
	virtual Suit type() = 0;
	virtual std::string toString(bool verbose) const = 0;
	virtual void willAddToBank(const Game& game) = 0;
	virtual int getValue() = 0;
private:
	int value = 0;
protected:
	Suit suit = Suit::None;
};