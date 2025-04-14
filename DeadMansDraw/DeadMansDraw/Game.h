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
class Game {
public:
	Game();
	void startGame();
	void endGame();
	void shuffleDeck();
private:
	void createDeck();
};