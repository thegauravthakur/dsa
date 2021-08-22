#include <bits/stdc++.h>

using namespace std;

void bubbleSort(int *array, int size) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (array[j] > array[j + 1]) swap(array[j], array[j + 1]);
        }
    }
}

int main() {
    int a[] = {5, 4, 3, 2, 1};
    int size = sizeof a / sizeof a[0];
    bubbleSort(a, size);
    for (auto i : a) cout << i << ' ';
    return 0;
}