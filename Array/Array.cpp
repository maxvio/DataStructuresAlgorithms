//
//  Array.cpp
//  Array
//
//  Created by viorel maxim on 2020-07-12.
//  Copyright © 2020 viorel maxim. All rights reserved.
//

#include <iostream>
#include "Array.hpp"

//--------------- constructors section -----------------
template<class T>
Array<T>::Array(){
    this->data = new T[100];
    this->length=0;
    for(int i{0};i<size;i++){
        data[i] = (T)0;
    }
}

template<class T>
Array<T>::Array(int size):size(size){
    this->data = new T[size];
    this->length=0;
    for(int i{0};i<size;i++){
        data[i] = (T)0;
    }
}


template<class T>
Array<T>::~Array(){
//    std::cout << " -------- destructor ----" << std::endl;
    delete []data;
    
}

template<class T> //copy constructor
Array<T>::Array(const Array<T>& src) {
    
//    initialize();
    data = new T[src.size];
    
    for (int i{0};i<src.size;i++) {
        data[i] = src.data[i];
    }
    setSize(src.size);
    setLength(src.length);
    
    //    std::cout << "----- copy constructor end ----" << std::endl;
}

template<class T> // assignement
Array<T>& Array<T>::operator= (const Array<T> &a){
    
    delete [] this->data;
    this->data = new T[a.size];
    this->length = a.length;
    
    for(int i{0};i<a.length;i++){
        this->data[i] = a.data[i];
    }
    return (*this);
}

template<class T> // scalar assignement
Array<T> & Array<T>::operator = (T value){
    T *p = data + length;
    while (p > data)
        *--p = value;
    return *this;
}

template<class T>
const int& Array<T>::operator[](int i) const {
    return this->data[checkIndex(i)];
    
}

template<class T>
int& Array<T>::operator[](int i){
    return this->data[checkIndex(i)];
    
}

//--------------- constructors section -----------------

// ------------- protected methods ------------------

template<class T>
int Array<T>::checkIndex(int i) const{
    return (i < 0 || i >= size) ? -1 : 1;
}

template<class T>
bool Array<T>::isFreePosition(){
    return (getSize()-getLength() >= 1) ? true : false;
}

// ------------- protected methods ------------------

// ------------- getter & setter -------------------
template<class T>
int Array<T>::getSize(){
    return this->size;
}

template<class T>
int Array<T>::getLength(){
    return this->length;
}

template<class T>
T Array<T>::getData(){
    return this->data;
}

template<class T>
void Array<T>::setValue(int index, T value){
    this->data[index] = value;
}

template<class T>
void Array<T>::setLength(int value){
    this->length = value;
}

template<class T>
void Array<T>::updateLength(int value){
    this->length +=value;
}

template<class T>
void Array<T>::setSize(int value){
    this->size=value;
}

template<class T>
void Array<T>::resize(int size){
    int* newData = new int[size];
    
    memcpy(newData, this->data, size * sizeof(int) );
    
    setSize(size);
    setLength(length);
    delete [] this->data;
    this->data = newData;
}
// ------------- getter & setter -------------------

//---------- methods working with single value ---------
template<class T>
void Array<T>::pushValue(T value){
    if(getLength()==0){
        this->data[0] = value;
    }
    else if(getLength() < getSize()){
        this->data[getLength()] = value;
    }else{
        return;
    }
//    this->length++;
    updateLength(1);
}


template<class T>
void Array<T>::insertAtIndex(T value, int index){
    if(checkIndex(index) !=-1 && isFreePosition()){
        if(index == getLength()){
            this->data[index+1] = this->data[index];
        }else{
            int i = this->length;
            while(i >= index){
                this->data[i+1] = this->data[i];
                i--;
            }
        }
        this->data[index] = value;
        //        setLength(1);
        updateLength(1);
    }
}


template<class T>
T Array<T>::getAtIndex(int index){
    return this->data[index];
}

template<class T>
T Array<T>::deleteAtIndex(int index){
    T value = this->data[index];
    for(int i=index;i<length;i++){
        this->data[i] = this->data[i+1];
    }
    //    setLength(-1);
    updateLength(-1);
    return value;
}

template<class T>
void Array<T>::append(T value){
    this->data[getLength()] = value;
    //    setLength(1);
    updateLength(1);
}

//---------- methods working with single value ---------


// --------------- reverse, shift and rotate ------------
template<class T>
void Array<T>::reverse(){
    for(int i=0,j=getLength()-1;i<j;i++,j--){
        int temp = this->data[i];
        this->data[i] = this->data[j];
        this->data[j] = temp;
    }
}

template<class T>
void Array<T>::leftRotation(){
    T temp = getAtIndex(0);
    for(int i=0;i<getLength()-1;i++){
        this->data[i] = this->data[i+1];
    }
    this->data[getLength()-1] = temp;
}

template<class T>
void Array<T>::rightRotation(){
    T temp = getAtIndex(getLength()-1);
    for(int i=getLength()-1;i>0;i--){
        this->data[i] = this->data[i-1];
    }
    this->data[0] = temp;
}


