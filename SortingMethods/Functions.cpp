//
//  Functions.cpp
//  SortingMethods
//
//  Created by viorel maxim on 2020-07-09.
//  Copyright © 2020 viorel maxim. All rights reserved.
//

#include "iostream"
#include "Functions.hpp"
void swap(int *a, int *b){
    int temp;
    temp=*a;
    *a=*b;
    *b=temp;
    
//    int temp = *x;
//    *x = *y;
//    *y = temp;
}

void bubleSort(int data[], int n){
    
    int flag{0};
    for(int i{0};i<n-1;i++){
        for(int j{0};j<n-1-i;j++){
            if(data[j]>data[j+1]){
                swap(&data[j],&data[j+1]);
                flag=1;
            }
        }
        if(flag==0) break;
    }
}


void show(int data[], int n){
    for(int i{0};i<n;i++)
        std::cout << data[i] << " | ";
    std::cout <<std::endl;
}


void insertionSort(int data[], int n){
    int x{0},j{0};
    
    for(int i{1};i<n;i++){
        j = i-1;
        x = data[i];
        
        while (j>-1 && data[j] > x) {
            data[j+1] = data[j];
            j--;
        }
        data[j+1] = x;
    }

}


void selectionSort(int *data, int n){
    int k{0};
    for(int i{0};i<n-1;i++){
        for(int j=k=i;j<n;j++){
            if(data[j] < data[k])
                k=j;
        }
        swap(&data[i], &data[k]);
    }
}


int partition(int *data, int low, int high){
    int pivot = data[low];
    int i = low, j = high;
    
    do {
        do {
            i++;
        } while (data[i] <= pivot);
        
        do {
            j--;
        } while (data[j] > pivot);
        
        if(i<j)
            swap(&data[i], &data[j]);
        
    } while (i<j);
    
    swap(&data[low], &data[j]);
    
    return j;
}

void quickSort(int *data, int low, int high){
    if (low < high){
        int j = partition(data, low, high);
        quickSort(data, low, j);
        quickSort(data, j+1, high);
    }
   
}
