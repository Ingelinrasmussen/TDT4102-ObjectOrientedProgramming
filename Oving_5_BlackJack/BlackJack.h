#include "std_lib_facilities.h"
#pragma once

class BlackJack {
private:
    vector<Card>dealerCards; // Medlemsvariabel
    vector<Card>playerCards;
    CardDeck cards;
public:
    BlackJack();// Konstruktør
    void playBlackJack();
    int calculateSum(vector<Card>cards);
};
