//
//  HashTable.cpp
//  HashTableLinearProbing
//
//  Created by viorel maxim on 2020-07-02.
//  Copyright © 2020 viorel maxim. All rights reserved.
//

#include <iostream>
#include "HashTable.hpp"


HashTable::HashTable(int size):size(size){
    hashTable = new int[size];
    for(int i = 1;i<size;i++)
        hashTable[i]=0;
}


HashTable::~HashTable(){
//    std::cout << "destructor HashTable " <<std::endl;
    delete [] hashTable;
}


int* HashTable::getHashTable(){
    return hashTable;
}


void HashTable::show(){
    for(int i=0;i<this->size;i++){
        std::cout << hashTable[i] << " | ";
    }
    std::cout << std::endl;
}

int HashTable::getSize(){
    return this->size;
}


int HashTable::hashFunction(int key){
     return key % this->size;
}
