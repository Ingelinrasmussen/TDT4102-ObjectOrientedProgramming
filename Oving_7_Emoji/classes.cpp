#include "classes.h"
#include "std_lib_facilities.h"
#include "GUI.h"
#include "Graph.h"

string Animal::toString(){
    return "Animal: " + name + ", " + to_string(age);
}

Animal::Animal(string n, int a): name{n}, age{a} {}

Cat::Cat(string n, int a): Animal(n, a){}

string Cat::toString(){
    return "Cat: " + name + ", " + to_string(age);
}

Dog::Dog(string n, int a): Animal(n, a){}

string Dog::toString(){
    return "Dog: " + name + ", " + to_string(age);
}

void testAnimal(){
    Dog a{"Husky", 4};
    Cat c{"Sphinx", 3};
    Dog d{"Golden Retriver", 11};

    using namespace Graph_lib;

    Vector_ref<Animal> animals;
    animals.push_back(a);
    animals.push_back(c);
    animals.push_back(d);

	for (int i=0; i<animals.size(); i++) {
		cout << animals[i].toString() << "\n";
	}
    //cout << a.toString() << "\n";
    //cout << c.toString() << "\n";
    //cout << d.toString() << "\n";
}
