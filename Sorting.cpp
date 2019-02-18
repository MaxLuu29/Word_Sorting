#include "Sorting.hpp"
void Sorting::quickSort(wordInfo* arr[], int beg, int end) {
    if (beg < end) {
        int p = partition(arr, beg, end);
        quickSort(arr, beg, p - 1);
        quickSort(arr, p + 1, end);
    }
}

int Sorting::partition(wordInfo* arr[], int beg, int end) {
    int pivot = arr[end]->ct;
    int i = (beg - 1);
    for (int j = beg; j <= end - 1; j++) {
        if (arr[j]->ct >= pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[end]);
    return (i + 1);
}

void Sorting::selectionSort(wordInfo* arr[], int len) {
    int mini;
    for (int i = 0; i < len-1; i++) {
        mini = i;
        for (int j = i+1; j < len; j++) {
            if (arr[j]->ct > arr[mini]->ct) {
                mini = j;
            }
        }
        swap(arr[mini], arr[i]);
    }
}

void Sorting::insertionSort(wordInfo* arr[], int len) {
    int i, j;
    wordInfo* key;
    for (i = 1; i < len; i++) {
        key = arr[i];
        j = i-1;
        while (j >= 0 && arr[j]->ct < key->ct) {
            arr[j+1] = arr[j];
            j = j-1;
        }
        arr[j+1] = key;
    }
}

void Sorting::merge(wordInfo* arr[], int l, int m, int r) {
    wordInfo** temp = new wordInfo*[r - l + 1];
    int i = l, j = m + 1;
    int k = 0;
    
    while (i <= m && j <= r) {
        if (arr[i]->ct >= arr[j]->ct)
            temp[k++] = arr[i++];
        else
            temp[k++] = arr[j++];
    }
    while (i <= m)
        temp[k++] = arr[i++];
    while (j <= r)
        temp[k++] = arr[j++];
    for (k = 0, i = l; i <= r; ++i, ++k)
        arr[i] = temp[k];
    delete []temp;
}

void Sorting::mergeSort(wordInfo* arr[], int l, int r) {
    int m;
    if (l < r) {
        m = (r+l)/2;
        mergeSort(arr, l, m);
        mergeSort(arr, m+1, r);
        merge(arr, l, m, r);
    }
}
