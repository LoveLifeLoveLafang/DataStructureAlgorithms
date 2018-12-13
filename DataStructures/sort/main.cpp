#include <iostream>
//#include "gnome.h"
//#include "bubbleSort.h"
//#include "quickSort.h"
//#include "selectionSort.h"
//#include "insertSort.h"
//#include "shellSort.h"
//#include "bucketSort.h"
//#include "mergeSort.h"
//#include "heap.h"
//#include "heapSort.h"
//#include "countSort.h"
#include "radixSort.h"

using namespace std;

int main() {
    int arr[6] = {96, 12, 31, 75, 26, 31};
    int array[10] = {100, 20, 10, 70, 30, 50, 80, 60, 90, 40};

    /*
     * 地精排序
     * */
//    gnomeSort(arr, 6);
//    for(auto &val : arr ) {
//        cout << val << endl;
//    }

    /*
     * 冒泡排序
     * */
//    bubbleSort(arr, 6);
//    for (auto &val : arr) {
//        cout << val << endl;
//    }


    /*
     * 快速排序
     * */
//    quickSort(arr, 0, 5);
//    for (auto &val : arr) {
//        cout << val << endl;
//    }


    /*
     * 选择排序
     * */
//    selectionSort(arr, 6);
//    for (auto &val: arr) {
//        cout << val << endl;
//    }


    /*
     * 插入排序
     * */
//    insertSort(array, 10);
//    for (auto &val : array) {
//        cout << val << endl;
//    }

    /*
     * 希尔排序
     * */
//    shellSort(array, 10);
//    for (auto &val : array) {
//        cout << val << endl;
//    }

    /*桶排序*/
//    bucketSort(array, 10, 100);
//    std::cout << std::endl;
//    for (auto &val : array) {
//        cout << val << endl;
//    }

    /*
     * 基数排序
     * */
    radixSort(array, 10);
    for (int i = 0; i < 10; ++i) {
        std::cout << array[i] << std::endl;
    }



    /*
     * 计数排序
     * */
//    countSort(arr, 6);
//    for (int j = 0; j < 6; ++j) {
//        std::cout << arr[j] << std::endl;
//    }

    /*
     * 归并排序
     * */
//    int size = sizeof(array) / sizeof(int);
//    mergeSort(array, size);
//    for (auto &val : array) {
//        std::cout << val << endl;
//    }
    /*
     * 堆排序
     * */
//    MyHeap<int> h = MyHeap<int>(array, 10);
//
//    for(int i = 0; i < 10; ++i) {
//        array[i] = h.extractMax();
//    }
//    for(int i = 0; i < 10; ++i) {
//        std::cout << array[i] << " ";
//    }
//    std::cout << std::endl;

//    heapSort(arr, 6);
//    for (int i = 0; i < 6; ++i) {
//        std::cout << arr[i] << " ";
//    }
//    std::cout << std::endl;

    return 0;
}