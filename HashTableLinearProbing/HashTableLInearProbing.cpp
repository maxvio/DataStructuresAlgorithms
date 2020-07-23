//
//  HashTableLInearProbing.cpp
//  HashTableLinearProbing
//
//  Created by viorel maxim on 2020-07-02.
//  Copyright © 2020 viorel maxim. All rights reserved.
//

#include <iostream>
#include "HashTableLInearProbing.hpp"

HashTableLinearProbing::HashTableLinearProbing(int size):size(size){
    hashTable = new int[size];
    for(int i = 1;i<size;i++)
        hashTable[i]=0;
}

HashTableLinearProbing::~HashTableLinearProbing(){
    delete [] hashTable;
}

int HashTableLinearProbing::hashFunction(int key){
    return key % this->size;
}

int HashTableLinearProbing::hashProbingFunction(int index, int key){
    int i{0};
    
    while (hashTable[(index + i) % this->size] != 0) {
        i++;
    }
    return (index + i) % this->size;
}

void HashTableLinearProbing::insertItem(int key){
    int index = hashFunction(key);
    
    if(hashTable[index] != 0)
        index = hashProbingFunction(index, key);
    hashTable[index] = key;
}

int HashTableLinearProbing::searchItem(int key){
    
    int index = hashFunction(key);
    int i = 0;
    while (hashTable[hashFunction(index+i)] != key){
        i++;
        if (hashTable[hashFunction(index+i)] == 0){
            return -1;
        }
    }
    return hashTable[hashFunction(index+i)];
    
}


void HashTableLinearProbing::show(){
    for(int i=0;i<this->size;i++){
        std::cout << hashTable[i] << " | ";
    }
    std::cout << std::endl;
}


// ------------ Quadrating probing -------------------

int HashTableLinearProbing::hashQuadProbingFunction(int index, int key){
    int i{0};
    
    while (hashTable[(index + i*i) % this->size] != 0) {
        i++;
    }
    return (index + i*i) % this->size;
}

void HashTableLinearProbing::insertQuadItem(int key){
    int index = hashFunction(key);
    
    if(hashTable[index] != 0)
        index = hashQuadProbingFunction(index, key);
    hashTable[index] = key;
}


int HashTableLinearProbing::searchQuadItem(int key){
    
    int index = hashFunction(key);
    int i = 0;
    while (hashTable[hashFunction(index+i*i)] != key){
        i++;
        if (hashTable[hashFunction(index+i*i)] == 0){
            return -1;
        }
    }
    return hashFunction(index+i*i);
}
