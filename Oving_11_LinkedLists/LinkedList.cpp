#include "LinkedList.h"

namespace LinkedList {
std::ostream & operator<<(std::ostream & os, const Node& node) 
{
    return os << node.getValue();
}

Node* LinkedList::insert(Node* pos, const std::string& value) 
{
    assert(pos); 

    if (pos == begin()) 
    { 
        head = std::make_unique<Node>(value, std::move(head), nullptr); 
        pos->prev = begin(); 
    } else {
        auto prevNode = pos->prev; //Find the previous node
        prevNode->next = std::make_unique<Node>(value, std::move(prevNode->next), prevNode); //Make the previous node point to (and own) the new node
        pos->prev = prevNode->getNext(); //Make the given node point back to the new node
    }
    return pos->prev; //Returns a pointer to the new node
}

Node* LinkedList::find(const std::string& value)
{
    for (Node* n = begin(); n!= end(); n->getNext())
    {
        if (n->value == value)
        {
            return n;
        }

    }
    return begin(); //Node points to the first node
}

//The remove function takes a pointer to a node, and removes the node from the list. The
//function returns a pointer to the element after the removed node.
Node* LinkedList::remove(Node* pos)
{
    assert(pos); //Makes sure pos isn't nullptr
    assert(pos != end()); //It's illegal to remove the last node, since it's a "dummy node"
    if (pos == begin()) 
    {
        head = std::move(pos->next); //Makes head point to the next node
        head->prev = nullptr; //The new head doesn't have a previous node
        //Returns a pointer to the node after the deleted node, which is the new head in this case
        return begin();
    }
    auto n = pos->getNext();
    //Makes the node after pos point to the node before pos
    pos->next->prev = pos->prev;
    //Makes the node before pos point to (and own) the node after pos
    pos->prev->next = std::move(pos->next);
    //Returns the node after the deleted node
    return n;
}

// The remove function takes a string and removes the first node which contains the value.
void LinkedList::remove(const std::string& value)
{
    Node* n = find(value);
    remove(n);
}

// write a string representation of the list to the ostream
std::ostream & operator<<(std::ostream & os, const LinkedList& list)
{
    auto n = list.begin();
    os << "[" << *n;
    n = n->getNext();
    while (n != list.end()) 
    {
        os << ", " << *n;
        n = n->getNext();
    }
    os << "]";
    return os;
}

/*
Oppgave 3 b) (teorispørsmål):

1) I en lenket liste kan man sette inn og fjerne elementer lett,
men hvis man skal finne et element må man iterere gjennom hele listen, noe som er sakte.
I en vektor er det raskt å finne et element, men det krever tid å sette inn et nytt element. 
Hvis man kommer til å sette inn og fjerne mange elementer er lenkede lister mer effektive enn vektorer.

2) Det er mye enklere å lage Stack og quees fordi der legger man til og fjerner mange ting.


*/
}
