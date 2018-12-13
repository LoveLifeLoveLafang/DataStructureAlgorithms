//
// Created by nicholas on 2018/11/28.
//

#ifndef SORT_MERGESORT_H
#define SORT_MERGESORT_H


template<typename T>
void __merge(T arr[], int start, int mid, int end) {
    T *temp = new T[end - start + 1];

    for (int i = 0; i <= end - start ; ++i) {
        temp[i] = arr[i + start];
    }

    int i = start, j = mid + 1;
    for (int k = start; k <= end; ++k) {
        if (i > mid) {
            arr[k] = temp[j - start];
            j++;
        } else if (j > end) {
            arr[k] = temp[i - start];
            i++;
        } else if (temp[i - start] < temp[j - start]) {
            arr[k] = temp[i - start];
            i++;
        } else {
            arr[k] = temp[j - start];
            j++;
        }
    }
    delete []temp;
}

template<typename T>
void __mergesort(T arr[], int start, int end) {
    if (start >= end)
        return;
    int mid = start + (end-start)/2;
    __mergesort(arr, start, mid);
    __mergesort(arr, mid+1, end);
    __merge(arr, start, mid, end);
}

template<typename T>
void mergeSort(T arr[], int n) {
    __mergesort(arr, 0, n-1);
}



#endif //SORT_MERGESORT_H
