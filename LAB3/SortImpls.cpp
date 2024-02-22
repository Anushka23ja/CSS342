#include <vector>
#include<iostream>

using namespace std;

void BubbleSort(vector<int> &arr, int index1, int index2) {
    for (int i = index1; i < index2 ; i++) { 
        for (int j = index1; j < index2 - i - 1; j++) { 
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
            }
        }
    }
}

void InsertionSort(vector<int> &arr, int index1, int index2) {
    for (int i = index1 + 1; i <= index2; i++) {
        int a = arr[i];
        int j = i - 1;
        while (j >= index1 && arr[j] > a) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = a;
    }
}

void merge(vector<int>& arr, int l, int m, int r) {
    int n1 = m - l + 1;
    int n2 = r - m;

    vector<int> L(n1);
    vector<int> R(n2);

    for (int i = 0; i < n1; ++i)
        L[i] = arr[l + i];
    for (int j = 0; j < n2; ++j)
        R[j] = arr[m + 1 + j];

    int i = 0, j = 0, k = l;

    while (i < n1 && j < n2) { 
        if (L[i] < R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1) { 
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2) { 
        arr[k] = R[j];
        j++;
        k++;
    }
}

void MergeSort(vector<int>& arr, int l, int r) {
    if (l < r) {
        int m = l + (r - l) / 2;
        MergeSort(arr, l, m);
        MergeSort(arr, m + 1, r);
        merge(arr, l, m, r);
    }
}

int partition(vector<int> &arr, int low, int high) {
    int pivot = arr[high];
    int i = low - 1;
    for (int j = low; j < high; j++) {
        if (arr[j] <= pivot) {
            ++i;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    return i + 1;
}

void QuickSort(vector<int> &arr, int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        QuickSort(arr, low, pi - 1);
        QuickSort(arr, pi + 1, high);
    }
}

void ShellSort(vector<int> &arr, int index1, int index2) {
    int n = index2 - index1 + 1;
    for (int gap = n / 2; gap > 0; gap /= 2) {
        for (int i = gap; i < n; ++i) {
            int temp = arr[index1 + i];
            int j;
            for (j = i; j >= gap && arr[index1 + j - gap] > temp; j -= gap) {
                arr[index1 + j] = arr[index1 + j - gap];
            }
            arr[index1 + j] = temp;
        }
    }
}
