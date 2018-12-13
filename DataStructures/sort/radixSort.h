//
// Created by nicholas on 2018/11/28.
//

#ifndef SORT_RADIXSORT_H
#define SORT_RADIXSORT_H

/*
 * 基本思想：分别以个位、十位、百位、千位...进行计数排序，
 * 所以需要获取到最大值的位数, 而且位数不够的需要进行补0
 * */
 template<typename T>
 T getMax(T arr[], int n) {
     int i = 0;
     T res = arr[0];
     while(i < n) {
         if (res < arr[i]) {
             res = arr[i];
         }
         i++;
     }
     return res;
 }

 /*
  * 计数排序
  * */
 template<typename T>
 void countSort(T arr[], int n, int exp) {
     int temp[n]; //用于存储排序的临时数组

     int buckets[10] = {0};

     for (int i = 0; i < n; ++i) {
         buckets[(arr[i] / exp) % 10]++;
     }

     for (int j = 1; j < 10; ++j) {
         buckets[j] += buckets[j-1];
     }

     for (int k = n-1; k >= 0; k--) {
         temp[buckets[(arr[k] / exp) % 10] - 1] = arr[k]; //次处索引不能忘记减一
         buckets[(arr[k] / exp) % 10]--;
     }

     for (int l = 0; l < n; ++l) {
         arr[l] = temp[l];
     }

 }

 template<typename T>
 void radixSort(T arr[], int n) {
     // 用于求位数
     int exp;

     int max = getMax(arr, n);

     for (exp = 1; max/exp > 0; exp *= 10) {
         countSort(arr, n, exp);
     }
 }

#endif //SORT_RADIXSORT_H
