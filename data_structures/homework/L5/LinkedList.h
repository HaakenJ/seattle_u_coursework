//
// Created by Haake on 10/14/2020.
//

#ifndef L5_LINKEDLIST_H
#define L5_LINKEDLIST_H

#include <string>

template<class KeyType>
class LinkedList {
public:
    LinkedList();

    ~LinkedList();

    LinkedList(const LinkedList &other);

    LinkedList &operator=(const LinkedList &rhs);

    void add(const KeyType &item, std::string payload);

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
LinkedList<KeyType>::LinkedList(const LinkedList &other) {
    head = copy(other.head);
}

template <class KeyType>
LinkedList<KeyType> & LinkedList<KeyType>::operator=(const LinkedList &rhs) {
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


#endif //L5_LINKEDLIST_H
