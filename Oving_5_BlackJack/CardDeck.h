#include "std_lib_facilities.h"
#pragma once

class CardDeck {
private:
    vector<Card>cards; // Medlemsvariabel
    void swap(int a, int b);
public:
    CardDeck(); // Konstruktør
    void print();
    void printShort();
    void shuffle();
    Card drawCard();
};
