//
// Created by nicholas on 2018/11/28.
//

#ifndef SORT_GNOME_H
#define SORT_GNOME_H

#include "swap.h"

template<typename T>
void gnomeSort(T arr[], int size) {
    for( int i = 0; i < size - 1;) {
        if ( arr[i] <= arr[i+1] )
            i++;
        else {
            swap(arr[i], arr[i + 1]);
            if ( i > 0)
                i--;
        }
    }
}


#endif //SORT_GNOME_H
