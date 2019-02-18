#ifndef Sorting_hpp
#define Sorting_hpp

#include <stdio.h>
#include "wordInfo.hpp"
class Sorting {
    friend class wordInfo;
public:
    void insertionSort(wordInfo *arr[], int len);
    void selectionSort(wordInfo *arr[], int len);
    void quickSort(wordInfo *arr[], int beg, int end);
    int partition(wordInfo *arr[], int beg, int end); // used by quicksort
    void mergeSort(wordInfo *arr[], int l1, int l2);
    void merge(wordInfo *arr[], int l, int m, int r); // used by mergesort
};
#endif /* Sorting_hpp */
