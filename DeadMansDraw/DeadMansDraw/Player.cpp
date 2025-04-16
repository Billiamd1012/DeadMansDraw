/*
	The player stores their totalScore and name. They also are responsible for playing cards, checking the play area, banking cards and printing the play area.
*/

#include "Player.h"
#include "Bank.h"
#include "PlayArea.h"
#include <iostream>


Player::Player() {
	std::string names[] = { "Sam", "Billy", "Jen", "Bob", "Sally", "Joe", "Sue","Sasha", "Tina", "Marge" };
	playerName = names[rand() % 10];

	totalScore = 0;
}

void Player::printBank() {
	std::cout << "| Score: 0\n";
}

void Player::playCard(std::unique_ptr<Card> card) {
	playArea.play(std::move(card));
}