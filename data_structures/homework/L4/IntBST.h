//
// Created by Kevin Lundeen on 10/7/20.
// Seattle University, CPSC 5005
//

#pragma once

/**
 * @class IntBST - Binary Search Tree implementation of the Set ADT
 *
 * An element is either in the set or not, solely as determined
 * by the equality operator (operator==). There is no
 * concept in this class of multiple equivalent elements.
 *
 * Time-efficiency of methods is from using a balanced IntBST:
 * has(key)         O(log n)
 * add(key,value)   O(log n)
 * remove(key)      O(log n)
 */
class IntBST {
public:
    /**
     * Simple constructor creates an empty set.
     */
    IntBST();

    /**
     * Destructor
     */
    ~IntBST();

    /**
     * Copy constructor creates a copy of the set.
     * @param other another IntBST to copy
     */
    IntBST(const IntBST &other);

    /**
     * Assignment operator.
     * Destroys current set and makes a copy of the rhs set.
     * @param rhs  another IntBST to copy (right-hand side of = expression)
     * @return *this
     */
    IntBST &operator=(const IntBST &rhs);

    /**
     * Determine if the given key is currently in this set
     * @param key  possible element of this set
     * @return     true if key is an element, false otherwise
     */
    bool has(int key) const;

    /**
     * Insert a new element into the set.
     * If the element was already in the set, this method does nothing.
     * @param newKey to insert
     * @post has(newKey) is true
     */
    void add(int newKey);

    /**
     * Remove the given key from this set
     *
     * It is irrelevant how many times this key has been added to the set
     * or even if it is currently an element or not.
     * @param key  an element (possibly) of this set
     * @post       has(key) is false
     */
    void remove(int key);

private:
    struct Node {
        int key;
        Node *left, *right;

        // Convenience constructor
        Node(int newKey, Node *lch = nullptr, Node *rch = nullptr) {
            key = newKey;
            left = lch;
            right = rch;
        }

        /**
        * Find the maximum node's value.
        *
        * @return  key of the right-most node in this subtree
        */
        int findMax() const;
    };

    /**
     * Only data element of IntBST -- the root of the binary search tree.
     */
    Node *root;

    /**
    * Recursive helper method for has.
    * @param me   sub-IntBST in which to look for key
    * @param key  key to search for
    * @return     true if found, false otherwise
    */
    static bool has(Node *me, int key);

    /**
    * Recursive helper method for add.
    * @param me      sub-IntBST to which to add key
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
};
