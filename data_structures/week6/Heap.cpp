//
// Created by Haake on 10/15/2020.
//

#include "Heap.h"

Heap::Heap() {
    size = 0;
}

void Heap::enqueue(int newItem) {
    data[size] = newItem;
    int parentIndex = (size - 1) / 2;

    percolateUp(newItem, size, parentIndex);
}

void Heap::percolateUp(int newIndex, int parentIndex) {
    if (data[newIndex] >= data[parentIndex])
        return;
    if (data[newIndex] < data[parentIndex])
        swap(newIndex, parentIndex);
        percolateUp(parentIndex, (parentIndex - 1) / 2);
}

