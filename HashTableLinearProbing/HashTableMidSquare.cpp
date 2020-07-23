//
//  HashTableMidSquare.cpp
//  HashTableLinearProbing
//
//  Created by viorel maxim on 2020-07-20.
//  Copyright © 2020 viorel maxim. All rights reserved.
//

#include <iostream>
#include <math.h>
#include "HashTableMidSquare.hpp"
#include "HashTable.hpp"


HashTableMidSquare::HashTableMidSquare(int size, int prime):HashTable(size){
    this->prime = prime;
};

int HashTableMidSquare::getPrime(){
    return this->prime;
}
int HashTableMidSquare::hashMidSquareFunctio(int key){
    int square = pow(key,2);
    int len = log10(square) + 1;
    
    return (int)(square/(pow(10, (int)len/2)))%10;
}


void HashTableMidSquare::insertItem(int key){
    int index = findMiddleDigits(key,2)%getPrime();
    
    if(getHashTable()[index] == 0){
        getHashTable()[index] = key;
    }else{
        int newIndex = getFreeIndex(index);
        getHashTable()[newIndex] = key;
    }
}

int HashTableMidSquare::getFreeIndex(int index){
    auto i {1};
    while (getHashTable()[(index + i)] != 0) {
           i++;
       }
    return index + i;
}

int HashTableMidSquare::getLengthOfNumber(int number){
    return log10(number) + 1;
}

int HashTableMidSquare::getSingleMiddleDigit(int number, int len){
    return (int)(number/(pow(10, (int)len/2)))%10;
}

int HashTableMidSquare::getLeftRightNumberDogits(int number, int len){
    auto i{2}, j{0};
    while (i <= len) {;
        i +=2;
        j++;
    }
    return j;
}
int HashTableMidSquare::getMultipleMiddleDigits(int number, int middle_digits, int len){

    int n_digits = getLeftRightNumberDogits(number,len)-1;
    
    int t1 = number/pow(10,len-n_digits);
    float t2 = (float)number/pow(10,len-n_digits);

    return (t2-t1)*pow(10,middle_digits);
}

int HashTableMidSquare::findMiddleDigits(int key, int middle_digits){
    int square = pow(key,2);
    int len = getLengthOfNumber(square);

    return (len % 2 != 0) ? getSingleMiddleDigit(square,len) : getMultipleMiddleDigits(square,middle_digits,len);
}


int HashTableMidSquare::searchItem(int key){
    int i = 0;
    while (i < getSize()) {
        if(getHashTable()[i] == key){
            return i;
        }
        i++;
    }
    
//    while (getHashTable()[hashDouleFunction(key,i)] != key){
//        i++;
//        if (getHashTable()[hashDouleFunction(key,i)] == 0){
//            return -1;
//        }
//    }
//    return hashDouleFunction(key,i);
    
    return -1;
}
