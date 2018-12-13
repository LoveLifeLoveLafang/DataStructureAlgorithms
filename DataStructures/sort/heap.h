//
// Created by nicholas on 2018/11/28.
//

#ifndef SORT_HEAPSORT_H
#define SORT_HEAPSORT_H

#include <iostream>
#include <cassert>
#include <algorithm>

template<typename T>
class MyHeap {
public:
    MyHeap(int capacity) {
        this->capacity = capacity;
        this->data = new T(capacity+1);
        this->size = 0;
    }

    MyHeap(T arr[], int n) {
        this->capacity = n;
        this->data = new T[capacity+1];
        for (int i = 1; i < n+1; ++i) {
            data[i] = arr[i-1];
        }
        this->size = n;

        heapify();
    }

    ~MyHeap() {
        delete [] data;
    }

    void shiftUp(int index) {

        while(index > 1 && data[index] > data[index/2]) {
            std::swap(data[index], data[index/2]);
            index /= 2;
        }
    }

    void shiftDown(int index) {

        while(2 * index <= size) {
            int j = 2 * index;
            if (j + 1 <= size && data[j] < data[j + 1])
                j++;
            if (data[index] >= data[j])
                break;

            std::swap(data[index], data[j]);
            index = j;
        }

    }

    void heapify() {
        int start = size / 2;
        while(start >= 1) {
            shiftDown(start);
            start--;
        }
    }

    bool isEmpty() {
        return size == 0;
    }

    void push(T ele) {
        //限压入队列，再进行向上调整
        assert(size + 1 <= capacity);
        this->data[size + 1] = ele;
        this->size++;
        shiftUp(size);
    }

    T extractMax() {
        assert(size >= 1);
        T max = this->data[1];
        std::swap(data[1], data[size]);
        this->size--;
        this->shiftDown(1);
        return max;
    }


private:
    T* data;
    int size;
    int capacity;
};

#endif //SORT_HEAPSORT_H
