//
//  HashTableLinearProb.cpp
//  HashTableLinearProbing
//
//  Created by viorel maxim on 2020-07-02.
//  Copyright © 2020 viorel maxim. All rights reserved.
//

#include "HashTableLinearProb.hpp"
#include "HashTable.hpp"

HashTableLinearProb::HashTableLinearProb(int size):HashTable(size){};

//int HashTableLinearProb::hashFunction(int key){
//     return key % this->getSize();
//}

int HashTableLinearProb::hashProbingFunction(int index, int key){
    int i{0};
    
    while (getHashTable()[(index + i) % this->getSize()] != 0) {
        i++;
    }
    return (index + i) % this->getSize();
}

void HashTableLinearProb::insertItem(int key){
    int index = hashFunction(key);
    
    if(getHashTable()[index] != 0)
        index = hashProbingFunction(index, key);
    getHashTable()[index] = key;
}

int HashTableLinearProb::searchItem(int key){
    
    int index = hashFunction(key);
    int i = 0;
    while (getHashTable()[hashFunction(index+i)] != key){
        i++;
        if (getHashTable()[hashFunction(index+i)] == 0){
            return -1;
        }
    }
    return getHashTable()[hashFunction(index+i)];
    
}
