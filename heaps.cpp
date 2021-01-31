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

    void heapify(const int *b, int arraySize);

    int *heapSort(int *b, int arraySize, const string &dir = "inc");
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

int Heap::extractMax() {
    if (size > 0) {
        const int removedItem = a[0];
        a[0] = a[size - 1];
        size--;
        int currentIndex = 0;
        int leftChildIndex = (2 * currentIndex) + 1;
        int rightChildIndex = (2 * currentIndex) + 2;
        while ((leftChildIndex < size && a[leftChildIndex] > a[currentIndex]) ||
               (rightChildIndex < size && a[rightChildIndex] > a[currentIndex])) {
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

void Heap::heapify(const int *b, int arraySize) {
    for (auto i = 0; i < arraySize; i++) {
        a[i] = b[i];
    }
    size = arraySize;
    for (int i = arraySize - 1; i >= 0; i--) {
        int currentIndex = i;
        int leftChildIndex = (2 * currentIndex) + 1;
        int rightChildIndex = (2 * currentIndex) + 2;
        while ((leftChildIndex < size && a[leftChildIndex] > a[currentIndex]) ||
               (rightChildIndex < size && a[rightChildIndex] > a[currentIndex])) {
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
    }
}

int *Heap::heapSort(int *b, int arraySize, const string &dir) {
    heapify(b, arraySize);
    if (dir == "dec")
        for (int i = 0; i < arraySize; i++) {
            b[i] = extractMax();
        }
    else
        for (int i = 0; i < arraySize; i++) {
            b[arraySize - i - 1] = extractMax();
        }
    return b;
}

int main() {
    Heap heap;
    int a[] = {65, 23, 75, 45, 12, 49, 18, 29};
    const int size = sizeof a / sizeof a[0];
    heap.heapSort(a, size);
    for (int i : a) cout << i << ' ';
    cout << endl;
    heap.heapSort(a, size, "dec");
    for (int i : a) cout << i << ' ';
    cout << endl;
}