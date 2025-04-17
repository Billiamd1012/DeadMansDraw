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

std::string Player::printBank() {
	return "| Score: 0\n";
}

void Player::playCard(std::unique_ptr<Card> card) {
	playArea.play(std::move(card));
}

std::string Player::printPlayArea() {
	return playArea.toString();
}