//
// empty(), size(), getLeafCount(), and isLeaf()
// Created by Kramer Johnson on 10/12/20
// Seattle University, CPSC 5910 03
// lab 4
//
// remainder of code
// Created by Kevin Lundeen on 10/7/20.
// Seattle University, CPSC 5005
//

#include "IntBST.h"

IntBST::IntBST() : root(nullptr) {}

IntBST::~IntBST() {
    clear(root);
}

IntBST::IntBST(const IntBST &other) {
    root = copy(other.root);
}

IntBST &IntBST::operator=(const IntBST &rhs) {
    if (this != &rhs) {
        clear(root);
        root = copy(rhs.root);
    }
    return *this;
}

bool IntBST::has(int key) const {
    return has(root, key);
}

void IntBST::add(int newKey) {
    root = add(root, newKey);
}

void IntBST::remove(int key) {
    root = remove(root, key);
}

int IntBST::Node::findMax() const {
    if (right == nullptr)
        return this->key;
    else
        return right->findMax();
}

bool IntBST::Node::isLeaf() const {
    if (left == nullptr && right == nullptr)
        return true;
    else
        return false;
}

bool IntBST::has(Node *me, int key) {
    if (me == nullptr)
        return false; // not found
    if (key < me->key)
        return has(me->left, key);
    else if (key > me->key)
        return has(me->right, key);
    else  // key == me->key
        return true;
}

IntBST::Node *IntBST::add(Node *me, int newKey) {
    if (me == nullptr)
        me = new Node(newKey);
    else if (newKey < me->key)
        me->left = add(me->left, newKey);
    else if (newKey > me->key)
        me->right = add(me->right, newKey);
    // else do nothing since newKey is already in the set
    return me;
}

IntBST::Node *IntBST::remove(Node *me, int key) {
    if (me == nullptr)
        return nullptr; // key is not in the IntBST so nothing to do nothing

    if (key < me->key) {
        // recurse down the left, possibly changing its root
        me->left = remove(me->left, key);
        return me;  // no change to me

    } else if (key > me->key) {
        // recurse down the right, possibly changing its root
        me->right = remove(me->right, key);
        return me;  // no change to me

    } else {
        // FOUND IT. key == rootlet.key, so remove this one
        if (me->left == nullptr) {
            // In this case the right subtree should just be elevated
            // to replace me; and delete me, too
            // By the way, this also works if me is a leaf since this
            // would cause myReplacement to be nullptr -- exactly correct.
            Node *myReplacement = me->right;
            delete me;
            return myReplacement;

        } else if (me->right == nullptr) {
            // In this case the left subtree should just be elevated
            // to replace me; and delete me, too
            Node *myReplacement = me->left;
            delete me;
            return myReplacement;

        } else {
            // In this case there are nodes to both my right and left
            // so I have to do something more clever!
            // Here we just swap with predecessor node
            // which is the max value from left (equally could use
            // successor node: min value from right)
            me->key = me->left->findMax();
            // and then remove the node that had the predecessor
            me->left = remove(me->left, me->key);
            return me;
        }
    }
}

void IntBST::clear(IntBST::Node *me) {
    if (me != nullptr) {
        clear(me->left);
        clear(me->right);
        delete me;
    }
}

IntBST::Node *IntBST::copy(IntBST::Node *me) {
    if (me == nullptr)
        return nullptr; // nothing to do
    else
        return new Node(me->key, copy(me->left), copy(me->right));
}

bool IntBST::empty() const {
    return root == nullptr;
}

int IntBST::size() const {
    return size(root);
}

int IntBST::getLeafCount() const {
    return getLeafCount(root);
}

int IntBST::size(IntBST::Node *me) {
    if (me == nullptr)
        return 0;
    else
        return 1 + size(me->left) + size(me->right);
}

int IntBST::getLeafCount(IntBST::Node *me) {
    if (me == nullptr)
        return 0;
    else if (me->isLeaf())
        return 1;
    else
        return getLeafCount(me->left) + getLeafCount(me->right);
}

