#include <bits/stdc++.h>

using namespace std;
#define int long long
#define MAX 100000

int partition(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = (low - 1);

    for (int j = low; j <= high - 1; j++) {
        if (arr[j] < pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    return (i + 1);
}

void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

int32_t main() {
    int a[] = {58, 4, 13, 32, 91};
    quickSort(a, 0, 4);
    for (auto i : a) cout << i << ' ';
}