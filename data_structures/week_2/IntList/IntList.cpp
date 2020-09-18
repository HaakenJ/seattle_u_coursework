//
// Created by Haake on 9/17/2020.
//

#include "IntList.h"

using namespace std;

IntList::IntList(int initialSize) {
    capacity = initialSize;
    list = new int[capacity]; // allocating system resources
    numElements = 0;
}

// Very simple but VERY important
IntList::~IntList() {
    delete[] list; // release system resources in ctor
}

void IntList::add(int item) {
    list[numElements++] = item;
}

int IntList::size() const {

}

int IntList::get(int search) cons {
    for (int i = 0; i < numElements)
}