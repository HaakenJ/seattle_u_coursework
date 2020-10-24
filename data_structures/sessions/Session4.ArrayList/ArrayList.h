//
// Created by Kevin Lundeen on 10/1/20.
//

#pragma once
#include <string>

class ArrayList {
public:
    ArrayList() : size(0) {}
    void add(int key, std::string payload);  // This is slow
    void remove(int key);  // This is slow
    std::string search(int key) const;  // This is fast!!!

private:
    static const int CAPACITY = 1000;
    struct ListElem {
        int key;
        std::string payload;
    };
    ListElem data[CAPACITY];
    int size;

    int bsearch(int key, int lo, int hi) const;
};
