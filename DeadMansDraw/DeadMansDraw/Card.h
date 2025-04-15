#pragma once

/*
	Card is an abstract class that is in charge of performing the suite specific actions, storing type and playing itself.
*/

#include <string>

class Game;
class Player;

//Enum to contain all of the different card type
enum Suit {
	Cannon,
	Chest,
	Key,
	Sword,
	Hook,
	Oracle,
	Map,
	Mermaid,
	Kraken
};

class Card {
public:
	virtual ~Card();
	virtual void play(const Game& game, Player& player) = 0;
	virtual Suit Type() = 0;
	virtual std::string toString() const = 0;
	virtual void willAddToBank(const Game& game) = 0;
private:
	Suit suit;
};