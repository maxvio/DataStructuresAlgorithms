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
    class iterator;
public:
    Array();
    Array(int size);
    ~Array();
    Array(const Array<T>&); //copy constructor
    Array<T> &operator= (const Array<T> &); // assignement
    Array<T> & operator = (T);         // scalar assignment
    
    const T& operator()(int i) const;
    T& operator()(int i);
    // --------------- itearator ------------
    iterator rend() {
        return iterator(-1, *this);
    }

    iterator begin() {
        return iterator(0, *this);
    }
    iterator end() {
        return iterator(length, *this);
    }
    

    iterator rbegin() {
        return iterator(length-1, *this);
    }
    
    T &get(int pos) {
        return data[pos];
    }
    
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
    float getAverage();
    float norm();
    
    // --------------- search operations ---------------
    int isSorted();
    int findIndex(T value);
    
    int iterativeBinarySaerch(T key, int low);
    int recursiveBinarySaerch(T key, int low,int high);
    
    // ---------- operators overloading -------------
    Array<T>& operator+(const Array<T>& rh);
    Array<T>& operator-(const Array<T>& rh);
//    Array<T>& operator*(const Array<T>& rh); //element-wise multiplication
    T operator*(const Array<T>& rh); //vector multiplication
    Array<T>& operator/(const Array<T>& rh); //element-wise division ???
    
    Array<T>& productElementWise(const Array<T>& rh);
    
    // ---------- array scalar operation ------------------
    Array<T>& operator+(const T& rh); // adition matrix with scalar
    Array<T>& operator-(const T& rh); // substraction matrix with scalar
    Array<T>& operator*(const T& rh); // multiplication matrix with scalar
    Array<T>& operator/(const T& rh); // division vector with scalar

    //---------------- set operation ---------------
    Array<T>& unionArray(Array<T> &rh);
    Array<T>& intersectionArray(Array<T> &rh);
    Array<T>& diffArray(Array<T> &rh);
    Array<T>& concatArray(Array<T> &rh);
    
    // --------------- sorting method ---------------
    void bubleSort();
    void insertionSort();
    void selectionSort();
    void quickSort(int low, int high);
    Array<T>& mergeSort(Array<T>& right);
    Array<T>& mergeSort(int low, int mid, int high);
    Array<T>& countSort();
    Array<T>& shellSort();
    
    // --------------- utility tools -------------
    void show();
    void showIterator();
    void showList();
    void showStartPosition(int pos);
    void swap(T &a, T &b);
    
    // -------------- boolean functions ----------
    int isUnit();
    
protected:
    int  checkIndex(int i) const;
    bool isFreePosition();
    int partition(int low, int high);
    void initialize();
    
};



template<class T>
class Array<T>::iterator {
private:
    int i_pos;
    Array<T> &m_array;
public:
    iterator(int pos, Array<T> &array_ref) :
            i_pos(pos), m_array(array_ref) {}

    iterator operator++(int) {
        iterator old = *this;
        ++(*this);
        return old;
    }

    //prefix
    iterator& operator++() {
        ++i_pos;
        return *this;
    }
    
    iterator operator--(int) {
        iterator old = *this;
        --(*this);
        return old;
    }
    
    //prefix
    iterator& operator--() {
        --i_pos;
        return *this;
    }

    bool hasNext() {
        if(getNextPos() !=-1)
            return true;
        return false;
    }
    

    
    bool hasPrev() {
        if(getPrevPos() !=-1)
            return true;
        return false;
    }
    
    T& operator*() {
        return m_array.get(i_pos);
    }

    bool operator==(const iterator &other) const {
        return i_pos == other.i_pos;
    }

    bool operator!=(const iterator &other) const {
        return !(*this == other);
    }
    
protected:
    
    int getNextPos() {
        return i_pos < m_array.length ? ++i_pos : -1;
    }
    
    int getPrevPos() {
        return (i_pos > 0 && i_pos < m_array.length) ? --i_pos : -1;
    }
    
};
#endif /* Array_hpp */
