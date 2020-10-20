//
// Created by Haake on 10/19/2020.
// Seattle University CSPC 5910 03
// P3
//

#ifndef P3_BST_H
#define P3_BST_H

#include <iostream>
#include <sstream>

template<class T>
class BST {
public:
    /**
     * Simple constructor creates an empty set.
     */
    BST();

    /**
     * Destructor
     */
    ~BST();

    /**
     * Copy constructor creates a copy of the set.
     * @param other another BST to copy
     */
    BST(const BST<T> &other);

    /**
     * Assignment operator.
     * Destroys current set and makes a copy of the rhs set.
     * @param rhs  another BST to copy (right-hand side of = expression)
     * @return *this
     */
    BST<T> &operator=(const BST<T> &rhs);

    /**
     * Insert a new element into the set.
     * If the element was already in the set, this method does nothing.
     * @param newKey to insert
     * @post has(newKey) is true
     */
    void add(const T &key);

    /**
     * Determine if the given key is currently in this set
     * @param key  possible element of this set
     * @return     true if key is an element, false otherwise
     */
    bool has(const T &key) const;

    /**
     * Remove the given key from this set
     *
     * It is irrelevant how many times this key has been added to the set
     * or even if it is currently an element or not.
     * @param key  an element (possibly) of this set
     * @post       has(key) is false
     */
    void remove(const T &key);

    /**
     * Check if this set is empty
     *
     * @return true if empty, false if not
     */
    bool empty() const;

    /**
     * Count the number of nodes in the set
     *
     * @return integer size of tree
     */
    int size() const;

    /**
     * Counts the number of leaves in the set
     *
     * @return integer representing total leaves
     */
    int getLeafCount() const;

    /**
     * Counts the height of the set
     *
     * @return integer representing height
     */
    int getHeight() const;

    /**
     * Creates a string displaying the in-order representation of elements
     * in the set
     *
     * @return string of in-order elements in set
     */
    std::string getInOrderTraversal() const;

    /**
     * Creates a string displaying the pre-order representation of elements
     * in the set
     *
     * @return string of pre-order elements in set
     */
    std::string getPreOrderTraversal() const;

    /**
     * Creates a string displaying the post-order representation of elements
     * in the set
     *
     * @return string of post-order elements in set
     */
    std::string getPostOrderTraversal() const;

private:
    struct Node {
        T key;
        Node *left;
        Node *right;

        // convenience ctor
        explicit Node(const T &newKey, Node *lch = nullptr, Node *rch = nullptr) {
            key = newKey;
            left = lch;
            right = rch;
        }

        /**
         * Find the maximum node's value.
         *
         * @return  key of the right-most node in this subtree
         */
        T findMax() const;

        /**
         * Determine if this node is a leaf
         *
         * @return true if this node is a leaf, false otherwise
         */
        bool isLeaf() const;
    };

    Node *root;

    /**
     * Recursive helper method for has.
     * @param me   sub-BST in which to look for key
     * @param key  key to search for
     * @return     true if found, false otherwise
     */
    static bool has(Node *me, const T &key);

    /**
     * Recursive helper method for add.
     * @param me      sub-BST to which to add key
     * @param newKey  key to add
     * @return        me, or if me is nullptr, the new Node with newKey
     */
    static Node *add(Node *me, const T &newKey);

    /**
     * Recursive helper method for remove.
     * @param me   sub-BST from which to remove key
     * @param key  key to remove
     * @return     me, or my replacement if I get deleted (could be nullptr
     *             if I'm it and also a leaf)
     */
    static Node *remove(Node *me, const T &key);

    /**
     * Recursive helper method to delete a subtree.
     * @param me the root of the subtree to delete
     */
    static void clear(Node *me);

    /**
     * Recursive helper method to copy a subtree.
     * @param me the root of the subtree to copy
     * @return   a fresh copy of the subtree
     */
    static Node *copy(Node *me);

    /**
     * Recursive helper method for size.
     * @param me   sub-BST in which to count size
     * @return     int size of the tree
     */
    static int size(Node *me);

    /**
     * Recursive helper method for getLeafCount.
     * @param me   sub-BST in which to count leaves
     * @return     int number of leaves in the tree
     */
    static int getLeafCount(Node *me);

    /**
     * Recursive helper method for getHeight.
     * @param me   sub-BST in which to count height
     * @return     int height of the tree
     */
    static int getHeight(Node *me);

    /**
     * Recursive helper method for getInOrderTraversal.
     * @param me  sub-BST in which to traverse
     * @param ss  a stringstream that contains the result
     * @return    string representation of in-order set
     */
    static void getInOrderTraversal(Node *me, std::stringstream &ss);

    /**
     * Recursive helper method for getPreOrderTraversal.
     * @param me  sub-BST in which to traverse
     * @param ss  a stringstream that contains the result
     * @return    string representation of in-order set
     */
    static void getPreOrderTraversal(Node *me, std::stringstream &ss);

