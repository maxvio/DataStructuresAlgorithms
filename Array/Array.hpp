//
//  Array.hpp
//  Array
//
//  Created by viorel maxim on 2020-07-12.
//  Copyright © 2020 viorel maxim. All rights reserved.
//

#ifndef Array_hpp
#define Array_hpp

#include <stdio.h>

template<class T>
class Array{
private:
    T *data;
    int size;
    int length;
    
    
public:
    Array();
    Array(int size);
    ~Array();
    Array(const Array<T>&); //copy constructor
    Array<T> &operator= (const Array<T> &); // assignement
    Array<T> & operator = (T);         // scalar assignment
    
    const int& operator[](int i) const;
    int& operator[](int i);
    
    // --------- getter & setter ---------
    int getSize();
    int getLength();
    T getData();
    
    void setValue(int index, T value);
    void setLength(int value);
    void updateLength(int value);
    void setSize(int n);//need to be implemented
    
    void resize(int size);
    
    // --------- getter & setter ---------
    
    //---------- methods working with single value ---------
    void pushValue(T value);
    void insertAtIndex(T value, int index);
    T getAtIndex(int index); // return the item at index
    T deleteAtIndex(int index);
    void append(T value); // append value at the end of the array - not necessary because insertAtIndex insert at the end of array
    
    // --------------- reverse, shift and rotate ------------
    void reverse();
    void leftRotation();
    void rightRotation();
    void leftShift();
    void rightShift();
    
    // --------------- array operations ---------------
    T getMax();
    T getMin();
    T getSum();
    double getAverage();
    
    // --------------- search operations ---------------
    int isSorted();
    int findIndex(T value);
    
    int iterativeBinarySaerch(T key, int low);
    int recursiveBinarySaerch(T key, int low,int high);
    
    // ---------- operators overloading -------------
    Array<T> &operator+ (const Array<T>&);
    Array<T> &operator- (const Array<T>&);
    Array<T> &operator* (const Array<T>&);
    Array<T> &operator/ (const Array<T>&);

    //---------------- set operation ---------------
    Array<T>& unionArray(Array<T> &rch);
    Array<T>& intersectionArray(Array<T> &rch);
    Array<T>& diffArray(Array<T> &rch);
    Array<T>& concatArray(Array<T> &rch);
    
    // --------------- sorting method ---------------
    void bubleSort();
    void insertionSort();
    void selectionSort();
    void quickSort(int low, int high);
    Array<T>& mergeSort(Array<T> &right);
    Array<T>& mergeSort(int low, int mid, int high);
    Array<T>& countSort();
    Array<T>&  shellSort();
    
    // --------------- utility tools -------------
    void show();
    void showList();
    void showStartPosition(int pos);
    
    void swap(T &a, T &b);
   

    
protected:
    int  checkIndex(int i) const;
    bool isFreePosition();
    int partition(int low, int high);
    void initialize();
    
};

#endif /* Array_hpp */
