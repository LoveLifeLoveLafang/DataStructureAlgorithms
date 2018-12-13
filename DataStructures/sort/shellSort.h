//
// Created by nicholas on 2018/11/28.
//

#ifndef SORT_SHELLSORT_H
#define SORT_SHELLSORT_H

template<typename T>
void shellSort(T arr[], int size) {
    int i, j , gap;
    for (gap = size/2; gap > 0 ; gap /= 2) {
        for (i = 0; i < gap; ++i) {
            for (j = i+gap; j < size; j += gap) {
                int temp = arr[j];
                int k = j - gap;
                while(k >= i && temp < arr[k]) {
                    arr[k + gap] = arr[k];
                    k -= gap;
                }
                arr[k + gap] = temp;
            }
        }
    }
}

#endif //SORT_SHELLSORT_H
