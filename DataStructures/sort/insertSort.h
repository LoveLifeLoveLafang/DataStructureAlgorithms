//
// Created by nicholas on 2018/11/28.
//

#ifndef SORT_INSERTSORT_H
#define SORT_INSERTSORT_H

#include "swap.h"
#include <cstdlib>

template<typename T>
void insertSort(T arr[], int size) {
    for (int i = 1; i < size; ++i) {
        int j = 0;
        while(j < i && arr[j] < arr[i]) {
            j++;
        }

        T temp = arr[i];
        for (int k = i-1; k >= j ; k--) {
            arr[k+1] = arr[k];
        }

        arr[j] = temp;
    }
}

#endif //SORT_INSERTSORT_H
