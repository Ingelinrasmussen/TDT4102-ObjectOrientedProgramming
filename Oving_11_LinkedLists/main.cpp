#include "std_lib_facilities.h"
#include "iterators.h"
#include "Person.h"
#include "Template.h"
#include <string>
#include <list>
#include <ostream>
#include "TemplateLL.h"

int main()
{
	int choice;
	bool on = true;
	while (on != false){
		cout << "\n1 - Vector iterator\n";
		cout << "2 - Set iterator\n";
		cout << "3 - Persons in alphabetical order\n";
		cout << "4 - Templates\n";
		cout << "5 - Exit\n";
		cout << "Enter your choice: ";
		cin >> choice;

		switch (choice){
			case 1:
			{
				iterator_v();
				break;
			}

			case 2:
			{
				iterator_s();
				break;
			}

			case 3:
			{
				Person p {"Ingelin", "Rasmussen"};
				p.printPersons();
				break;
			}

			case 4:
			{
				int a = 1;
				int b = 2;
				int c = maximum(a, b);
				cout << "\nMaximum of 1 and 2:\n";
				cout << c << "\n";
				// c er nå 2.
				double d = 2.4;
				double e = 3.2;
				double f = maximum(d,e);
				cout << "\nMaximum of 2.4 and 3.2:\n";
				cout << f << "\n";
				srand(static_cast<unsigned int>(time(nullptr)));
				std::vector<int> v {1, 2, 3, 4, 5, 6, 7};
				shuffle(v); 	
				cout << "\nShuffeling vector {1, 2, 3, 4, 5, 6, 7}:\n";
				for (auto i : v)
				{
					cout << i << " ";
				}	
				cout << "\n";
				cout << "\nShuffeling vector {'one', 'two', 'three', 'four'}:\n";
				vector<string> h{"one", "two", "three", "four"};
				shuffle(h);
				for (const auto& x : h){
					cout << x << " ";
				}
				cout << "\n";
				break;
			}

			case 5:
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


