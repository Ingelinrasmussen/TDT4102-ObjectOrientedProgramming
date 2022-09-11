#include <string>
#include <list>
#include <ostream>
#include <iostream>
#include "Person.h"

Person::Person(const std::string firstname, const std::string lastname):
fName{firstname}, lName{lastname}
{}

std::string Person::getFirstName() const
{
    return fName;
}

void Person::setFirstName(std::string newFirstName)
{
    fName = newFirstName;
}

std::string Person::getLastName() const
{
    return lName;
}

void Person::setLastName(std::string newLastName)
{
    lName = newLastName;
}

void Person::insertOrdered(std::list<Person> &l, const Person& p)
{
    for (std::list<Person>::iterator i = l.begin(); i != l.end(); i++)
    {
        if (p < *i)
        {
            l.insert(i, p);
            return;
        }
    }
    l.push_back(p);
}

void Person::printPersons()
{
    std::list<Person> l;
    Person p1{"Ingelin", "Rasmussen"};
    Person p2{"Masa", "Paunov"};
    Person p3{"Emil", "Soleim"};
    Person p4{"Frida", "Hundhammer"};
    Person p5{"Thijs", "Mol"};
    Person p6{"Linn", "Dimmen"};
    insertOrdered(l, p1);
    insertOrdered(l, p2);
    insertOrdered(l, p3);
    insertOrdered(l, p4);
    insertOrdered(l, p5);
    insertOrdered(l, p6);

    for (const Person p : l)
    {
        std::cout << p << "\n";
    }
}

std::ostream& operator<<(std::ostream& os, const Person& p)
{
    os << "\n" << p.getLastName() << ", " << p.getFirstName(); 
    return os;
}

bool Person::operator <(const Person& p) const
{
    return (lName + fName) < (p.lName + p.fName);
}