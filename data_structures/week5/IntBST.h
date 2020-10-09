//
// Created by Haake on 10/8/2020.
//

#ifndef WEEK5_INTBST_H
#define WEEK5_INTBST_H


class IntBST {
public:
    IntBST();
    ~IntBST();
    IntBST(const IntBST &other);
    IntBST &operator=(const IntBST &rhs);
    // FIXME: rest of big 4

    bool has(int key) const;
    void add(int newKey);
    void remove(int key);

private:
    struct Node {
        int key;
        Node *left, *right;

        Node(int k, Node *lch, Node *rch) {
            key = k;
            left = lch;
            right = rch;
        }
        int findMax() const;
    };
    Node *root;

    bool has(Node *rootlet, int key) const;
    Node *add(Node *rootlet, int kewKey) const;
    Node *remove(Node *rootlet, int key);
    static Node *copy(Node *rootlet);
    void clear(Node *rootlet);
};


#endif //WEEK5_INTBST_H