template<class T>
void Array<T>::leftShift(){
    for(int i=0;i<getLength()-1;i++){
        this->data[i] = this->data[i+1];
    }
    this->data[getLength()-1] = 0;
    updateLength(-1);
}


template<class T>
void Array<T>::rightShift(){
    for(int i=getLength();i>0;i--){
        this->data[i] = this->data[i-1];
    }
    this->data[0] = 0;

    updateLength(-1);
}

// --------------- reverse, shift and rotate ------------

// --------------- array operations ---------------------
template<class T>
T Array<T>::getMax(){
    T max = this->data[0];
    for(int i=1;i<getLength();i++){
        if(this->data[i] > max)
            max = this->data[i];
    }
    return max;
}

template<class T>
T Array<T>::getMin(){
    T min = this->data[0];
    for(int i=1;i<getLength();i++){
        if(this->data[i] < min)
            min = this->data[i];
    }
    return min;
}


template<class T>
T Array<T>::getSum(){
    T sum = (T)0;
    for(int i=0;i<getLength();i++){
        sum += this->data[i];
    }
    return sum;
}


template<class T>
double Array<T>::getAverage(){
    return (double)getSum()/getLength();
}

// --------------- array operations ---------------------

// --------------- search operations --------------------
template<class T>
int Array<T>::isSorted(){
    for(auto i{1};i<getLength();i++){
        if(data[i] < data[i-1])
            return -1;
    }
    return 1;
}
template<class T>
int Array<T>::findIndex(T value){
    for(int i{0};i<getLength();i++){
        if(this->data[i] == value){
            return i;
        }
    }
    return -1;
}

template<class T>
int Array<T>::iterativeBinarySaerch(T key, int low){
    int high = getLength();
    while (low <= high) {
        int mid = (low+high)/2;
        if(this->data[mid]==key)
            return mid;
        else if(key < data[mid])
            high = mid-1;
        else
            low = mid+1;
    }
    return -1;
}

template<class T>
int Array<T>::recursiveBinarySaerch(T key, int low, int high){
    int mid {0};
    if(low <= high){
        mid = (low+high)/2;
        if(key == this->data[mid])
            return mid;
        else if(key < this->data[mid])
            return recursiveBinarySaerch(key,low, mid-1);
        else
            return recursiveBinarySaerch(key,mid+1,high);
    }
    return -1;
}




// --------------- search operations --------------------

// ---------- operators overloading ---------------------
template<class T>
Array<T>& Array<T>::operator+ (const Array<T>& a){
    if(getSize() == a.size){
        for(int i{0};i<a.length;i++){
            T x = data[i] + a.data[i];
            data[i] = x;
        }
    }
    return (*this);
}

template<class T>
Array<T>& Array<T>::operator- (const Array<T>& a){
    if(getSize() == a.size){
        for(int i{0};i<a.length;i++){
            T x = data[i] - a.data[i];
            data[i] = x;
        }
    }
    return (*this);
}


template<class T>
Array<T>& Array<T>::operator* (const Array<T>& a){
    if(getSize() == a.size){
        for(int i{0};i<a.length;i++){
            T x = data[i] * a.data[i];
            data[i] = x;
        }
    }
    return (*this);
}

template<class T>
Array<T>& Array<T>::operator/ (const Array<T>& a){
    
//    static_cast<float>(a) ----- use it if possible
    if(getSize() == a.size){
        for(int i{0};i<a.length;i++){
            T x = data[i]/a.data[i];
            data[i] = (T)x;
        }
    }
    return (*this);
}


// ---------- operators overloading ---------------------

//---------------- set operation ---------------
template<class T>
Array<T>& Array<T>::unionArray(Array<T> &rch){
    
    auto a1 = (*this);
    
    resize(getSize()+ rch.size);
    
    (*this) = a1;
    
    auto i{0}, j{0};
    while(j<rch.length){
        if(findIndex(rch.data[j]) == -1){
            this->data[i+++a1.getLength()] = rch.data[j];
        }
        j++;
    }
    updateLength(i);
    return (*this);
}

template<class T>
Array<T>& Array<T>::intersectionArray(Array<T> &rch){
    auto a1 = (*this);
    
    auto i{0},k{0};
    while (i++ < getLength()) {
        auto j{0};
        while (j < rch.length) {
            if(a1.data[i] == rch.data[j]){
                this->data[k++] = a1.data[i];
            }
            this->data[i] = 0;
            j++;
        }
    }
    setLength(k);
    
    return (*this);
}


template<class T>
Array<T>& Array<T>::diffArray(Array<T> &rch){
    
    auto a1 = (*this);
    
    auto i{0}, j{0};
    
    for(i=0;i<a1.length;i++){
        if(rch.findIndex(a1.data[i]) ==-1){
            this->data[j++] = this->data[i];
        }
    }
    
    setLength(j);
    
    return (*this);
}


template<class T>
Array<T>& Array<T>::concatArray(Array<T> &rch){

    auto temp = (*this);
    resize(getSize() + rch.size);
    
    for(auto i {0}; i< temp.getLength();i++){
        this->data[i] = temp.data[i];
    }
    
    for(auto i {0}; i< rch.length;i++){
        this->data[i+temp.getLength()] = rch.data[i];
       }
    
    setLength(temp.getLength()+rch.length);
    
    return (*this);
}
//---------------- set operation ---------------
//---------------- sorting methods ---------------

