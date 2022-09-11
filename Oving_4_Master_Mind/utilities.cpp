#include "std_lib_facilities.h"
#include "utilities.h"
#include "tests.h"
#include "mastermind.h"

int incrementByValueNumTimes(int startValue, int increment, int numTimes) { 
	for (int i = 0; i < numTimes; i++){
		startValue += increment;
	}
	return startValue; 
}

void incrementByValueNumTimesRef(int& startValue, int increment, int numTimes){
    for (int i = 0; i < numTimes; i++){
		startValue += increment;
	}
}

void swapNumbers(int& tall1, int& tall2){
	tall1 += 10;
	tall2 -= 1;
}

void printStudent(Student print){
	cout << "\nName: " << print.name << "\n";
    cout <<"Study Program: " << print.studyProgram << "\n";
    cout << "Age: " << print.age << "\n";

}

void isInProgram(Student s, string studie){
	if (s.studyProgram == studie){
		cout << "\nDet er riktig! Personen går på " << studie << "\n";
	}
	else{
		cout << "\nDet er feil! Personen går ikke på " << studie << "\n";
	}
}

string randomizeString(int antall, char start, char slutt){
	string randomLetters = "";
	srand(static_cast<unsigned int>(time(nullptr)));
	for (unsigned int i{0}; i < antall; ++i){
		char randomChar = start + rand()% (slutt - start + 1); 
		randomLetters.push_back(randomChar);
	}
	return randomLetters;
}

string readInputToString(int n, char start, char slutt){
	bool x{true};
	string ordFraBruker;
	while (x){
		int feil = 0;
		int lengde{0};
		cout << "\nSkriv inn et ord med " << n << " karakterer og bokstaver fra " << start << " til " << slutt << ":";
		cin >> ordFraBruker; 
		for (char& c : ordFraBruker){
			c = toupper(c);
			lengde += 1;
	  		if (c < start or c > slutt or isalpha(c) == false){
		  		feil += 1;
				break;
			}
		}
		if (feil > 0){
			cout << "\nDet du skrev ble ikke akseptert, prøv på nytt\n"; 
			continue;
		}
		else if (lengde > n){
			cout << "\nDet du skrev ble ikke akseptert, prøv på nytt\n"; 
			continue;
		}
		if (feil == 0){
			break;
		}
	}
	return ordFraBruker;
}

int countChar(string s, char bokstav){
	int likeBokstaver{0};
	bokstav = tolower(bokstav);
	for (char c : s){
		c = tolower(c);
		if (c == bokstav){
			likeBokstaver += 1;
		}
	}
	return likeBokstaver;
}

