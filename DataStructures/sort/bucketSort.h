//
// Created by nicholas on 2018/11/28.
//

#ifndef SORT_BUCKETSORT_H
#define SORT_BUCKETSORT_H

#include <iostream>
#include <vector>

template<typename T>
void bucketSort(T arr[], int n, double boundary) {
    std::vector<double> vec(n);
    for (int i = 0; i < n; ++i) {
        vec[i] = arr[i] / boundary;
    }

    std::vector<double> res[n];
    for (int i = 0; i < n; ++i) {
        int index = n * vec[i];
        res[index].push_back(arr[i]);
    }

    for (int i = 0; i < n; ++i) {
        if (!res[i].empty()) {
            std::sort(res[i].begin(), res[i].end());
        }
    }

    int index = 0;
    for (int i = 0; i < n; ++i) {
        int length = res[i].size();
        for (int j = 0; j < length; ++j) {
            arr[index] = res[i][j];
            index++;
        }
    }
}

#endif //SORT_BUCKETSORT_H
