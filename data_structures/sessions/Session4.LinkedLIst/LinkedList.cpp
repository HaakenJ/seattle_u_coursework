//
// Created by Kevin Lundeen on 10/1/20.
//

#include "LinkedList.h"
using namespace std;

LinkedList::LinkedList() {
    head = nullptr;
}

LinkedList::~LinkedList() {
    clear();
}

LinkedList::LinkedList(const LinkedList &other) {
    head = copy(other.head);
}

LinkedList & LinkedList::operator=(const LinkedList &rhs) {
    if (&rhs != this) {
        clear();
        head = copy(rhs.head);
    }
    return *this;
}

void LinkedList::clear() {
    while (head != nullptr) {
        ListElem *toDelete = head;
        head = head->next;
        delete toDelete;
    }
}

void LinkedList::add(int key, std::string payload) {
    if (payload == "")
        throw invalid_argument("Cannot have a payload of empty string (means "
                               "not found when returned from search)");
    head = new ListElem(key, payload, head);
}

std::string LinkedList::search(int key) const {
    for (ListElem *cur = head; cur != nullptr; cur = cur->next) {
        if (cur->key == key)
            return cur->payload;
    }
    return ""; // Empty string means not found
}

LinkedList::ListElem *LinkedList::copy(LinkedList::ListElem *headToCopy) {
    ListElem anchor(0, "", nullptr), *source, *tail;
    tail = &anchor;
    for (source = headToCopy; source != nullptr; source = source->next) {
        tail->next = new ListElem(source->key, source->payload, nullptr);
        tail = tail->next;
    }
    return anchor.next;
}

void LinkedList::remove(int key) {
    if (head == nullptr)
        return;

    // special case if found at head of list
    if (head->key == key) {
        ListElem *toDelete = head;
        head = head->next;
        delete toDelete;
        return;
    }

    // normal case is to find later down the list
    ListElem *prior = head;
    for (ListElem *cur = head->next; cur != nullptr; cur = cur->next) {
        if (cur->key == key) {
            prior->next = cur->next;
            delete cur;
            return;
        }
        prior = prior->next;
    }
}


