//
// Created by Haake on 9/17/2020.
//

#ifndef INTLIST_INTLIST_H
#define INTLIST_INTLIST_H


class IntList {
public:
    IntList(int initialSize); // Constructor
    ~IntList(); // Destructor - we now need the Big 4!
    // Big 4: ctor, dtor, copy-constructor, assignment-op
    IntList(const IntList &other); // copy-ctor
    IntList &operator=(const IntList &rhs); // assignment-op
    void add(int item); // add item to list
    int get(int seach) const; // took for search and return index
    int size() const;
private:
    int *list;
    int capacity; // how many elements can be in a list
    int numElements; // how many add's have happened
};


#endif //INTLIST_INTLIST_H
