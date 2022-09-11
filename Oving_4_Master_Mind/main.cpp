#include "std_lib_facilities.h"
#include "utilities.h"
#include "tests.h"
#include "mastermind.h"
#include "masterVisual.h"
#include "Graph.h"
#include "Simple_window.h"
using namespace Graph_lib;

/*Oppgave 1a)

V0 får verdien 25 fordi 2*10 iterasjoner = 20 og + v0 gir 25. 

Oppgave 1e)

Passby-value gjør at tall1 og tall2 forblir 10 og 21.
Passby-reference gjør at tallene endres til det som er bestemt i funksjonen swapNumbers
Passby-const-reference gjør at man ikke kan endre verdien, så det går ikke. Den forblir den samme uansett. 

*/

int main()
{	
	cout << "\nDel 1\n";
	testCallByValue();
	testCallByReference();

	int tall1 = 10;
	int tall2 = 21;
	cout << "\n" << tall1 << " " << tall2 << "\n";
	swapNumbers(tall1, tall2);
	cout << "\n" << tall1 << " " << tall2 << "\n";

	Student s1{"Ingelin", "Elsys", 20};
	Student s2{"Maria", "IKT", 20};
	Student s3{"Ingeborg", "Lærer", 21};

	printStudent(s1);

	isInProgram(s1, "Elsys");
	isInProgram(s2, "Elsys");

	testString();

	cout << readInputToString(4, 'A', 'B') << "\n";

	cout << "\nTester antall n-er i ordet heisann: \n";
	cout << countChar("heisann", 'n') << "\n ";

	cout << "\nDel 2: Mastermind\n";

	//addGuess(mwin, "ABBA", 4, 'A', 0);

	playMastermind();

	keep_window_open();
}

