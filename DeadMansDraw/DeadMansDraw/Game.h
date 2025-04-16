#pragma once

/*
	The game class is responsible for:
	- starting a game
	- ending a game
	- initalising the deck
	- calling the deck to shuffle itself
	- initalising the players
	- storing the currentTurn
*/
#include "Deck.h"
#include "Player.h"

class Game {
public:
	int currentTurn = 1;
	Player* currentPlayer;
	void startGame();
	void endGame();
	void shuffleDeck();
private:
	std::unique_ptr<Card> nextCard;
	bool playing = true;
	Player player1;
	Player player2;
	Deck deck;
};