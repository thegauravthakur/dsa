#include <bits/stdc++.h>

using namespace std;
#define int long long
#define MAX 100000

void mergeArray(int *array, int left, int right) {
    int mid = (left + right) / 2;
    int temp[MAX];
    int i = left, j = mid + 1, k = left;
    while (i <= mid and j <= right) {
        if (array[i] < array[j])
            temp[k++] = array[i++];
        else temp[k++] = array[j++];
    }

    while (i <= mid) temp[k++] = array[i++];
    while (j <= right) temp[k++] = array[j++];

    for (int p = left; p <=right; p++) {
        array[p] = temp[p];
    }
}

void mergeSort(int *array, int left, int right) {
    if (left >= right) return;
    int mid = (left + right) / 2;
    mergeSort(array, left, mid);
    mergeSort(array, mid + 1, right);
    mergeArray(array, left, right);
}

int32_t main() {
    int a[] = {5, 4, 1, 3, 2, 9};
    mergeSort(a, 0, 5);
    for (auto i : a) cout << i << ' ';
    return 0;
}