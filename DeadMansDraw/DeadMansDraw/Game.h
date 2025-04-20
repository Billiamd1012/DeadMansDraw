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
#include "Discard.h"


class Game {
public:
	int currentTurn = 1;
	Player* currentPlayer;
	Player* otherPlayer;
	Deck deck;
	void startGame();
	void endGame();
	void shuffleDeck();
private:
	Discard discardPile;
	void discardCards();
	std::unique_ptr<Card> nextCard;
	bool drawingCard = true;
	bool playing = true;
	Player player1;
	Player player2;
	void drawNextCard();
};