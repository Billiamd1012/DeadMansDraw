/*
	The deck holds at most 54 cards.
	It manages these cards and passes them to the game whenever it is asked to.
*/

#include "Deck.h"
#include "Cards/Cannon.h"
#include "Cards/Chest.h"
#include "Cards/Key.h"
#include "Cards/Sword.h"
#include "Cards/Hook.h"
#include "Cards/Oracle.h"
#include "Cards/Map.h"
#include "Cards/Mermaid.h"
#include "Cards/Kraken.h"

//Create all the cards
Deck::Deck(){
	createCards();
	shuffleCards();
}

//create all of the cards in the deck
void Deck::createCards() {
	//loop through each suit and create 6 cards for each
	CardCollection cards;
	//for cannon
	for (int i = 2; i <= 7; i++) {
		cards.push_back(std::make_unique<Cannon>(i));
	}

	//chest
	for (int i = 2; i <= 7; i++) {
		cards.push_back(std::make_unique<Chest>(i));
	}
	//key
	for (int i = 2; i <= 7; i++) {
		cards.push_back(std::make_unique<Key>(i));
	}
	//sword
	for (int i = 2; i <= 7; i++) {
		cards.push_back(std::make_unique<Sword>(i));
	}
	//hook
	for (int i = 2; i <= 7; i++) {
		cards.push_back(std::make_unique<Hook>(i));
	}
	//oracle
	for (int i = 2; i <= 7; i++) {
		cards.push_back(std::make_unique<Oracle>(i));
	}
	//map
	for (int i = 2; i <= 7; i++) {
		cards.push_back(std::make_unique<Map>(i));
	}
	//mermaid
	for (int i = 4; i <= 9; i++) {
		cards.push_back(std::make_unique<Mermaid>(i));
	}
	//kraken
	for (int i = 2; i <= 7; i++) {
		cards.push_back(std::make_unique<Kraken>(i));
	}

}

void Deck::shuffleCards() {

}

void Deck::getCard() {

}