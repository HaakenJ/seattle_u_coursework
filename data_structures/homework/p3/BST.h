//
// Created by Haake on 10/19/2020.
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
        std::string payload;
        Node *left;
        Node *right;

        // convenience ctor
        Node(T k, Node *l, Node *r) {
            key = k;
            left = l;
            right = r;
        }
    };

    Node *root;

    /**
     * Recursive helper method for has.
     * @param me   sub-BST in which to look for key
     * @param key  key to search for
     * @return     true if found, false otherwise
     */
    static bool has(Node *me, int key);

    /**
     * Recursive helper method for add.
     * @param me      sub-BST to which to add key
     * @param newKey  key to add
     * @return        me, or if me is nullptr, the new Node with newKey
     */
    static Node *add(Node *me, int newKey);

    /**
     * Recursive helper method for remove.
     * @param me   sub-IntBST from which to remove key
     * @param key  key to remove
     * @return     me, or my replacement if I get deleted (could be nullptr
     *             if I'm it and also a leaf)
     */
    static Node *remove(Node *me, int key);

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
     * Recursive helper method for getLeafCount.
     * @param me   sub-IntBST in which to count leaves
     * @return     int number of leaves in the tree
     */
    static int getLeafCount(Node *me);
};

#endif //P3_BST_H
