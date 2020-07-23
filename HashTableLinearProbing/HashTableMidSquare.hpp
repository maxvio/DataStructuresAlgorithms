//
//  HashTableMidSquare.hpp
//  HashTableLinearProbing
//
//  Created by viorel maxim on 2020-07-20.
//  Copyright © 2020 viorel maxim. All rights reserved.
//

#ifndef HashTableMidSquare_hpp
#define HashTableMidSquare_hpp

#include <stdio.h>
#include "HashTable.hpp"

class HashTableMidSquare: public HashTable{
private:
    int prime;
public:
    HashTableMidSquare(int size,int prime);
    
    int getPrime();
    void insertItem(int key);
    int searchItem(int key);
    
    int findMiddleDigits(int key, int middle_digits);
    int getSingleMiddleDigit(int number, int len);
    int getLeftRightNumberDogits(int number, int len);
    int getMultipleMiddleDigits(int number,int middle_digits, int len);
    int getLengthOfNumber(int number);
    
    int getFreeIndex(int index);
    
    
    int hashMidSquareFunctio(int key);
};

#endif /* HashTableMidSquare_hpp */
