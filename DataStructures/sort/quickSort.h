//
// Created by nicholas on 2018/11/28.
//

#ifndef SORT_QUICKSORT_H
#define SORT_QUICKSORT_H

#include "swap.h"


template<typename T>
void quickSort(T arr[], int start, int end) {
    if (start >= end)
        return;
    T pivo = arr[start];
    int i = start;
    int j = end;
    while(start < end) {
        while(start < end && arr[end] >= pivo)
            --end;
        arr[start] = arr[end];
        while(start < end && arr[start] <= pivo)
            ++start;
        arr[end] = arr[start];
    }
    arr[start] = pivo;
    quickSort(arr, i, start-1);
    quickSort(arr, start+1, j);
}


#endif //SORT_QUICKSORT_H
