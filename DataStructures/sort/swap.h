//
// Created by nicholas on 2018/11/28.
//

#ifndef SORT_SWAP_H
#define SORT_SWAP_H

template<typename T>
void swap(T &a, T &b) {
    T temp = a;
    a = b;
    b = temp;
}

#endif //SORT_SWAP_H

