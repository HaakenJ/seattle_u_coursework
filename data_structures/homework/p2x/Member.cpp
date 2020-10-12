//
// Created by KJohnson on 10/04/2020.
// Lab 3 in CPSC 5910 03 at Seattle University
// Fall 2020
//

#include <iostream>
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


Member &Member::operator=(const Member &rhs) {
    if (this != &rhs) {

        // Deallocate memory
        delete[] this->memberArray;

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
    return *this;
}

Member::~Member() {
    delete[] memberArray;
}

int Member::addMember(std::string memberName) {
    // Determine if resize is needed
    if (count >= capacity)
        resize();

    // Create a new MemberInfo for the new member
    MemberInfo newMember = {count + 1000, memberName, false};

    // Add new member and increase count
    memberArray[count++] = newMember;

    // Return the memberId (index)
    return count - 1;
}

std::string Member::findName(int memberId) const {
    // Determine if memberId returns a valid member
    if (memberId < count && memberId >= 0)
        return memberArray[memberId].name;

    // Provided memberId is invalid
    return "";
}

bool Member::login(int memberId) {
    // Determine if memberId returns a valid member
    if (memberId < count && memberId >= 0) {
        memberArray[memberId].loggedIn = true;
        return true;
    }

    // Provided memberId is invalid
    return false;
}

bool Member::logout(int memberId) {
    // Determine if memberId returns a valid member
    if (memberId < count && memberId >= 0) {
        memberArray[memberId].loggedIn = false;
        return true;
    }

    // Provided memberId is invalid
    return false;
}

void Member::printAccount(int memberId) const {
    if (memberId < count && memberId >= 0) {
        std::cout << memberArray[memberId].name;
        std::cout << " (account #: ";
        std::cout << memberArray[memberId].account << ")";
    } else {
        std::cout << "No such member found for member id: " << memberId;
    }
}

void Member::print() const {
    for (int i = 0; i < count; ++i) {
        std::cout << "Member account #: ";
        std::cout << memberArray[i].account << std::endl;
        std::cout << "Member name: " << memberArray[i].name << std::endl;
        std::cout << "This member is";
        std::cout << (memberArray[i].loggedIn ? " " : " not ") << "logged in";
        std::cout << std::endl;
        std::cout << std::endl;
    }
}

int Member::size() const {
    return count;
}

void Member::resize() {
    // Update capacity
    capacity *= 2;

    // Create temp array with new capacity
    auto *temp = new MemberInfo[capacity];

    // Copy old values to temp array
    for (int i = 0; i < count; ++i) {
        temp[i] = memberArray[i];
    }

    // Deallocate old memberArray
    delete[] memberArray;

    // Reassign old array to new
    memberArray = temp;
}
