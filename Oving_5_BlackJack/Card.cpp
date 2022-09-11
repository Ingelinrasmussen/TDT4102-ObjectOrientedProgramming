#include "std_lib_facilities.h"
#include "Card.h"
#include "CardDeck.h"
#include "BlackJack.h"

string suitToString(Suit s){

    map<Suit, string> suitName = { 
        {Suit::clubs, "Clubs"},
        {Suit::diamonds, "Diamonds"},
        {Suit::hearts, "Hearts"},
        {Suit::spades, "Spades"} 
    };
    return suitName[s];
}

string rankToString(Rank r){

    map<Rank, string> rankName = { 
        {Rank::two, "Two"},
        {Rank::three, "Three"},
        {Rank::four, "Four"},
        {Rank::five, "Five"}, 
        {Rank::six, "Six"}, 
        {Rank::seven, "Seven"},
        {Rank::eight, "Eight"},
        {Rank::nine, "Nine"},
        {Rank::ten, "Ten"},
        {Rank::jack, "Jack"}, 
        {Rank::queen, "Queen"}, 
        {Rank::king, "King"},
        {Rank::ace, "Ace"} 
    };
    return rankName[r];
}

Card::Card(Suit suit, Rank rank): s{suit}, r{rank} { // Initialiseringsliste
    s = suit;
    r = rank;
}
 
string Card::getSuit(Suit s){
    return suitToString(s);
}

string Card::getRank(Rank r){
    return rankToString(r);
}

string Card::toString(){
	return rankToString(Card::r) + " of " + suitToString(Card::s);
}

string Card::toStringShort(){
    char suiting = (suitToString(Card::s)).at(0);
    string ranking = to_string(int(Card::r));
    return suiting + ranking;
}

int Card::rankVal(){
	return int(r);
}