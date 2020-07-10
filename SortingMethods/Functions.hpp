//
//  Functions.hpp
//  SortingMethods
//
//  Created by viorel maxim on 2020-07-09.
//  Copyright © 2020 viorel maxim. All rights reserved.
//

#ifndef Functions_hpp
#define Functions_hpp

#include <stdio.h>

void swap(int a, int b);
void bubleSort(int *data, int n);
void insertionSort(int *data, int n);
void selectionSort(int *data, int n);

int partition(int *data, int low, int high);
void quickSort(int *data, int low, int high);

void show(int data[], int n);

#endif /* Functions_hpp */
