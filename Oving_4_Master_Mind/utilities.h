#include "std_lib_facilities.h"
#pragma once

int incrementByValueNumTimes(int startValue, int increment, int numTimes);
void incrementByValueNumTimesRef(int& startValue, int increment, int numTimes);
void swapNumbers(int& tall1, int& tall2);

struct Student{
	string name;
	string studyProgram;
	int age; 
};

void printStudent(Student print);

void isInProgram(Student s, string studie);

string randomizeString(int antall, char start, char slutt);

string readInputToString(int n, char start, char slutt);

int countChar(string s, char c);