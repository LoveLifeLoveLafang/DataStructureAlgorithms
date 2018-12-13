//
// Created by nicholas on 2018/11/28.
//

#ifndef SORT_SELECTIONSORT_H
#define SORT_SELECTIONSORT_H

#include "swap.h"


/*
 * 思路：
 * 从未排序序列中选择一个最小的元素，将该元素与未排序序列首元素进行交换
 * */
template<typename T>
void selectionSort(T arr[], int n) {
    for (int i = 0; i < n - 1; ++i) {
        int minIndex = i;
        T min = arr[i];
        for (int j = i + 1; j < n; ++j) {
            if (arr[j] < min) {
                minIndex = j;
                min= arr[j];
            }
        }
        swap(arr[i], arr[minIndex]);
    }
}

#endif //SORT_SELECTIONSORT_H
