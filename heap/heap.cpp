#include <bits/stdc++.h>

using namespace std;

class Heap {
    vector<int> heap;

public:
    void insert(int);

    void printHeap();
};

void Heap::insert(int value) {
    // a complete binary tree with one node is always a binary tree
    if (heap.empty())
        heap.push_back(value);
    else {
        // add element to the leaf
        heap.push_back(value);
        // get the index of last item
        unsigned long long index = heap.size() - 1;
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
    for (auto item: heap) cout << item << " ,";
    cout << endl;
}

int main() {
    Heap heap;
    heap.insert(5);
    heap.insert(10);
    heap.insert(7);
    heap.insert(3);
    heap.insert(9);
    heap.insert(2);
    heap.printHeap();
    return 0;
}
