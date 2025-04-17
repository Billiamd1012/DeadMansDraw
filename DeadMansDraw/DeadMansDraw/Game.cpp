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

		drawNextCard();

		std::string nextCardInput;
		while (drawingCard) {
			std::cout << "Draw again? (y/n): ";
			std::cin >> nextCardInput;

			if (nextCardInput == "y") {
				//draw another card
				drawNextCard();
			}
			else if (nextCardInput == "n") {
				//end player turn
				drawingCard = false;
			}
			else {
				std::cout << "Try typing a lowercase y to represent yes or n to represent no";
			}
		}

		//iterate turn counter and switch players
		currentTurn += 1;
		if (currentTurn % 2 == 0) {
			currentPlayer = &player2;
		}
		else {
			currentPlayer = &player1;
		}
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

void Game::drawNextCard() {
	//draw first card
	nextCard = deck.getCard();

	if (nextCard == nullptr) {
		std::cout << "No more cards to draw.\n";
		endGame();
	}

	else {
		std::cout << currentPlayer->playerName << " draws a " << nextCard->toString(true) << "\n";

		//play first card
		currentPlayer->playCard(std::move(nextCard));
		std::cout << currentPlayer->playerName << "'s Play Area: \n";
		std::cout << currentPlayer->printPlayArea();
	}
}
