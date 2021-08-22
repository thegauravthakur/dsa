#include <bits/stdc++.h>

using namespace std;

void selectionSort(int *array, const int size) {
    for (int i = 0; i < size - 1; i++) {
        pair<int, int> placeholder = {INT32_MAX, -1};
        for (int j = i; j < size; j++) {
            if (array[j] < placeholder.first) {
                placeholder.first = array[j];
                placeholder.second = j;
            }
        }
        swap(array[i], array[placeholder.second]);
    }
}

int main() {
    int a[] = {5, 4, 1, 3, 2, 1};
    int size = sizeof a / sizeof a[0];
    selectionSort(a, size);
    for (auto i : a) cout << i << ' ';
    return 0;
}