#include <bits/stdc++.h>

using namespace std;
const int MAX_SIZE = 100;

class Heap {
    int size;
    int a[MAX_SIZE];

public:
    Heap() : a{} {
        size = 0;
    }

    void insert(int value);

    int extractMax();

    void printArray();

    [[nodiscard]] bool isEmpty() const;
};

void Heap::insert(int value) {
    a[size] = value;
    int currentIndex = size;
    int parentIndex = (currentIndex - 1) / 2;
    while (parentIndex >= 0 && a[currentIndex] > a[parentIndex]) {
        swap(a[currentIndex], a[parentIndex]);
        currentIndex = parentIndex;
        parentIndex = (currentIndex - 1) / 2;
    }
    size++;
}

void Heap::printArray() {
    for (int i = 0; i < size; i++)
        cout << a[i] << ' ';
    cout << endl;
}

//
int Heap::extractMax() {
    if (size > 0) {
        const int removedItem = a[0];
        a[0] = a[size - 1];
        size--;
        int currentIndex = 0;
        int leftChildIndex = (2 * currentIndex) + 1;
        int rightChildIndex = (2 * currentIndex) + 2;
        while ((leftChildIndex < size && a[leftChildIndex] > a[currentIndex]) || (rightChildIndex < size && a[rightChildIndex] > a[currentIndex]) ) {
            if (a[leftChildIndex] > a[rightChildIndex]) {
                swap(a[leftChildIndex], a[currentIndex]);
                currentIndex = leftChildIndex;
                leftChildIndex = (2 * currentIndex) + 1;
                rightChildIndex = (2 * currentIndex) + 2;
            } else {
                swap(a[rightChildIndex], a[currentIndex]);
                currentIndex = rightChildIndex;
                leftChildIndex = (2 * currentIndex) + 1;
                rightChildIndex = (2 * currentIndex) + 2;
            }
        }
        return removedItem;
    }
}

bool Heap::isEmpty() const {
    return size != 0;
}

int main() {
    Heap heap;
    heap.insert(32);
    heap.insert(12);
    heap.insert(24);
    heap.insert(19);
    heap.insert(15);
    heap.insert(40);
    heap.insert(27);
    heap.insert(39);
    heap.insert(50);
    while (heap.isEmpty()) {
       cout << heap.extractMax() << ' ' ;
    }
    cout << endl;
}