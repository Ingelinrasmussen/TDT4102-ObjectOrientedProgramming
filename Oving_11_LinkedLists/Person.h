#include <string>
#include <ostream>
#include <list>

class Person
{
private:
    std::string fName;
    std::string lName;

public:
    Person(const std::string firstname, const std::string lastname);
    std::string getFirstName() const;
    std::string getLastName() const;
    void setFirstName(std::string newFirstName);
    void setLastName(std::string newLastName);
    void insertOrdered(std::list<Person> &l, const Person& p);
    void printPersons();
    bool operator <(const Person& p) const;
};

std::ostream& operator<<(std::ostream& os, const Person& p);
