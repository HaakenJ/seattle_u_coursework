//
// Created by Kevin Lundeen on 10/7/20.
// For Seattle University, CPSC5005, P3.BST
//

#pragma once

#include <sstream>
#include <queue>

/**
 * @class BST - Binary Search Tree implementation of the Set ADT
 *
 * An element is either in the set or not, solely as determined
 * by the equality operator (operator==). There is no
 * concept in this class of multiple equivalent elements.
 *
 * Time-efficiency of methods is from using a balanced BST:
 * has(key)         O(log n)
 * add(key,value)   O(log n)
 * remove(key)      O(log n)
 *
 * @tparam KeyType     type of elements (keys) of the set
 *                     must support all the comparison operators:
 *                     ==, <, <=, >, >=, !=
 */
template<typename KeyType>
class BST {
public:
    /**
     * Simple constructor creates an empty set.
     */
    BST() : root(nullptr) {}

    /**
     * Destructor
     */
    ~BST() {
        clear(root);
    }

    /**
     * Copy constructor creates a deep copy of the set.
     * Uses assignment (operator=) on KeyElem to copy the data.
     * @param other another BST to copy
     */
    BST(const BST<KeyType> &other) {
        root = copy(other.root);
    }

    /**
     * Assignment operator.
     * Destroys current set and makes a deep copy of the rhs set.
     * Uses assignment (operator=) on KeyElem to copy the data.
     * @param rhs  another BST to copy (right-hand side of = expression)
     * @return *this
     */
    BST<KeyType> &operator=(const BST<KeyType> &rhs) {
        if (this != &rhs) {
            clear(root);
            root = copy(rhs.root);
        }
        return *this;
    }

    /**
     * Determine if the given key is currently in this set
     * @param key  possible element of this set
     * @return     true if key is an element, false otherwise
     */
    bool has(const KeyType &key) const {
        return has(root, key);
    }

    /**
     * Insert a new element into the set.
     * If the element was already in the set, this method does nothing.
     * @param newKey to insert
     * @post has(newKey) is true
     */
    void add(const KeyType &newKey) {
        root = add(root, newKey);
    }

    /**
     * Remove the given key from this set.
     *
     * It is irrelevant how many times this key has been added to the set
     * or even if it is currently an element or not.
     * @param key  an element (possibly) of this set
     * @post       has(key) is false
     */
    void remove(const KeyType &key) {
        root = remove(root, key);
    }

    /**
     * Check if this is an empty set.
     * @return true if empty, false otherwise
     */
    bool empty() const {
        return root == nullptr;
    }

    /**
     * Count the number of elements in this set.
     * @return cardinality
     */
    int size() const {
        return size(root);
    }

    /**
     * Count the number of leaves in this BST.
     * Along with size(), this should give some sense of the overall balance.
     * @return number of leaves
     */
    int getLeafCount() const {
        return getLeafCount(root);
    }

    /**
     * Count the number of levels in this BST.
     * Along with size(), this should give some sense of the overall balance.
     * In a well-balanced tree, getHeight()**2 == size(), approximately.
     * @return height (0 for empty tree, 1 for tree with single element, etc.)
     */
    int getHeight() const {
        return getHeight(root);
    }

    /**
     * Calculate the width of the tree (largest number of nodes in the same
     * level).
     * @return width of the tree
     */
    int getWidth() const {
        return getWidth(root);
    }

    /**
     * In-Order Traversal.
     * @return a string of elements in the order specified by the
     *         in-order traversal of the BST
     */
    std::string getInOrderTraversal() const {
        std::ostringstream s;
        getInOrderTraversal(s, root);
        return s.str();
    }

    /**
     * Pre-Order Traversal.
     * @return a string of elements in the order specified by the
     *         pre-order traversal of the BST
     */
    std::string getPreOrderTraversal() const {
        std::ostringstream s;
        getPreOrderTraversal(s, root);
        return s.str();
    }

    /**
     * Post-Order Traversal.
     * @return a string of elements in the order specified by the
     *         post-order traversal of the BST
     */
    std::string getPostOrderTraversal() const {
        std::ostringstream s;
        getPostOrderTraversal(s, root);
        return s.str();
    }

    /**
     * Level-Order Traversal.
     * @return a string of elements in the order specified by the
     *         level-order traversal of the BST
     */
    std::string getLevelOrder() const {
        std::ostringstream ss;
        std::queue<Node*> q;
        q.push(root);
        while (!q.empty()) {
            Node *node = q.front();
            q.pop();
            ss << node->key << ' ';
            if (node->left != nullptr)
                q.push(node->left);
            if (node->right != nullptr)
                q.push(node->right);
        }
        return ss.str();
    }

private:
    struct Node {
        KeyType key;
        Node *left, *right;

