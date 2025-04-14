/*
	The game class is responsible for:
	- starting a game
	- ending a game
	- initalising the deck
	- calling the deck to shuffle itself
	- initalising the players
	- storing the currentTurn
*/

#include "Game.h";
#include <iostream>;

using namespace std;

Game::Game() {
	Deck deck;
	std::cout << "Game created \n";
}

//Initalises the deck and player
void Game::startGame() {
	std::cout << "Game started!\n";
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
