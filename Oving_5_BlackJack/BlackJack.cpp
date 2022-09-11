#include "std_lib_facilities.h"
#include "Card.h"
#include "CardDeck.h"
#include "utilities.h"
#include "BlackJack.h"

BlackJack::BlackJack(){ // Initialiseringsliste

    cards = CardDeck();
	cards.shuffle();

    for (int i = 0; i < 2; ++i){
        playerCards.push_back(cards.drawCard());
        dealerCards.push_back(cards.drawCard());
    }
    playBlackJack();
}

int BlackJack::calculateSum(vector<Card>cards){
    int sum = 0;
    int ace = 0;
    for (Card c: cards){
	    int value = c.rankVal();
        if (value <= 13 and value >= 11){
            value = 10;
        }
        else if (value == 14){
            ace += 1;
            value = 0;
        }
        sum += value;   
    }

    for (int i = 0; i < ace; ++i){
        if (sum + 11 <= 21){
            sum += 11;
        }
        else{
            sum += 1;
        }
    }
    return sum;
}

void BlackJack::playBlackJack(){

    //Players turn
    cout << "\nWelcome to BlackJack!\nYour cards are: \n";

    for (Card el : playerCards){
        cout << el.toString() << "\n";
    }
    int sum = calculateSum(playerCards);
    cout << "Your sum is " << sum << "\n";
    int sumD = calculateSum(dealerCards);
    bool outcome = true;

    if (sum == 21){
        cout << "\nYou got Blackjack! You won!\n";
    }

    else{
        Card visibleCard = dealerCards[0];
        cout << "\nDealers visible card is: " << visibleCard.toString() << "\n";

        cout << "\nWould you like to get another card? (yes/no) ";
        string answer;
        cin >> answer;

        if (answer == "yes"){

            do{
                playerCards.push_back(cards.drawCard());
                int s = playerCards.size();
                cout << "\nYour new card is " << playerCards[s-1].toString() << "\n";

                cout << "\nYour hand is now: \n";

                for (Card el : playerCards){
                    cout << el.toString() << "\n";
                }

                sum = calculateSum(playerCards);
                cout << "New sum is: " << sum << "\n";

                if (sum > 21){
                    cout << "\nYou lost! You got more than 21.\n";
                    outcome = false;
                    break;
                }
        
                else if (sum == 21){
                    cout << "\nYou got Blackjack! You won!\n";
                    outcome = false;
                    break;
                }

                cout << "\nWould you lke to get another card? (yes/no) ";
                cin >> answer;

            } while (answer == "yes");
        }

        //Dealers turn
        if (sumD < 17){
            do{
                dealerCards.push_back(cards.drawCard());
                sumD = calculateSum(dealerCards);
            } while (sumD < 17);
        }
            
        if (answer == "no" || outcome == true){
            cout << "\nYour score is " << sum << "\n";
            if ((sum > sumD) || (sum <= 21 && sumD > 21)){
                cout << "You won! ";
            }
            else{
                cout << "You lost! ";
            }
        }
    }
    cout << "Dealer got " << sumD << "\n";
    cout << "Thanks for playing!\n";
}
