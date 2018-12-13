//
// Created by nicholas on 2018/11/28.
//

#ifndef SORT_COUNTSORT_H
#define SORT_COUNTSORT_H

#include <cstring>

template<typename T>
void countSort(T arr[], int n) {

    /*
     * 先求出最大值和最小值
     * */
    int min = arr[0], max = arr[0];
    for (int i = 0; i < n; ++i) {
        if (arr[i] < min)
            min = arr[i];
        if (arr[i] > max)
            max = arr[i];
    }

    T *temp = new T[max + 1];
    T *res = new T[n];

    memset(temp, 0, sizeof(temp));
    for (int i = 0; i < n; ++i) {
        temp[arr[i]]++;
    }

    for (int j = min; j < max; ++j) {
        temp[j+1] += temp[j];
    }

    for (int k = n - 1; k >= 0 ; k--) {
        res[temp[arr[k]] - 1] = arr[k];
        temp[arr[k]]--;
    }

    for (int i = 0; i < n; ++i) {
        arr[i] = res[i];
    }

    delete [] res;

    delete [] temp;
}

#endif //SORT_COUNTSORT_H
