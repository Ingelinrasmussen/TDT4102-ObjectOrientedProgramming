#pragma once

#include <memory>
#include <ostream>
#include <string>
#include <sstream>
#include <cassert>
#include <iostream>

namespace TemplateLL { //We need to forward declare this, so that it is known when declaring it as a friend 

template<typename T>
class LinkedList;

template<typename T>
class Node {
private:
    const T value;    // The data held by the LinkedList
    std::unique_ptr<Node<T>> next; // unique_ptr to the next node
    Node<T>* prev;                 // raw (non-owning) ptr to the previous node
public:
    Node(): value(), next(nullptr), prev(nullptr) {}
    // construct a node with string value, a unique_ptr to the next node, and a pointer to the previous node
    Node(const T& value, std::unique_ptr<Node<T>> next, Node<T>* prev)
        : value(value)
        , next(std::move(next))
        , prev(prev)
    {}
    // We can use the default constructor, since unique_ptr takes care of deleting memory
    ~Node() = default;
    // return the value of the node
    T getValue() const { return value; }

    // return a raw (non-owning) pointer to the next node
    Node<T>* getNext() const { return next.get(); }
    // return a raw (non-owning) pointer to the previous node
    Node<T>* getPrev() const { return prev; }

    // write the value of the node to the ostream
    friend std::ostream & operator<<(std::ostream & os, const Node<T> & node) {
      return os << node.getValue();
    }

    friend class LinkedList<T>;
};

template<typename T>
class LinkedList {
private:
    std::unique_ptr<Node<T>> head;
    Node<T>* const tail;
public:
    LinkedList(): 
    head(std::make_unique<Node<T>>()), tail(head.get()){}
    ~LinkedList() = default;
    bool isEmpty() const { return !head->next; }
    Node<T>* begin() const { return head.get(); }
    Node<T>* end() const { return tail; }
    Node<T>* insert(Node<T> *pos, const T& value);
    Node<T>* find(const T& value);
    Node<T>* remove(Node<T>* pos);
    void remove(const T& value);
    friend std::ostream & operator<<(std::ostream & os, const LinkedList<T>& list) {
      auto x = list.begin();
      os << "[" << *x;
      x = x->getNext();
      while (x != list.end()) {
          os << " " << *x;
          x = x->getNext();
      }
      os << "]";
      return os;
    }
};

template<typename T>
Node<T>* LinkedList<T>::insert(Node<T> *pos, const T& value) {
    // make sure pos isn't nullptr (for debugging purposes)
    assert(pos);
    if (pos == begin()) { // if pos is the first node
        // create a new head node, point to the old head node
        head = std::make_unique<Node<T>>(value, std::move(head), nullptr);
        // and make the old head node point back to the new one
        pos->prev = begin();
    } else {
        // find the previous node
        auto prevNode = pos->prev;
        // make the previous node point to (and own) the new node
        prevNode->next = std::make_unique<Node<T>>(value, std::move(prevNode->next), prevNode);
        // make the given node point back to the new node
        pos->prev = prevNode->getNext();
    }
    return pos->prev;
}

template<typename T>
Node<T>* LinkedList<T>::find(const T& value) {
    auto node = begin();
    while(node != end() && node->value != value) {
        node = node->getNext();
    }
    return node;
}

template<typename T>
Node<T>* LinkedList<T>::remove(Node<T>* pos) {
    assert(pos);
    assert(pos != end());
    if (pos == begin()) {
        head = std::move(pos->next);
        head->prev = nullptr;
        return begin();
    }
    auto ret = pos->getNext();
    pos->next->prev = pos->prev;
    pos->prev->next = std::move(pos->next);
    return ret;
}

template<typename T>
void LinkedList<T>::remove(const T& value) {
    auto node = find(value);
    remove(node);
}

} 

