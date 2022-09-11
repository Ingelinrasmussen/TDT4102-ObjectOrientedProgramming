#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <algorithm>

void replace_v(std::vector<std::string> &v, const std::string &old, std::string replacement)
{
    for (std::vector<std::string>::iterator i = v.begin(); i != v.end(); i++)
    {
        if (*i == old)
        {
            i = v.erase(i);
            i = v.insert(i, replacement);
        }
    }
}

void iterator_v()
{
    std::vector<std::string> v;
    v.push_back("Dog");
	v.push_back("Cat");
	v.push_back("Cow");
	v.push_back("Rabbit");
    v.push_back("Cat");

    //Printer ut en vector ved bruk at iteratorer
    std::cout << "\nVektor riktig vei:\n";
    for (std::vector<std::string>::iterator i = v.begin(); i != v.end(); i++)
    {
        std::cout << *i << "\n";
    }
    std::cout << "\n";

    //Printer ut vectoren baklengs
    std::cout << "Vektor baklengs:\n";
    for (std::vector<std::string>::reverse_iterator i = v.rbegin(); i != v.rend(); i++)
    {
        std::cout << *i << "\n";
    }
    std::cout << "\n";

    replace_v(v, "Cat", "Dragon");
    std::cout << "Vektor hvor 'Cat' er byttet ut med 'Dragon':\n";
    for (std::vector<std::string>::iterator i = v.begin(); i != v.end(); i++)
    {
        std::cout << *i << "\n";
    }
    std::cout << "\n";
}

void replace_s(std::set<std::string> &s, const std::string &old, std::string replacement)
{
    for (std::set<std::string>::iterator i = s.begin(); i != s.end(); i++)
    {
        if (*i == old)
        {
            i = s.erase(i);
            i = s.insert(i, replacement);
        }
    }
}

void iterator_s()
{
    std::set<std::string> s {};
    s.insert("Hippo");
	s.insert("Dolphin");
	s.insert("Zebra");
	s.insert("Lion");
    s.insert("Dolphin");

    //Printer ut en set-funksjon ved bruk at iteratorer
    std::cout << "\nSet riktig vei:\n";
    for (std::set<std::string>::iterator sit = s.begin(); sit != s.end(); ++sit)
    {
        std::cout << *sit << "\n";
    }
    std::cout << "\n";

    //Printer ut set baklengs
    std::cout << "Set baklengs:\n";
    for (std::set<std::string>::reverse_iterator rit = s.rbegin(); rit != s.rend(); ++rit)
    {
        std::cout << *rit << "\n";
    }
    std::cout << "\n";

    replace_s(s, "Dolphin", "Tiger");
    std::cout << "Set hvor 'Dolphin' er byttet ut med 'Tiger':\n";
    for (std::set<std::string>::iterator sit = s.begin(); sit != s.end(); ++sit)
    {
        std::cout << *sit << "\n";
    }
    std::cout << "\n";
}


