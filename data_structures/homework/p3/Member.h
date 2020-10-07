//
// Created by Kevin Lundeen on 9/25/20
// for Seattle University, CPSC 5005, Fall 2020
//
// Header file used by Kramer Johnson for
// Project 3 in CPSC 5910 03 at Seattle University
// Fall 2020
//

#pragma once

#include <string>

/**
 * Member class holds a list of current members.
 * Members are uniquely identified by a member id returned by the add method.
 */
class Member {
public:
    /**
     * Constructor
     */
    Member();

    /**
     * Copy constructor.
     * @param other Member to copy
     */
    Member(const Member &other);

    /**
     * Assignment operator -- make a deep copy.
     * @param rhs Member to copy
     * @return myself
     */
    Member &operator=(const Member &rhs);

    /**
     * Destructor
     */
    ~Member();

    /**
     * Add a new member.
     * @param memberName
     * @return member id (useful for calling findName, for example)
     */
    int addMember(std::string memberName);

    /**
     * Find the name of the given member.
     * @param memberId as returned by the addMember method
     * @return member name or blank string if not found
     */
    std::string findName(int memberId) const;

    /**
     * Login to account.
     * @param memberId to login
     * @return true if logged in successfully or false if no such member
     */
    bool login(int memberId);

    /**
     * Logout of account.
     * @param memberId to logout
     * @return true if logged out successfully or false if no such member
     */
    bool logout(int memberId);

    /**
     * Print to std::cout a line about the given member.
     * @param memberId as returned by the addMember method
     */
    void printAccount(int memberId) const;

    /**
     * Print to std::cout the entire member list contents
     */
    void print() const;

    /**
     * Get the cardinality of the list.
     * @return number of successful calls to add
     */
    int size() const;

private:
    static const int INITIAL_CAPACITY = 23;
    struct MemberInfo {
        int account;
        std::string name;
        bool loggedIn;
    };
    MemberInfo *memberArray;
    int count;
    int capacity;

    /**
     * Automatically enlarge if we get more than INITIAL_CAPACITY books in
     * the list.
     */
    void resize();
};
