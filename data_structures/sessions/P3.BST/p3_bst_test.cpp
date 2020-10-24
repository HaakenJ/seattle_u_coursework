//
// Created by Kevin Lundeen on 10/7/20.
// For Seattle University, CPSC5005, P3.BST
//

#include <iostream>
#include <fstream>
#include "BST.h"

using namespace std;

bool firstTest() {
    string title = "first test: ";

    BST<string> bst;
    cout << title << "check if empty tree has cat" << endl;
    if (bst.has("cat"))
        return false;
    cout << title << "add cat and check has(cat)" << endl;
    bst.add("cat");
    if (!bst.has("cat"))
        return false;
    cout << title << "remove cat and check" << endl;
    bst.remove("cat");
    if (bst.has("cat"))
        return false;

    BST<int> bsti;
    cout << title << "check if empty tree has 1" << endl;
    if (bsti.has(1))
        return false;
    cout << title << "add 1 and check has(1)" << endl;
    bsti.add(1);
    if (!bsti.has(1))
        return false;
    cout << title << "remove 1 and check" << endl;
    bsti.remove(1);
    if (bsti.has(1))
        return false;
    cout << title;
    return true;
}

bool critterTest() {
    string title = "critter test: ";
    BST<string> critters;
    cout << title << "check empty" << endl;
    if (!critters.empty())
        return false;
    cout << title << "adding critters then checking them" << endl;
    string pets[] = {"bee", "ant", "newt", "owl", "hawk", "dog", "elk", "cat"};
    for (string pet: pets)
        critters.add(pet);
    for (string pet: pets)
        if (!critters.has(pet)) {
            cout << title << "OUCH, missing " << pet << endl;
            return false;
        }
    if (critters.size() != 8)
        return false;
    cout << title << "number of leaves " << critters.getLeafCount() << endl;
    BST<string> another(critters);
    cout << title << "removing them all" << endl;
    for (string pet: pets)
        critters.remove(pet);
    cout << title << "check empty" << endl;
    if (!critters.empty())
        return false;

    cout << title << "checking copy" << endl;
    for (string pet: pets)
        if (!another.has(pet)) {
            cout << title << "OUCH, another missing " << pet << endl;
            return false;
        }
    if (another.size() != 8)
        return false;
    cout << title;
    return true;
}

string trueFalse(bool cond) {
    return cond ? "true" : "false";
}

template<typename KeyType>
void printData(const BST<KeyType> &bst) {
    cout << "# of nodes:  " << bst.size() << endl;
    cout << "# of leaves: " << bst.getLeafCount() << endl;
    cout << "BST height:  " << bst.getHeight() << endl;
    cout << "BST empty?   " << trueFalse(bst.empty()) << endl;
}

template<typename KeyType>
void printTraversals(const BST<KeyType> &bst) {
    cout << "pre-order:   " << bst.getPreOrderTraversal() << endl;
    cout << "in-order:    " << bst.getInOrderTraversal() << endl;
    cout << "post-order:  " << bst.getPostOrderTraversal() << endl;
}

void sampleOutputInt() {
    int testers[] = {20, 40, 10, 70, 99, -2, 59, 43};

    cout << endl;
    cout << "******************************" << endl;
    cout << "* INTEGER BINARY SEARCH TREE *" << endl;
    cout << "******************************" << endl;
    cout << endl;

    cout << "** CREATE BST **" << endl;
    BST<int> ibst;
    printData(ibst);
    cout << endl;

    cout << "Enter integer file: ";
    string filename;
    getline(cin, filename);
    cout << endl;
    cout << "** TEST INSERT **" << endl;
    cout << "Inserting in this order:";
    ifstream infile;
    infile.open(filename);
    int n;
    while (infile >> n) {
        cout << " " << n;
        ibst.add(n);
    }
    infile.close();
    cout << endl;
    printData(ibst);
    cout << endl;
    cout << "** TEST TRAVERSALS **" << endl;
    printTraversals(ibst);
    cout << endl;

    cout << "** TEST CONTAINS **" << endl;
    for (int n: testers)
        cout << "has(" << n << "): " << trueFalse(ibst.has(n)) << endl;
    cout << endl;

    cout << "** TEST REMOVE **" << endl;
    cout << "Removing in this order:";
    for (int n: testers) {
        cout << " " << n;
        ibst.remove(n);
    }
    cout << endl;
    printData(ibst);
    printTraversals(ibst);
    cout << endl;

    cout << "** TEST INSERT (again) **" << endl;
    cout << "Inserting in this order:";
    for (int n: testers) {
        cout << " " << n;
        ibst.add(n);
    }
    cout << endl;
    printData(ibst);
    printTraversals(ibst);
    cout << endl;
}

void sampleOutputString() {
    string testers[] = {"gene", "mary", "bea", "uma", "yan", "amy", "ron",
                        "opal"};

    cout << endl;
    cout << "*******************" << endl;
    cout << "* test string BST *" << endl;
    cout << "*******************" << endl;
    cout << endl;

    cout << "** CREATE BST **" << endl;
    BST<string> sbst;
    printData(sbst);
    cout << endl;

    cout << "Enter string file: ";
    string filename;
    getline(cin, filename);
    cout << endl;
    cout << "** TEST INSERT **" << endl;
    cout << "Inserting in this order:";
    ifstream infile;
    infile.open(filename);
    string name;
    while (getline(infile, name)) {
        cout << " " << name;
        sbst.add(name);
    }
    infile.close();
    cout << endl;
    printData(sbst);
    cout << endl;
    cout << "** TEST TRAVERSALS **" << endl;
    printTraversals(sbst);
    cout << endl;

    cout << "** TEST CONTAINS **" << endl;
    for (string n: testers)
        cout << "has(" << n << "): " << trueFalse(sbst.has(n)) << endl;
    cout << endl;

    cout << "** TEST REMOVE **" << endl;
    cout << "Removing in this order:";
    for (string n: testers) {
        cout << " " << n;
        sbst.remove(n);
    }
    cout << endl;
    printData(sbst);
    printTraversals(sbst);
    cout << endl;

    cout << "** TEST INSERT (again) **" << endl;
    cout << "Inserting in this order:";
    for (string n: testers) {
        cout << " " << n;
        sbst.add(n);
    }
    cout << endl;
    printData(sbst);
    printTraversals(sbst);
    cout << endl;
}

void sampleOutputEC() {
    int sample[] = {40, 20, 60, 10, 30, 50, 70};
    BST<int> bst;
    for (int elem: sample)
        bst.add(elem);
    cout << "width: " << bst.getWidth() << endl;
    cout << "level-order: " << bst.getLevelOrder() << endl;
}

int main() {
    cout << "Welcome (add more info about the program here)!" << endl;
    cout << endl;
    sampleOutputInt();
    sampleOutputString();
    sampleOutputEC();
    cout << endl << endl << "Goodbye!" << endl << endl;

    cout << (firstTest() ? "passed" : "failed") << endl;
    cout << (critterTest() ? "passed" : "failed") << endl;
    return EXIT_SUCCESS;
}
