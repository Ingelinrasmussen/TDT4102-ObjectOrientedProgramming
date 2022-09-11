#include "std_lib_facilities.h"
#include "utilities.h"
#include "tests.h"
#include "mastermind.h"

void testCallByValue() { 
	int v0 = 5;
	int increment = 2;
	int iterations = 10;
	int result = incrementByValueNumTimes(v0, increment, iterations); 
	cout << "v0: " << v0
		<< " increment: " << increment
		<< " iterations: " << iterations
		<< " result: " << result << endl;
}

void testCallByReference() {
    int v0 = 5;
    cout << "v0: " << v0;
	int increment = 2;
	int iterations = 10;
	incrementByValueNumTimesRef(v0, increment, iterations); 
	cout << " increment: " << increment
		<< " iterations: " << iterations
		<< " result: " << v0 << endl;
}

void testString(){
	string grades;
	vector<int>gradeCount;
	int karakter {5};
	grades = randomizeString(8, 'A', 'F');
	for(char i = 'A'; i < 'F'; i++){
		int antall = countChar(grades, i) * karakter;
		gradeCount.push_back(antall);
		karakter -= 1;
	}
	int sum{0};
	for (int i : gradeCount){
		sum += i;
	}
	double gjennomsnitt = sum/8.0;
	cout << grades << endl; 
	cout << "Gjennomsnittskarakter: " << gjennomsnitt << endl;
}