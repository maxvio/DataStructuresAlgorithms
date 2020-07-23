//
//  HashTableQuadraticProb.cpp
//  HashTableLinearProbing
//
//  Created by viorel maxim on 2020-07-02.
//  Copyright © 2020 viorel maxim. All rights reserved.
//

#include "HashTableQuadraticProb.hpp"
#include "HashTable.hpp"
HashTableQuadraticProb::HashTableQuadraticProb(int size):HashTable(size){};

void HashTableQuadraticProb::insertItem(int key){
    int index = hashFunction(key);
    
    if(getHashTable()[index] != 0)
        index = hashQuadraticProbingFunction(index, key);
    getHashTable()[index] = key;
}

int HashTableQuadraticProb::hashQuadraticProbingFunction(int index, int key){
    int i{0};
    
    while (getHashTable()[(index + i*i) % this->getSize()] != 0) {
        i++;
    }
    return (index + i*i) % this->getSize();
}


int HashTableQuadraticProb::searchItem(int key){
    
    int index = hashFunction(key);
    int i = 0;
    while (getHashTable()[hashFunction(index+i*i)] != key){
        i++;
        if (getHashTable()[hashFunction(index+i*i)] == 0){
            return -1;
        }
    }
    return hashFunction(index+i*i);
}

//int HashTableQuadraticProb::hashFunction(int key){
//     return key % this->getSize();
//}
