//
// Created by Haake on 10/15/2020.
//

#ifndef WEEK6_HEAP_H
#define WEEK6_HEAP_H


class Heap {
public:
    Heap();
    void enqueue(int newItem);
    int dequeue();
    bool empty();
    int peek() const;
private:
    static const int CAPACITY = 1000;
    int data[CAPACITY];
    int size;

    void percolateUp(int newIndex, int parentIndex);

    left = (i * 2 + 1)
    left = (i * 2 + 2)
};


#endif //WEEK6_HEAP_H
