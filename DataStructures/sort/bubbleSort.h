//
// Created by nicholas on 2018/11/28.
//

#ifndef SORT_BUBBLESORT_H
#define SORT_BUBBLESORT_H

#include "swap.h"

//从小到大
template<typename T>
void bubbleSort(T arr[], int size) {
    int i = 0;
    while( i < size ) {
        while(i < size - 1) {
            if (arr[i] > arr[i+1])
                swap(arr[i], arr[i+1]);
            i++;
        }
        size--;
        i = 0;
    }
}


#endif //SORT_BUBBLESORT_H
