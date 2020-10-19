//
// Created by Haake on 10/14/2020.
//

#ifndef L5_LINKEDLIST_H
#define L5_LINKEDLIST_H

#include <iostream>
#include <string>

template<class KeyType>
class LinkedList {
public:
    LinkedList();

    ~LinkedList();

    LinkedList(const LinkedList<KeyType> &other);

    LinkedList<KeyType> &operator=(const LinkedList<KeyType> &rhs);

    void add(const KeyType &key, const std::string &payload);

    /**
     * Returns the last negative value contained in the list
     * @precon the list must contain at least one negative value
     * @return the last negative value of type KeyType
     */
    KeyType getLastNegative() const;

private:
    struct ListElem {
        KeyType key;  // KeyType is the template argument
        std::string payload;
        ListElem *next;

        // convenience ctor
        ListElem(KeyType k, std::string p, ListElem *n) {
            key = k;
            payload = p;
            next = n;
        }
    };
    ListElem *head;

    void clear();
    static ListElem *copy(ListElem *headToCopy);

    /**
     * Recursive helper function for getLastNegative()
     * @param me     current list element
     * @param result a KeyType variable to store a result if found
     * @return       the KeyType value of the last negative element in the list
     */
    static KeyType getLastNegative(ListElem *me, KeyType result);
};



template <class KeyType>
LinkedList<KeyType>::LinkedList() {
    head = nullptr;
}

template <class KeyType>
LinkedList<KeyType>::~LinkedList() {
    clear();
}

template <class KeyType>
LinkedList<KeyType>::LinkedList(const LinkedList<KeyType> &other) {
    head = copy(other.head);
}

template <class KeyType>
LinkedList<KeyType> & LinkedList<KeyType>::operator=(const LinkedList<KeyType> &rhs) {
    if (&rhs != this) {
        clear();
        head = copy(rhs.head);
    }
    return *this;
}

template <class KeyType>
void LinkedList<KeyType>::clear() {
    while (head != nullptr) {
        ListElem *toDelete = head;
        head = head->next;
        delete toDelete;
    }
}

template <class KeyType>
typename LinkedList<KeyType>::ListElem *LinkedList<KeyType>::
        copy(LinkedList::ListElem *headToCopy) {
    ListElem anchor(0, "", nullptr), *source, *tail;
    tail = &anchor;
    for (source = headToCopy; source != nullptr; source = source->next) {
        tail->next = new ListElem(source->key, source->payload, nullptr);
        tail = tail->next;
    }
    return anchor.next;
}

template <class KeyType>
void LinkedList<KeyType>::add(const KeyType &key, const std::string &payload) {
    head = new ListElem(key, payload, head);
}

template <class KeyType>
KeyType LinkedList<KeyType>::getLastNegative() const {
    KeyType result = 0;
    return getLastNegative(head, result);
}

template <class KeyType>
KeyType LinkedList<KeyType>::getLastNegative(ListElem *me, KeyType result) {
    if (me == nullptr)
        return result;
    else if (me->key < 0)
        result = me->key;
    return getLastNegative(me->next, result);
}


#endif //L5_LINKEDLIST_H
