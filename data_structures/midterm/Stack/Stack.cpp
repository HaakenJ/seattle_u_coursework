//
// Created by Haake on 10/2/2020.
//

#include "Stack.h"

using namespace std;

Stack::Stack() {
    head = nullptr;
}

Stack::~Stack() {
    clear();
}

Stack::Stack(const Stack &other) {
    head = copy(other.head);
}

Stack &Stack::operator=(const Stack &rhs) {
    if (&rhs != this) {
        clear();
        head = copy(rhs.head);
    }
    return *this;
}

void Stack::clear() {
    while (head != nullptr) {
        StackElem *toDelete = head;
        head = head->next;
        delete toDelete;
    }
}

void Stack::push(std::string element) {
    head = new StackElem(element, head);
}

std::string Stack::pop() throw(range_error) {
    if (empty())
        throw range_error("The stack is empty, cannot pop an element");

    string result = head->element;
    StackElem *toDelete = head;
    head = head->next;
    delete toDelete;
    return result;
}

bool Stack::empty() const {
    return head == nullptr;
}

Stack::StackElem *Stack::copy(Stack::StackElem *headToCopy) {
    StackElem anchor("", nullptr), *source, *tail;
    tail = &anchor;
    for (source = headToCopy; source != nullptr; source = source->next) {
        tail->next = new StackElem(source->element, nullptr);
        tail = tail->next;
    }
    return anchor.next;
}


