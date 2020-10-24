//
// Created by Kevin Lundeen on 10/1/20.
//

#include "ArrayList.h"
using namespace std;

// keep it in sorted order so our binary search works
void ArrayList::add(int key, std::string payload) {
    if (payload == "")
        throw invalid_argument("Cannot have a payload of empty string (means "
                               "not found when returned from search)");

    int where = bsearch(key, 0, size - 1);
    if (data[where].key != key) {
        // move everything to the right
        for (int i = where; i < size; i++)
            data[i + 1] = data[i];
        data[where].key = key;
        data[where].payload = payload;
        size++;
    }
}

void ArrayList::remove(int key) {
    int where = bsearch(key, 0, size - 1);
    if (where < size && data[where].key == key) {
        size--;
        // move everything to the left
        for (int i = where; i < size; i++)
            data[i] = data[i + 1];
    }
}

std::string ArrayList::search(int key) const {
    int where = bsearch(key, 0, size - 1);
    if (where < size && data[where].key == key)
        return data[where].payload;
    return ""; // not found
}

// returns the place with key >= search key
// (or size if search key is biggest of all)
int ArrayList::bsearch(int key, int lo, int hi) const {
    if (hi <= lo) {
        // not found, so find the insertion point (first place where key is
        // greater than search key)
        int insertion = hi < 0 ? 0 : hi;  // insertion = max(0, hi)
        while (insertion < size && data[insertion].key < key)
            insertion++;
        return insertion;
    }
    int mid = (lo + hi) / 2;
    if (data[mid].key == key)
        return mid;
    if (data[mid].key < key)
        return bsearch(key, mid + 1, hi);
    return bsearch(key, lo, mid - 1);
}
