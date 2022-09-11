#include "mastermind.h"
#include "std_lib_facilities.h"
#include "utilities.h"
#include "tests.h"
#include "masterVisual.h"

int checkCharactersAndPosition(string code, string guess){
    int likPosBok {0};
    for (int i = 0; i < 4; ++i){
        if (code[i] == guess[i]){
            likPosBok += 1;
        }
    }
	return likPosBok;
}

int checkCharacters(string code, string guess){
    int like = checkCharactersAndPosition(code, guess);
    int likBok {0};
    string codeKopi = code;
    for (char c : guess){
        for (char k : codeKopi){
            if (c == k){
                likBok += 1;
                codeKopi.erase(remove(codeKopi.begin(), codeKopi.end(), k), codeKopi.end());
            }
		}
	}
    int likBok1 = likBok - like;
    return likBok1;
}

void playMastermind(){
    MastermindWindow mwin{Point{900, 20}, winW, winH, "Mastermind"};
    int x{1};
    constexpr int size{4};
    constexpr int letters{6};
    string guess;
    char start{'A'};
    char slutt{'A' + (letters - 1)};
    const string code{randomizeString(size, start, slutt)};
    addGuess(mwin, code, size, 'A', 0);

    while (x <= 6){

        if (x > 6){
            cout << "\nDu brukte 10 forsøk, GAME OVER. Ordet var " << code << "\n";
            break;
        }
        cout << "\nForsøk " << x << ":\n";
        string guess{mwin.getInput(size, start, slutt)};
        addGuess(mwin, guess, size, 'A', x);
        
        //string guess{readInputToString(size, start, slutt)};
        
        int likPosBok = 0;
        int likBok = 0;

        likPosBok = checkCharactersAndPosition(code, guess);
        likBok = checkCharacters(code, guess);

        addFeedback(mwin, likPosBok, likBok, size, x);

        if (likPosBok == size){
            cout << "\nDu vant! Ordet var " << code << "\n";
            break;
        }

        cout << "\nDu har " << likBok << " riktige bokstaver.\n";
        cout << "Og " << likPosBok << " som står på riktig posisjon.\n";
        x+=1;

        mwin.redraw();
    }
}

