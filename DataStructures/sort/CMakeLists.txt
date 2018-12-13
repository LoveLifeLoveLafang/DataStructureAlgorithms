cmake_minimum_required(VERSION 3.8)
project(sort)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp gnome.h bubbleSort.h selectionSort.h quickSort.h insertSort.h mergeSort.h heap.h shellSort.h bucketSort.h radixSort.h countSort.h swap.h heapSort.h)
add_executable(sort ${SOURCE_FILES})