//
// Created by Haake on 10/2/2020.
//
#include <iostream>

#ifndef STACK_STACK_H
#define STACK_STACK_H


class Stack {
public:
    // Default constructor
    Stack();
    // Destructor
    ~Stack();
    // Copy ctor
    Stack(const Stack &other);
    //Assign. Op
    Stack &operator=(const Stack &rhs);

    /** Function to push an element onto the top of the stack
     * @param element string to push onto stack
     */
    void push(std::string element);

    /** Function to remove an element from the top of the stack
     * and return it to the client
     * @throws range_error if the stack is empty
     * @return string element from the top of the stack
     */
    std::string pop() throw(std::range_error);

    /** Function to determine if a stack is empty
     * @return true if stack is empty, false otherwise
     */
    bool empty() const;

private:
    struct StackElem {
        std::string element;
        StackElem *next;

        StackElem(std::string e, StackElem *n) {
            element = e;
            next = n;
        }
    };
    StackElem *head;

    void clear();
    static StackElem *copy(StackElem *headToCopy);
};


#endif //STACK_STACK_H