template<class T>
void Array<T>::bubleSort(){
    auto flag{0};
    for(auto i{0};i<getLength()-1;i++){
        for(auto j{0};j<getLength()-1-i;j++){
            if(data[j]>data[j+1]){
                swap(data[j],data[j+1]);
                flag=1;
            }
        }
        if(flag==0) break;
    }
}


template<class T>
void Array<T>::insertionSort(){
    T x{0};
    auto j{0};
    
    for(auto i{1};i<getLength();i++){
        j = i-1;
        x = data[i];
        
        while (j>-1 && data[j] > x) {
            data[j+1] = data[j];
            j--;
        }
        data[j+1] = x;
    }

}


template<class T>
void Array<T>::selectionSort(){
    int k{0};
    for(auto i{0};i<getLength()-1;i++){
        for(auto j=k=i;j<getLength();j++){
            if(data[j] < data[k])
                k=j;
        }
        swap(data[i], data[k]);
    }
}


template<class T>
int Array<T>::partition(int low, int high){
    T pivot = data[low];
    int i = low, j = high;
    
    do {
        do {
            i++;
        } while (data[i] <= pivot);
        
        do {
            j--;
        } while (data[j] > pivot);
        
        if(i<j)
            swap(data[i], data[j]);
        
    } while (i<j);
    
    swap(data[low], data[j]);
    
    return j;
}

template<class T>
void Array<T>::quickSort(int low, int high){
    if (low < high){
        auto j = partition(low, high);
        quickSort(low, j);
        quickSort(j+1, high);
    }
   
}


template<class T>
Array<T>& Array<T>::mergeSort(Array<T> &right){
    
    auto left = (*this);
    
    resize(left.getSize() + right.size);
    initialize();

    auto i{0}, j{0}, k{0};

    while (i < getLength() && j < right.length) {
        if(left.data[i] < right.data[j])
            data[k++] = left.data[i++];
        else
            data[k++] = right.data[j++];
    }

    for(;i<getLength();i++)
        data[k++] = left.data[i];

    for(;j<right.length;j++){
        data[k++] = left.data[j];
    }
    
    setLength(left.length + right.length);
    
    return (*this);
}

template<class T>
Array<T>& Array<T>::mergeSort(int low, int mid, int high){
    auto temp = (*this);
    initialize();
    
    int i{low}, j{mid+1}, k{low};
    
    while (i <= mid && j <= high){
        if (temp.data[i] < temp.data[j]){
            data[k++] = temp.data[i++];
        } else {
            data[k++] = temp.data[j++];
        }
    }
    while (i <= mid){
        data[k++] = temp.data[i++];
    }
    while (j <= high){
        data[k++] = temp.data[j++];
    }

    return (*this);
}


template<class T>
Array<T>& Array<T>::countSort(){
    auto max = getMax();
    
    Array<T> count = Array<T>(max+1);
    count.initialize();
    
    auto temp = (*this);
//    initialize();
    
    for(auto i{0};i<getLength();i++){
        count.data[temp.data[i]]++;
    }
    
    auto i{0}, j{0};
    while (i < max +1) {
        if(count.data[i] > 0){
            data[j++] = i;
            count.data[i]--;
        }else{
            i++;
        }
    }
    
    setLength(j);
    
    return (*this);
}

template<class T>
Array<T>& Array<T>::shellSort(){

    int n = getLength();
    for (int gap=n/2; gap>=1; gap/=2){
        for (int j=gap; j<n; j++){
            T temp = data[j];
            int i = j - gap;
            while (i >= 0 && data[i] > temp){
                data[i+gap] = data[i];
                i = i-gap;
            }
            data[i+gap] = temp;
        }
    }
    return (*this);
}



//---------------- sorting methods ---------------
// --------------- utility tools --------------
template<class T>
void Array<T>::show(){
//    std::cout << "-- getLength() in show = " << getLength() << std::endl;
    for(int i{0};i<getLength();i++){
        std::cout << (T)this->data[i] << " | ";
    }
    std::cout << std::endl;
}


template<class T>
void Array<T>::showList(){
//    std::cout << "-- getLength() in show = " << getLength() << std::endl;
    for(int i{0};i<getLength();i++){
        auto a1 = this->data[i];
        std::cout << this->data[i] << " | ";
    }
    std::cout << std::endl;
}

template<class T>
void Array<T>::showStartPosition(int pos){
    for(auto i{pos};i<=getLength();i++){
        std::cout << (T)this->data[i] << " | ";
    }
    std::cout << std::endl;
}


template<class T>
void Array<T>::swap(T &a, T &b){
    T temp;
    temp=a;
    a=b;
    b=temp;
    
//    std::cout << "&a = " << &a << std::endl;
//     std::cout << "*a = " << a << std::endl;
    
}

template<class T>
void Array<T>::initialize(){
    for (auto i{0};i<getSize();i++)
        this->data[i] = 0;
}
