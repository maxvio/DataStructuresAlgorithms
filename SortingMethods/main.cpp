//
//  main.cpp
//  SortingMethods
//
//  Created by viorel maxim on 2020-07-09.
//  Copyright © 2020 viorel maxim. All rights reserved.
//

#include <iostream>

#include "Functions.hpp"

int main(int argc, const char * argv[]) {
    // insert code here...
//    std::cout << "Hello, World!\n";
    
    int n = 11;
//    int *a = new int[n] {8,5,7,3,2};
//    int *a = new int[n] {11,13,7,12,16,9,24,5,10,3};
    int *a = new int[n]{3, 70, 9, 100, 16, 5, 12, 4, 11, 2,INT_MAX};
//    show(a,n);
    std::cout << "--------- Buble sort -------- " << std::endl;
//    bubleSort(a,n);
    std::cout << "--------- Insertion sort -------- " << std::endl;
//    insertionSort(a,n);
    std::cout << "--------- Selection sort -------- " << std::endl;
//    selectionSort(a, n);
    std::cout << "--------- Quick sort -------- " << std::endl;
    quickSort(a, 0, n-1);
    show(a,n-1);
    
    return 0;
}
