//
// Created by Haake on 10/1/2020.
//
#include <string>

#ifndef LINKEDLIST_LINKEDLIST_H
#define LINKEDLIST_LINKEDLIST_H

class LinkedList {
public:
    LinkedList();
    ~LinkedList();
    LinkedList(const LinkedList &other);
    LinkedList &operator=(const LinkedList &rhs);

    void add(int key, std::string payload);
    void remove(int key);
    std::string search(int key) const;

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


#endif //LINKEDLIST_LINKEDLIST_H
