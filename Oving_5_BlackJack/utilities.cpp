#include "std_lib_facilities.h"
#include "utilities.h"
#include "Card.h"
#include "CardDeck.h"


int randomWithLimits(int lower, int upper){

    int randomNumber = rand() % (upper - lower + 1) + lower;
    return randomNumber;
}