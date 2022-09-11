#include "std_lib_facilities.h"
#pragma once

enum class Suit { clubs, diamonds, hearts, spades };

enum class Rank { two = 2, three, four, five, six, seven, eight, nine, ten, jack, queen, king, ace };

string suitToString(Suit s);

string rankToString(Rank r);

class Card {
private:
    Suit s; // Medlemsvariabel
    Rank r; // Medlemsvariabel
public:
    Card(Suit suit, Rank rank);// Konstruktør
    string getSuit(Suit suit);// Medlemsfunksjon
    string getRank(Rank rank);
    string toString();
    string toStringShort();
    int rankVal();
};