        // Convenience constructor
        Node(const KeyType &newKey, Node *lch = nullptr, Node *rch = nullptr) {
            key = newKey;
            left = lch;
            right = rch;
        }

        /**
        * Find the maximum node's value in this subtree.
        *
        * @return  key of the right-most node in this subtree
        */
        const KeyType &findMax() const {
            if (right == nullptr)
                return this->key;
            else
                return right->findMax();
        }

        /**
         * Checks if this is a leaf node.
         *
         * @return  true if a leaf (no left and no right)
         */
        bool isLeaf() const {
            return left == nullptr && right == nullptr;
        }
    };

    /**
     * Only data element of BST -- the root of the binary search tree.
     */
    Node *root;

    /**
    * Recursive helper method for has.
    * @param me   sub-BST in which to look for key
    * @param key  key to search for
    * @return     true if found, false otherwise
    */
    static bool has(Node *me, const KeyType &key) {
        if (me == nullptr)
            return false; // not found
        if (key < me->key)
            return has(me->left, key);
        else if (key > me->key)
            return has(me->right, key);
        else  // key == me->key
            return true;
    }

    /**
    * Recursive helper method for add.
    * @param me      sub-BST to which to add key
    * @param newKey  key to add
    * @return        me, or if me is nullptr, the new Node with newKey
    */
    static Node *add(Node *me, const KeyType &newKey) {
        if (me == nullptr)
            me = new Node(newKey);
        else if (newKey < me->key)
            me->left = add(me->left, newKey);
        else if (newKey > me->key)
            me->right = add(me->right, newKey);
        // else do nothing since newKey is already in the set
        return me;
    }

    /**
     * Recursive helper method for remove.
     * @param me   sub-BST from which to remove key
     * @param key  key to remove
     * @return     me, or my replacement if I get deleted (could be nullptr
     *             if I'm it and also a leaf)
     */
    static Node *remove(Node *me, const KeyType &key) {
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

    /**
     * Recursive helper method to delete a subtree.
     * @param me the root of the subtree to delete
     */
    static void clear(Node *me) {
        if (me != nullptr) {
            clear(me->left);
            clear(me->right);
            delete me;
        }
    }

    /**
     * Recursive helper method to copy a subtree.
     * @param me the root of the subtree to copy
     * @return   a fresh copy of the subtree
     */
    static Node *copy(Node *me) {
        if (me == nullptr)
            return nullptr; // nothing to do
        else
            return new Node(me->key, copy(me->left), copy(me->right));
    }

    /**
     * Size of given subtree.
     * @param me subtree to count
     * @return   number of nodes in me
     */
    static int size(Node *me) {
        if (me == nullptr)
            return 0;
        else
            return 1 + size(me->left) + size(me->right);
    }

    /**
     * Count of leaves in given subtree.
     * @param me subtree to count
     * @return   number of leaves in me
     */
    static int getLeafCount(Node *me) {
        if (me == nullptr)
            return 0;
        else if (me->isLeaf())
            return 1;
        else
            return getLeafCount(me->left) + getLeafCount(me->right);
    }

    /**
     * Height of given subtree.
     * @param me subtree to find height of
     * @return   number of levels in me
     */
    static int getHeight(Node *me) {
        if (me == nullptr)
            return 0;
        else
            return 1 + std::max(getHeight(me->left), getHeight(me->right));
    }

    /**
     * Width of given subtree.
     * @param me subtree to find width of
     * @return   largest number of nodes in the same level
     */
    static int getWidth(Node *me) {
        if (me == nullptr)
            return 0;
        return std::max(getWidth(me->left) + getWidth(me->right), 1);
    }

    /**
     * Recursive helper for in-order traversal.
     * @param s   output string stream to write to
     * @param me  subtree to output
     */
    static void getInOrderTraversal(std::ostream &s, Node *me) {
        if (me == nullptr)
            return;
        getInOrderTraversal(s, me->left);
        s << me->key << " ";
        getInOrderTraversal(s, me->right);
    }

    /**
     * Recursive helper for pre-order traversal.
     * @param s   output string stream to write to
     * @param me  subtree to output
     */
    static void getPreOrderTraversal(std::ostream &s, Node *me) {
        if (me == nullptr)
            return;
        s << me->key << " ";
        getPreOrderTraversal(s, me->left);
        getPreOrderTraversal(s, me->right);
    }

    /**
     * Recursive helper for post-order traversal.
     * @param s   output string stream to write to
     * @param me  subtree to output
     */
    static void getPostOrderTraversal(std::ostream &s, Node *me) {
        if (me == nullptr)
            return;
        getPostOrderTraversal(s, me->left);
        getPostOrderTraversal(s, me->right);
        s << me->key << " ";
    }
};
