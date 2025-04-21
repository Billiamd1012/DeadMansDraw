#pragma once

/*
	The player object interacts with the play area and bank by playing or banking cards.
	They store their total score and name, and can also print their current status to help the game with displaying scores.
*/
#include "Cards/Card.h"
#include "PlayArea.h"
#include "Bank.h"
#include <string>

class Game;
class Discard;


class Player {
public:
	int totalScore;
	std::string playerName;
	
	Player();
	void setGame(Game* g, Discard* discard);
	void playCard(std::unique_ptr<Card> card);
	bool checkPlayArea();
	void bankCards();
	std::string printPlayArea();
	std::string printBank();
	void discardPlay();
	void discardCard(std::unique_ptr<Card> card);
	Bank* getBank();
	PlayArea* getPlayArea();
	Discard* getDiscardPile();
	void drawNCards(int n);
private:
	Discard* discard;
	Game* game;
	Bank bank;
	PlayArea playArea;

};