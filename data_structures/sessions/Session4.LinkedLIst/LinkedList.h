//
// Created by Kevin Lundeen on 10/1/20.
//

#pragma once
#include <string>

// Dictionary of int: string functionality in a linked list implementation.
class LinkedList {
public:
    LinkedList();
    ~LinkedList();
    LinkedList(const LinkedList &other);
    LinkedList &operator=(const LinkedList &rhs);

    void add(int key, std::string payload);  // lightning fast!!
    void remove(int key);  // not so fast -- linear search
    std::string search(int key) const;  // not so fast -- linear search

private:
    struct ListElem {
        int key;
        std::string payload;
        ListElem *next;

        // convenience ctor
        ListElem(int k, std::string p, ListElem *n) {
            key = k;
            payload = p;
            next = n;
        }
    };
    ListElem *head;

    void clear();
    static ListElem *copy(ListElem *headToCopy);
};
