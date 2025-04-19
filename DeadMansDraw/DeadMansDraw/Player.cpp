/*
	The player stores their totalScore and name. They also are responsible for playing cards, checking the play area, banking cards and printing the play area.
*/

#include "Player.h"
#include "Bank.h"
#include "PlayArea.h"
#include <iostream>


Player::Player() {
	std::string names[] = { "Sam", "Jen", "Billy", "Bob", "Sally", "Joe", "Sue","Sasha", "Tina", "Marge" };
	playerName = names[rand() % 10];
	totalScore = 0;
}

void Player::setGame(Game* g) {
	game = g;
}

std::string Player::printBank() {
	return bank.printBank();
}

void Player::playCard(std::unique_ptr<Card> card) {
	playArea.play(std::move(card));
}

std::string Player::printPlayArea() {
	return playArea.toString();
}

void Player::bankCards() {
	//move the cards from playArea to bank calling each ability along the way.
	for (size_t i = 0; i < playArea.playedCards.size(); ++i) {
		Card* currentCard = playArea.playedCards[i].get();
		
		currentCard->willAddToBank(*game);

		bank.bankedCards.push_back(move(playArea.playedCards[i]));

		playArea.playedCards.clear();
	}
}