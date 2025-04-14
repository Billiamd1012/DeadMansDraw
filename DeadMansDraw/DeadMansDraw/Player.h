#pragma once

/*
	The player object interacts with the play area and bank by playing or banking cards.
	They store their total score and name, and can also print their current status to help the game with displaying scores.
*/
#include "Card.h"
#include "PlayArea.h"
#include "Bank.h"

class Player {
public:
	int totalScore;
	std::string playerName;
	
	Player();
	void playCard(Card& card);
	void checkPlayArea();
	void bankCards();
	void printPlayArea();
private:
	Bank bank;
	PlayArea playArea;
};