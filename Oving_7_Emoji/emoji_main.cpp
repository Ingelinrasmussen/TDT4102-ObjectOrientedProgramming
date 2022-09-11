#include "Simple_window.h"
#include "Emoji.h"
#include "std_lib_facilities.h"
#include "classes.h"
#include "Graph.h"

// Size of window and emoji radius
constexpr int xmax = 1000;
constexpr int ymax = 600;
constexpr int emojiRadius = 50;

int main()
{
	using namespace Graph_lib;

	int choice;
	bool on = true;
	while (on != false){
		cout << "\n1 - Oppgave 1 (animals).\n";
		cout << "2 - Oppgave 2 (emojis).\n";
		cout << "3 - Exit.\n";
		cout << "Enter your choice: ";
		cin >> choice;

		switch (choice){
			case 1:
				{
				testAnimal();
				break;
				}

			case 2:
				{
				const Point tl{100, 100};
				const string win_label{"Emoji factory"};
				Simple_window win{tl, xmax, ymax, win_label};

				Vector_ref<Emoji> emoji;
				emoji.push_back(new EmptyFace(Point{100, 100}, emojiRadius));
				emoji.push_back(new SmileyFace(Point{210, 100}, emojiRadius));
				emoji.push_back(new SadFace(Point{320, 100}, emojiRadius));
				emoji.push_back(new AngryFace(Point{100, 210}, emojiRadius));
				emoji.push_back(new WinkingFace(Point{210, 210}, emojiRadius));
				emoji.push_back(new SurprisedFace(Point{320, 210}, emojiRadius));
	
				for (int i=0; i<emoji.size(); i++) {
					emoji[i].attach_to(win);
				}

				win.wait_for_button();
				break;
				}

			case 3:
				{
				cout << "End of Program.\n";
				on = false;
				break;
				}

			default:
				{
				cout << "Not a Valid Choice. \n";
				cout << "Choose again.\n";
				}

			cin >> choice;
			break;
		}
	}
	
	keep_window_open();

}
