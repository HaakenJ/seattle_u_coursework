#include <iostream>

// Use libraries from the "Standard Template Library" (STL)
// Everything in these libraries is in the std:: namespace
#include <set>  // this implements a Set ADT
#include <map>  // this implements a Dictionary ADT

using namespace std;

bool setTest() {
    string title = "first test: ";

    set<int> bsti;
    cout << title << "check if empty tree has 1" << endl;
    if (bsti.find(1) != bsti.end()) // like our bst.has(1)
        return false;
    cout << title << "add 1 and check find(1)" << endl;
    bsti.insert(1);
    if (bsti.find(1) == bsti.end())
        return false;
    cout << title << "remove 1 and check" << endl;
    bsti.erase(1);
    if (bsti.find(1) != bsti.end())
        return false;

    set<string> bst;
    cout << title << "check if empty tree has cat" << endl;
    if (bst.find("cat") != bst.end())
        return false;
    cout << title << "add cat and check find(cat)" << endl;
    bst.insert("cat");
    if (bst.find("cat") == bst.end())
        return false;
    cout << title << "remove cat and check" << endl;
    bst.erase("cat");
    if (bst.find("cat") != bst.end())
        return false;

    cout << title;
    return true;
}

bool mapTest() {
    string title = "map test: ";

    map<int, string> d;  // my dictionary which "maps" integer keys to strings
    cout << title << "check empty" << endl;
    if (!d.empty())
        return false;
    cout << title << "insert some elements into the dictionary" << endl;
    d.insert(pair<int,string>(1, "one"));  // insert method still works
    d[20] = "twenty";  // but normally we just use the operator[]
    d[-9] = "negative nine";
    d[1e9] = "one billion";
    if (d.empty())
        return false;
    int keys[] = {1, 20, -9, 1000000000};
    for (int key: keys)
        cout << title << key << ": " << d[key] << endl;

    cout << title << "looking up one that isn't there" << endl;
    if (d.find(666) != d.end())
        return false;

    cout << title << "removing them and checking" << endl;
    for (int key: keys)
        d.erase(key);
    if (!d.empty())
        return false;
    for (int key: keys)
        if (d.find(key) != d.end())
            return false;

    cout << title;
    return true;
}

int main() {
    cout << (setTest() ? "passed" : "failed") << endl;
    cout << (mapTest() ? "passed" : "failed") << endl;
    return 0;
}
