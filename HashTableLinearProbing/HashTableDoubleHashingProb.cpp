//
//  HashTableDoubleHashingProb.cpp
//  HashTableLinearProbing
//
//  Created by viorel maxim on 2020-07-03.
//  Copyright © 2020 viorel maxim. All rights reserved.
//

#include "HashTableDoubleHashingProb.hpp"
# include "HashTable.hpp"


HashTableDoubleHashingProb::HashTableDoubleHashingProb(int size, int prime):HashTable(size){
    this->prime = prime;
};


//int HashTableDoubleHashingProb::hashFunction(int key){
//     return key % this->getSize();
//}

int HashTableDoubleHashingProb::hashH2(int key){
    return prime - key%prime;
}

int HashTableDoubleHashingProb::hashDouleFunction(int key, int i){
    return hashFunction(hashFunction(key) + i * hashH2(key));
}

int HashTableDoubleHashingProb::doubleHashing(int key){
//    int index = hashFunction(key);
    
    int i{0};
    while ( getHashTable()[hashDouleFunction(key,i)] !=0) {
        i++;
    }
    return hashDouleFunction(key, i);
}

void HashTableDoubleHashingProb::insertItem(int key){
    int index = hashFunction(key);
    
    if(getHashTable()[index] != 0)
        index = doubleHashing(key);
    
    getHashTable()[index] = key;
}


int HashTableDoubleHashingProb::searchItem(int key){
    int i = 0;
    while (getHashTable()[hashDouleFunction(key,i)] != key){
        i++;
        if (getHashTable()[hashDouleFunction(key,i)] == 0){
            return -1;
        }
    }
    return hashDouleFunction(key,i);
}
