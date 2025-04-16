/*
	The game class is responsible for:
	- starting a game
	- ending a game
	- initalising the deck
	- calling the deck to shuffle itself
	- initalising the players
	- storing the currentTurn
*/

#include "Game.h"
#include <iostream>

using namespace std;


//Initalises the deck and player
void Game::startGame() {
	currentPlayer = &player1;
	std::cout << "Starting Dead Man's Draw++!\n";
	while (playing) {
		int round = (currentTurn+1)/2;
		std::cout << "--- Round " << round << ", Turn "<< currentTurn << " ---\n";
		std::cout << currentPlayer->playerName << "'s turn: \n";

		//print bank
		std::cout << currentPlayer->playerName << "'s Bank: \n";
		std::cout << currentPlayer->printBank();

		//draw first card
		nextCard = deck.getCard();
		std::cout << currentPlayer->playerName << " draws a " << nextCard->toString() << "\n";
		currentTurn += 1;
		if (currentTurn > 40) { playing = false; }
	}

}

//Removes the deck and prints results
void Game::endGame() {
	std::cout << "Game ended!\n";
}

//Tells the deck to shuffle itself
void Game::shuffleDeck() {
	deck.shuffleCards();
	std::cout << "Deck shuffled\n";
}
