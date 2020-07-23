//
//  HashTableDoubleHashing.cpp
//  HashTableLinearProbing
//
//  Created by viorel maxim on 2020-07-02.
//  Copyright © 2020 viorel maxim. All rights reserved.
//

#include "HashTableDoubleHashing.hpp"
HashTableDoubleHashing::HashTableDoubleHashing(int size, int prime):HashTableLinearProbing(size){
    this->prime = prime;
};

// ----------- double hashing -----------
int HashTableDoubleHashing::hashH2(int key){
    return prime - key%prime;
}

int HashTableDoubleHashing::hashDouleFunction(int key, int i){
    return hashFunction(hashFunction(key) + i * hashH2(key));
}

int HashTableDoubleHashing::doubleHashing(int key){
//    int index = hashFunction(key);
    
    int i{0};
    while ( getHashTable()[hashDouleFunction(key,i)] !=0) {
        i++;
    }
    return hashDouleFunction(key, i);
}

void HashTableDoubleHashing::insertDoubleHashingItem(int key){
    int index = hashFunction(key);
    
    if(getHashTable()[index] != 0)
        index = doubleHashing(key);
    
    getHashTable()[index] = key;
}


int HashTableDoubleHashing::searchDoubleHashingItem(int key){
    int i = 0;
    while (getHashTable()[hashDouleFunction(key,i)] != key){
        i++;
        if (getHashTable()[hashDouleFunction(key,i)] == 0){
            return -1;
        }
    }
    return hashDouleFunction(key,i);
}
