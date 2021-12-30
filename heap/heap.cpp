#include <bits/stdc++.h>

using namespace std;

class Heap {
    int heap[10000]{};
    int size = 0;

public:
    void insert(int);

    void printHeap();

    int popIterative();

    void heapify(int index);

    int pop();
};

void Heap::insert(int value) {
    // a complete binary tree with one node is always a binary tree
    if (size == 0)
        heap[size++] = value;
    else {
        // add element to the leaf
        heap[size++] = value;
        // get the index of last item
        int index = size - 1;
        // get the parent index
        int parent = (int) index / 2;
        // push the value upwards till it satisfies heap property
        while (index > 0 && heap[parent] < heap[index]) {
            swap(heap[parent], heap[index]);
            index = parent;
            parent = (int) index / 2;
        }
    }
}

void Heap::printHeap() {
    for (int i = 0; i < size; i++) cout << heap[i] << " ,";
    cout << endl;
}

void Heap::heapify(int index) {
    int leftChildIndex = index * 1 + 1;
    int rightChildIndex = index * 1 + 2;
    int maxChildIndex = index;

    if (leftChildIndex < size && heap[leftChildIndex] > heap[maxChildIndex]) {
        maxChildIndex = leftChildIndex;
    }

    if (rightChildIndex < size && heap[rightChildIndex] > heap[maxChildIndex]) {
        maxChildIndex = rightChildIndex;
    }

    if (maxChildIndex != index) {
        swap(heap[maxChildIndex], heap[index]);
        heapify(maxChildIndex);
    }
}

int Heap::pop() {
    if (size > 0) {
        int poppedElement = heap[0];
        heap[0] = heap[size - 1];
        size--;
        heapify(0);
        return poppedElement;
    }
    return -1;
}


int Heap::popIterative() {
    int poppedElement = heap[0];
    heap[0] = heap[size - 1];
    int index = 0;
    int leftChildIndex = index * 2 + 1;
    int rightChildIndex = index * 2 + 2;
    int maxChildIndex = index;

    if (leftChildIndex < size && heap[leftChildIndex] > heap[maxChildIndex]) {
        maxChildIndex = leftChildIndex;
    }

    if (rightChildIndex < size && heap[rightChildIndex] > heap[maxChildIndex]) {
        maxChildIndex = rightChildIndex;
    }

    while (maxChildIndex != index) {
        swap(heap[index], heap[maxChildIndex]);
        index = maxChildIndex;
        leftChildIndex = index * 2 + 1;
        rightChildIndex = index * 2 + 2;
        maxChildIndex = index;
        if (leftChildIndex < size && heap[leftChildIndex] > heap[maxChildIndex]) {
            maxChildIndex = leftChildIndex;
        }
        if (rightChildIndex < size && heap[rightChildIndex] > heap[maxChildIndex]) {
            maxChildIndex = rightChildIndex;
        }
    }
    return poppedElement;
}


int main() {
    Heap heap;
    heap.insert(2);
    heap.insert(5);
    heap.insert(9);
    heap.insert(7);
    heap.insert(3);
    heap.insert(10);
    heap.printHeap();
    cout << heap.pop() << endl;
    cout << heap.pop() << endl;
    cout << heap.pop() << endl;
    cout << heap.pop() << endl;
    cout << heap.pop() << endl;
    cout << heap.pop() << endl;
    cout << heap.pop() << endl;
    cout << heap.pop() << endl;
    return 0;
}
