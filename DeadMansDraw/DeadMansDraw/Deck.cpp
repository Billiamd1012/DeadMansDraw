/*
	The deck holds at most 54 cards.
	It manages these cards and passes them to the game whenever it is asked to.
*/

#include "Deck.h"
#include "Cards/Cannon.h"

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

	


}

void Deck::shuffleCards() {

}

void Deck::getCard() {

}