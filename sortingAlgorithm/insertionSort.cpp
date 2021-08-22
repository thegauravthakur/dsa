#include <bits/stdc++.h>

using namespace std;

void insertionSort(int *array, const int size) {
    for (int i = 1; i < size; i++) {
        int j = i;
        while (j > 0 and array[j] < array[j - 1])
            swap(array[j], array[j - 1]), j--;
    }
}

int main() {
    int a[] = {5, 4, 1, 3, 2, 1};
    int size = sizeof a / sizeof a[0];
    insertionSort(a, size);
    for (auto i : a) cout << i << ' ';
    return 0;
}