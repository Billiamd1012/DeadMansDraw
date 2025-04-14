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
	
	std::cout << "Game created \n";
}

void Game::startGame() {
	std::cout << "Game started!\n";
}


void Game::endGame() {
	std::cout << "Game ended!\n";
}

void Game::shuffleDeck() {
	std::cout << "Deck shuffled\n";
}