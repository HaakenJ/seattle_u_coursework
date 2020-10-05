//
// Created by Haake on 10/4/2020.
//

#include "Member.h"

Member::Member() {
    capacity = INITIAL_CAPACITY;
    count = 0;
    memberArray = new MemberInfo[capacity];
}

Member::Member(const Member &other) {
    // Copy data elements
    capacity = other.capacity;
    count = other.count;

    // Allocate memory with new capacity
    memberArray = new MemberInfo[capacity];

    // Copy over elements from other
    for (int i = 0; i < count; ++i) {
        memberArray[i] = other.memberArray[i];
    }
}


Member& Member::operator=(const Member &rhs) {
    if (this != &rhs) {

        // Deallocate memory
        delete [] this->memberArray;

        // Assign count and capacity from rhs
        this->capacity = rhs.capacity;
        this->count = rhs.count;

        // Allocate memory with new capacity
        this->memberArray = new MemberInfo[capacity];

        // Copy over elements from rhs
        for (int i = 0; i < count; ++i) {
            this->memberArray[i] = rhs.memberArray[i];
        }
    }
}

Member::~Member() {
    delete [] memberArray;
}