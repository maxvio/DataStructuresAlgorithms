//
//  main.cpp
//  Array
//
//  Created by viorel maxim on 2020-07-12.
//  Copyright © 2020 viorel maxim. All rights reserved.
//

#include <iostream>
#include "Array.hpp"
#include "Array.cpp"

int main(int argc, const char * argv[]) {
    
    int size = 10;
    Array<int> arr = Array<int>(size);
    arr.pushValue(2);
    arr.pushValue(4);
    arr.pushValue(5);
    arr.pushValue(1);
    arr.pushValue(11);
    
    
    std::cout << "-------- Initial array ----------- " << std::endl;
    arr.show();
    std::cout << "initial length = " <<  arr.getLength() << " : " << "initial size = " << arr.getSize() << std::endl;
    std::cout << "\n-------- Insert value at index array ----------- " << std::endl;
    int value = 6;
    int index = 4;
    std::cout << "insert value = " << value << " : at index = " << index << std::endl;
    arr.insertAtIndex(value,index);
    arr.show();
    std::cout << "legth = " <<  arr.getLength() << " : " << "size = " << arr.getSize() << std::endl;
    
    std::cout << "\n-------- Delete value at index array ----------- " << std::endl;
    index=  4;
    std::cout << "value deleted at index = " << index << " is =  " << arr.deleteAtIndex(4) << std::endl;
    std::cout << "legth = " <<  arr.getLength() << " : " << "size = " << arr.getSize() << std::endl;
    arr.show();
    
    std::cout << "\n-------- Append value at the end of array ----------- " << std::endl;
    value = 33;
    std::cout << "appended value = " << value <<std::endl;
    arr.append(value);
    arr.show();
    
    std::cout << "\n-------- Reverse array ----------- " << std::endl;
    arr.reverse();
    arr.show();
    
    std::cout << "\n-------- Left Rotation ----------- " << std::endl;
    arr.leftRotation();
    arr.show();
    
    std::cout << "\n-------- Right Rotation ----------- " << std::endl;
    arr.rightRotation();
    arr.show();
    
    std::cout << "\n-------- Left shift ----------- " << std::endl;
    arr.leftShift();
    arr.show();
    
    std::cout << "\n-------- Right shift ----------- " << std::endl;
    arr.rightShift();
    arr.showStartPosition(1);
    std::cout << " size = " << arr.getSize() << " : righ shift length = " << arr.getLength() << std::endl;
    
    std::cout << "\n-------- Resize ----------- " << std::endl;
    arr.resize(20);
    arr.show();
    std::cout << "new size = " << arr.getSize() << " : new length = " << arr.getLength() << std::endl;
    
    std::cout << "\n-------- Max of array ----------- " << std::endl;
    arr.deleteAtIndex(0);
    arr.insertAtIndex(100, 0);
    arr.append(67);
    arr.show();
    std::cout << "Max of array = " << arr.getMax() << std::endl;
    
    std::cout << "\n-------- Min of array ----------- " << std::endl;
    std::cout << "Min of array = " << arr.getMin() << std::endl;
    
    std::cout << "-------- Sum of array ----------- " << std::endl;
    arr.show();
    std::cout << "Sum of array = " << arr.getSum() << std::endl;
    std::cout << "new size = " << arr.getSize() << " : new lebnth = " << arr.getLength() << std::endl;
    
    std::cout << "\n-------- Average of array ----------- " << std::endl;
    std::cout << "Average of array = " << arr.getAverage() << std::endl;
    
    std::cout << "\n-------- Find item of array ----------- " << std::endl;
    value = 67;
    arr.show();
    std::cout << "Found value = " << value << " at position = " << arr.findIndex(value) << std::endl;
    
    std::cout << "\n------------- binary search -------- " << std::endl;
    Array<int> s = Array<int>(arr.getSize());
    s.pushValue(1);
    s.pushValue(2);
    s.pushValue(5);
    s.pushValue(6);
    s.pushValue(10);
    s.pushValue(40);
    s.pushValue(67);
    s.pushValue(100);
    
    s.show();
    int key = 100;
    std::cout << "iterative search = " << s.iterativeBinarySaerch(key,0) << std::endl;
    std::cout << "recursive search = " << s.recursiveBinarySaerch(key,0, s.getLength()) << std::endl;
    std::cout << "is sorted s = " << s.isSorted() << std::endl;
    std::cout << "\n------------- Union of two array -------- " << std::endl;
    //    s.show();
    //    arr.pushValue(100);
    //    arr.show();
    //    Array<int> result = s.unionArray(arr);
    //    result.show();
    //    std::cout << "-result.length = "<< result.getLength() << std::endl;
    std::cout << "\n------------- Intersection of two arrays -------- " << std::endl;
    //    std::cout << " --------- inputs ---------- " << std::endl;
    //    s.show();
    //    arr.pushValue(100);
    //    arr.show();
    //    std::cout << " --------- result ---------- " << std::endl;
    //    Array<int> result1 = s.intersectionArray(arr);
    //    result1.show();
    
    std::cout << "\n------------- Diff of two arrays -------- " << std::endl;
    //    std::cout << " --------- inputs ---------- " << std::endl;
    //    s.show();
    //    arr.pushValue(100);
    //    arr.show();
    //    std::cout << " --------- result ---------- " << std::endl;
    //    Array<int> result = s.diffArray(arr);
    //    result.show();
    std::cout << "\n------------- Concatenate two arrays -------- " << std::endl;
    std::cout << " --------- inputs ---------- " << std::endl;
    //    s.show();
    //    arr.pushValue(100);
    //    arr.show();
    //    std::cout << " --------- result ---------- " << std::endl;
    //    Array<int> result = s.concatArray(arr);
    //    result.show();
    
    std::cout << "\n\n===================== Sorting methods ======================== " << std::endl;
    arr.show();
    std::cout << "\n--------- Buble sort ------- " << std::endl;
    //    arr.bubleSort();
    //    arr.show();
    std::cout << "\n--------- Insertion sort ------- " << std::endl;
    arr.insertionSort();
    //    arr.show();
    std::cout << "\n--------- Selection sort ------- " << std::endl;
    //    arr.selectionSort();
    //    arr.show();
    std::cout << "\n--------- Quick sort ------- " << std::endl;
    //    arr.quickSort(0,arr.getLength());
    //    arr.show();
    std::cout << "\n--------- Merge sort version 1 ------- " << std::endl;
    //    s.show();
    //    arr.bubleSort();
    //    arr.show();
    //    Array<int> result = s.mergeSort(arr);
    //    result.show();
    std::cout << "\n--------- Merge sort version 2 ------- " << std::endl;
    Array<int> c = Array<int>(9); // both sides of array has to be sorted without duplicate
    c.pushValue(2);
    c.pushValue(5);
    c.pushValue(8);
    c.pushValue(22);
    c.pushValue(3);
    c.pushValue(6);
    c.pushValue(7);
    c.pushValue(10);
    c.pushValue(15);
    
    std::cout << " -------- input ------- " << std::endl;
    c.show();
    std::cout << " -------- results ------- " << std::endl;
    //    Array<int> result = c.mergeSort(0,3,c.getLength()-1);
    //    result.show();
    std::cout << "\n-------------- Count sort -------------- " << std::endl;
    std::cout << " -------- input ------- " << std::endl;
    c.show();
    std::cout << " -------- results ------- " << std::endl;
    //    Array<int> result = c.countSort();
    //    result.show();
    std::cout << "\n---------------- Shell sort ------------- " << std::endl;
    Array<int> sh = Array<int>(10);
    sh.pushValue(237);
    sh.pushValue(146);
    sh.pushValue(259);
    sh.pushValue(348);
    sh.pushValue(152);
    sh.pushValue(163);
    sh.pushValue(235);
    sh.pushValue(48);
    sh.pushValue(36);
    sh.pushValue(62);
    
    std::cout << " -------- input ------- " << std::endl;
    sh.show();
    std::cout << " -------- results ------- " << std::endl;
    Array<int> shell = sh.shellSort();
    shell.show();
    
    std::cout << "\n =================== Arrays basic operations ====================" << std::endl;
    int length = 10;
    
    float *q1 = new float[length]{3.f, 70.f, 9.f, 100.f, 16.f, 5.f, 12.f, 4.f, 11.f, 2.f};
    float *q2 = new float[length]{4.f, 3.5f, 2.7, 6.7, 9.0, 10.0, 2.5,15.34,6.f,7.8};
    Array<float> left = Array<float>(length);
    Array<float> right = Array<float>(length);
    for(auto i{0};i<length;i++){
        left.pushValue(q1[i]);
        right.pushValue(q2[i]);
    }
    std::cout << " ------------ inputs -------------- " << std::endl;
    left.show();
    right.show();
    std::cout << " ------------ inputs -------------- " << std::endl;
    std::cout << "\n------------- addition -------------" << std::endl;
    
    std::cout << " ------------ result -------------- " << std::endl;
    //    Array<float> add = left + right;
    //    add.show();
    
    std::cout << "\n------------- substraction -------------" << std::endl;
    std::cout << " ------------ result -------------- " << std::endl;
    //    Array<float> diff = left - right;
    //    diff.show();
    
    std::cout << "\n------------- multiplication -------------" << std::endl;
    std::cout << " ------------ result -------------- " << std::endl;
    //    Array<float> mul = left * right;
    //    mul.show();
    
    std::cout << "\n------------- division -------------" << std::endl;
    std::cout << " ------------ result -------------- " << std::endl;
    Array<float> div = left / right;
    div.show();
    
    
    
    
    std::cout<<std::endl;
    
    return 0;
}
