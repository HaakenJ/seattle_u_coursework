//
// Created by Haake on 10/8/2020.
//

#include "IntBST.h"

IntBST::IntBST() {
    root = nullptr;
}

bool IntBST::has(int key) const {
    return has(root, key);
}

bool IntBST::has(IntBST::Node *me, int key) const {
    if (me == nullptr)
        return false;
    if (key < me->key)
        return has(me->left, key);
    else if (key > me->key)
        return has(me->right, key);
    else
        return true;
}


void IntBST::add(int newKey) {
    root = add(root, newKey);
}

IntBST::Node *IntBST::add(IntBST::Node *me, int newKey) const {
    if (me == nullptr)
        // this is where I go!!
        me = new Node(newKey, nullptr, nullptr);
    else if (newKey < me->key)
        me->left = add(me->left, newKey);
    else if (newKey > me->key)
        me->right = add(me->right, newKey);
    // else equal so do nothing
    return me;
}

IntBST::~IntBST() {
    clear(root); // delete all the root and its whole tree
}

IntBST::IntBST(const IntBST &other) {
    root = copy(other.root);
}

IntBST &IntBST::operator=(const IntBST &rhs) {
    if (&rhs != this) {
        clear(root);
        root = copy(rhs.root);
    }
    return *this;
}

void IntBST::remove(int key) {
    root = remove(root, key);
}

IntBST::Node *IntBST::remove(IntBST::Node *me, int key) {
    if (me == nullptr)
        return nullptr; // key not found
    if (key < me->key) {
        me->left = remove(me->left, key);
        return me;
    }
    else if (key > me->key) {
        me->right = remove(me->right, key);
        return me;
    }
    else {
        // FOUND IT!!
        if (me->left == nullptr) {
            Node *myReplacement = me->right;
            delete me;
            return myReplacement;
        }
        else if (me->right == nullptr) {
            Node *myReplacement = me->left;
            delete me;
            return myReplacement;
        }
        else {
            // replace me with max element in my left subtree
            me->key = me->left->findMax();
            me->left = remove(me->left, me->key);
        }
    }
}

IntBST::Node *IntBST::copy(IntBST::Node *me) {
    if (me == nullptr)
        return nullptr;
    else
        return new Node(me->key, copy(me->left), copy(me->right));
}

void IntBST::clear(IntBST::Node *me) {
    if (me != nullptr) {
        clear(me->left);
        clear(me->right);
        delete me;
    }
}


int IntBST::Node::findMax() const {
    if (right == nullptr)
        return key;
    else
        return right->findMax();
}
