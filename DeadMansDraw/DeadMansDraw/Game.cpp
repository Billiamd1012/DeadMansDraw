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
	player1.setGame(this, &discardPile);
	player2.setGame(this, &discardPile);

	currentPlayer = &player1;
	otherPlayer = &player2;
	std::cout << "Starting Dead Man's Draw++!\n";
	while (playing) {
		int round = (currentTurn+1)/2;
		std::cout << "--- Round " << round << ", Turn "<< currentTurn << " ---\n";
		std::cout << currentPlayer->playerName << "'s turn: \n";

		//print bank
		std::cout << currentPlayer->playerName << "'s Bank: \n";
		std::cout << currentPlayer->printBank();

		drawNextCard();
		drawingCard = true;
		std::string nextCardInput;
		while (drawingCard) {
			//check if play area is busted
			if (currentPlayer->checkPlayArea()) {
				discardCards();
				drawingCard = false;
				break;
			}

			//if not then ask the user if they want to draw again
			else {
				std::cout << "Draw again? (y/n): ";
				std::cin >> nextCardInput;

				if (nextCardInput == "y") {
					//draw another card
					drawNextCard();
				}
				else if (nextCardInput == "n") {
					//end player turn
					currentPlayer->bankCards();
					drawingCard = false;
				}
				else {
					std::cout << "Try typing a lowercase y to represent yes or n to represent no";
				}
			}
		}


		//iterate turn counter and switch players
		currentTurn += 1;
		if (currentTurn % 2 == 0) {
			currentPlayer = &player2;
			otherPlayer = &player1;
		}
		else {
			otherPlayer = &player2;
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
		return;
	}
	else if (currentPlayer->checkPlayArea()) {
		discardCards();
		drawingCard = false;
	}
	else {
		std::cout << currentPlayer->playerName << " draws a " << nextCard->toString(true) << "\n";

		//play first card
		currentPlayer->playCard(std::move(nextCard));
		std::cout << currentPlayer->playerName << "'s Play Area: \n";
		std::cout << currentPlayer->printPlayArea();
	}
}

void Game::discardCards() {
	//for each card in current player play area move to the discard pile 
	std::cout << "BUST! " << currentPlayer->playerName << " loses all cards in play area.\n";
	currentPlayer->discardPlay();
}
