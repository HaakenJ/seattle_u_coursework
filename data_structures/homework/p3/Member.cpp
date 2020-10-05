//
// Created by Haake on 10/4/2020.
//

#include "Member.h"
#include <stdexcept>

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

std::string Member::findName(int memberId) noexcept(false) {
    // Determine if memberId returns a valid member
    if (memberId < count)
        return memberArray[memberId].name;

    // Provided memberId is invalid
    throw std::invalid_argument("The member id provided is not associated"
                                " with a member");
}

bool Member::login(int memberId) {
    return false;
}

void Member::logout(std::string memberName) {

}

void Member::printAccount(int memberId) {

}

void Member::print() {

}

int Member::size() {
    return 0;
}
