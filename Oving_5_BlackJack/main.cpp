#include "std_lib_facilities.h"
#include "Card.h"
#include "CardDeck.h"
#include "BlackJack.h"

/*OPPGAVE 1e) Fordeler med å bruke symboler fremfor int og string er at de kan slås sammen og printes samtidig,
siden paramteren er lik så kan de foreksempel inngå i samme for løkke, eller vektor. I tillegg tar det mindre plass på PC
siden begge er char. */

int main()
{	
	/*
	cout <<"\nTester at funksjonen fungerer: \n";
	Suit s = Suit::hearts;
	Rank r = Rank::king;
	string rank = rankToString(r);
	string suit = suitToString(s);
	cout << "Rank: " << rank << " Suit: " << suit << '\n';

	Card c1{s, r}; // Konstruerer ett objekt av klassen Card
	cout << c1.getRank(r) << "\n"; // Kaller medlemsfunksjonen på instansen
	cout << c1.getSuit(s) << "\n";

	Card c2{Suit::spades, Rank::ace};
	cout << c2.toString() << '\n';
	cout << c2.toStringShort() << '\n';

	CardDeck cd = CardDeck();
	cd.print();
	cd.printShort();
	cd.shuffle();
	cd.printShort();
	Card uppercard = cd.drawCard();
	cout <<"\nDu trakk kortet: \n";
	cout << uppercard.toString() << "\n";
	cd.print(); */

	//Play BlackJack

	BlackJack();

	keep_window_open();
}

