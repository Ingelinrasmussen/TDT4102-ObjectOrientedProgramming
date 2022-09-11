#include "Card.h"
#include "CardDeck.h"
#include "std_lib_facilities.h"
#include "utilities.h"
#include "BlackJack.h"

CardDeck::CardDeck(){

    for (int s{0}; s < 4; s++){
        for (int r{2}; r < 13 + 2; r++){
            cards.push_back(Card(Suit(s), Rank(r)));
        }
    }
}

void CardDeck::swap(int a, int b){
    Card c = cards[a];
    cards[a] = cards[b];
    cards[b] = c;
}

void CardDeck::print(){

    for (Card element : cards){
        cout << element.toString() << "\n";
    }
}

void CardDeck::printShort(){

    for (Card element : cards){
        cout << element.toStringShort() << "\n";
    }
}

void CardDeck::shuffle(){
    srand(static_cast<unsigned int>(time(nullptr)));
	for (int i = 0; i < 100; ++i){
		swap(randomWithLimits(0, cards.size() - 1), randomWithLimits(0, cards.size() - 1));
	}
}

Card CardDeck::drawCard(){
    int s = cards.size();
    Card upperCard = cards[s-1];
    cards.erase (cards.begin()+(s-1));
    return upperCard;
}