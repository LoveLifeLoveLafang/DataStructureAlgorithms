//
// Created by nicholas on 2018/12/2.
//

#ifndef SORT_HEAPSORT_H
#define SORT_HEAPSORT_H

#include <iostream>
#include <algorithm>


template<typename T>
void shiftDown(T arr[], int length, int index) {
    //从0开始计数
    while((2 * index + 1) < length) {
        int i = 2 * index + 1;
        if ((i+1) < length && arr[i+1] > arr[i])
            i++;

        if (arr[index] >= arr[i])
            break;
        std::swap(arr[index], arr[i]);
        index = i;
    }
}

template<typename T>
void heapify(T arr[], int n) {
    int start = (n - 2) / 2;
    while(start >= 0) {
        shiftDown(arr, n, start);
        start--;
    }
}

template<typename T>
void heapSort(T arr[], int n) {

    heapify(arr, n);

    while(n > 1) {
        std::swap(arr[0], arr[n-1]);
        n--;
        shiftDown(arr, n, 0);
    }
}

#endif //SORT_HEAPSORT_H