    /**
     * Recursive helper method for getPostOrderTraversal.
     * @param me  sub-BST in which to traverse
     * @param ss  a stringstream that contains the result
     * @return    string representation of in-order set
     */
    static void getPostOrderTraversal(Node *me, std::stringstream &ss);
};

template <class T>
BST<T>::BST() : root(nullptr) {}

template <class T>
BST<T>::~BST<T>() {
    clear(root);
}

template <class T>
BST<T>::BST(const BST<T> &other) {
    root = copy(other.root);
}

template <class T>
BST<T> &BST<T>::operator=(const BST<T> &rhs) {
    if (this != &rhs) {
        clear(root);
        root = copy(rhs.root);
    }
    return *this;
}

template <class T>
bool BST<T>::has(const T &key) const {
    return has(root, key);
}

template <class T>
void BST<T>::add(const T &newKey) {
    root = add(root, newKey);
}

template <class T>
void BST<T>::remove(const T &key) {
    root = remove(root, key);
}

template <class T>
T BST<T>::Node::findMax() const {
    if (right == nullptr)
        return this->key;
    else
        return right->findMax();
}

template <class T>
bool BST<T>::Node::isLeaf() const {
    if (left == nullptr && right == nullptr)
        return true;
    else
        return false;
}

template <class T>
bool BST<T>::has(Node *me, const T &key) {
    if (me == nullptr)
        return false; // not found
    if (key < me->key)
        return has(me->left, key);
    else if (key > me->key)
        return has(me->right, key);
    else  // key == me->key
        return true;
}

template <class T>
typename BST<T>::Node *BST<T>::add(Node *me, const T &newKey) {
    if (me == nullptr)
        me = new Node(newKey);
    else if (newKey < me->key)
        me->left = add(me->left, newKey);
    else if (newKey > me->key)
        me->right = add(me->right, newKey);
    // else do nothing since newKey is already in the set
    return me;
}

template <class T>
typename BST<T>::Node *BST<T>::remove(Node *me, const T &key) {
    if (me == nullptr)
        return nullptr; // key is not in the BST so nothing to do nothing

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

template <class T>
void BST<T>::clear(BST<T>::Node *me) {
    if (me != nullptr) {
        clear(me->left);
        clear(me->right);
        delete me;
    }
}

template <class T>
typename BST<T>::Node *BST<T>::copy(BST<T>::Node *me) {
    if (me == nullptr)
        return nullptr; // nothing to do
    else
        return new Node(me->key, copy(me->left), copy(me->right));
}

template <class T>
bool BST<T>::empty() const {
    return root == nullptr;
}

template <class T>
int BST<T>::size() const {
    return size(root);
}

template <class T>
int BST<T>::getLeafCount() const {
    return getLeafCount(root);
}

template<class T>
int BST<T>::getHeight() const {
    return getHeight(root);
}

template <class T>
int BST<T>::size(BST<T>::Node *me) {
    if (me == nullptr)
        return 0;
    else
        return 1 + size(me->left) + size(me->right);
}

template <class T>
int BST<T>::getLeafCount(BST<T>::Node *me) {
    if (me == nullptr)
        return 0;
    else if (me->isLeaf())
        return 1;
    else
        return getLeafCount(me->left) + getLeafCount(me->right);
}

template<class T>
int BST<T>::getHeight(BST::Node *me) {
    if (me == nullptr)
        return 0;
    else
        return 1 + std::max(getHeight(me->left), getHeight(me->right));
}

template<class T>
std::string BST<T>::getInOrderTraversal() const {
    std::stringstream ss;
    getInOrderTraversal(root, ss);
    return ss.str();
}

template<class T>
void BST<T>::getInOrderTraversal(BST::Node *me, std::stringstream &ss) {
    if (me != nullptr) {
        getInOrderTraversal(me->left, ss);
        ss << me->key << " ";
        getInOrderTraversal(me->right, ss);
    }
    else
        return;
}

template<class T>
std::string BST<T>::getPreOrderTraversal() const {
    std::stringstream ss;
    getPreOrderTraversal(root, ss);
    return ss.str();
}

template<class T>
void BST<T>::getPreOrderTraversal(BST::Node *me, std::stringstream &ss) {
    if (me != nullptr) {
        ss << me->key << " ";
        getPreOrderTraversal(me->left, ss);
        getPreOrderTraversal(me->right, ss);
    }
    else
        return;
}

template<class T>
std::string BST<T>::getPostOrderTraversal() const {
    std::stringstream ss;
    getPostOrderTraversal(root, ss);
    return ss.str();
}

template<class T>
void BST<T>::getPostOrderTraversal(BST::Node *me, std::stringstream &ss) {
    if (me != nullptr) {
        getPostOrderTraversal(me->left, ss);
        getPostOrderTraversal(me->right, ss);
        ss << me->key << " ";
    }
    else
        return;
}

#endif //P3_BST_H
