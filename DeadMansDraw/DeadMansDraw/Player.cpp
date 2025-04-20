/*
	The player stores their totalScore and name. They also are responsible for playing cards, checking the play area, banking cards and printing the play area.
*/

#include "Player.h"
#include "Bank.h"
#include "PlayArea.h"
#include <iostream>
#include <vector>
#include "Discard.h"


Player::Player() {
	std::string names[] = { "Sam", "Jen", "Billy", "Bob", "Sally", "Joe", "Sue","Sasha", "Tina", "Marge" };
	playerName = names[rand() % 10];
	totalScore = 0;
}

void Player::setGame(Game* g, Discard* d) {
	game = g;
	discard = d;
}

std::string Player::printBank() {
	return bank.printBank();
}

void Player::playCard(std::unique_ptr<Card> card) {
	Card* currentCard = card.get();
	currentCard->play(*game,*this);
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

	}
	playArea.playedCards.clear();

}

/*
	Checks if there are duplicates suits in the play area
	return
		true (if there are duplicates)
		false (if there are no duplicates)
*/
bool Player::checkPlayArea() {
	//for each card in play area check that the suit hasn't been drawn yet
	std::vector<Suit> playedSuits = std::vector<Suit>();
	for (size_t i = 0; i < playArea.playedCards.size(); ++i) {
		Card* currentCard = playArea.playedCards[i].get();

		//check if suit has already been played
		for (size_t i = 0; i < playedSuits.size(); ++i) {
			if (currentCard->type() == playedSuits[i]) {
				return true;
			}
		}

		//otherwise push the suit to the played suits vector
		playedSuits.push_back(currentCard->type());
	}

	return false;
}

void Player::discardPlay() {
	for (size_t i = 0; i < playArea.playedCards.size(); ++i) {
		discard->addCard(std::move(playArea.playedCards[i]));
	}
	playArea.playedCards.clear();
}

void Player::discardCard(std::unique_ptr<Card> card) {
	discard->addCard(std::move(card));
}

Bank* Player::getBank() {
	return &bank;
}