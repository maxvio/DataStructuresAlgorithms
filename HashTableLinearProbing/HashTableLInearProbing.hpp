//
//  HashTableLInearProbing.hpp
//  HashTableLinearProbing
//
//  Created by viorel maxim on 2020-07-02.
//  Copyright © 2020 viorel maxim. All rights reserved.
//

#ifndef HashTableLInearProbing_hpp
#define HashTableLInearProbing_hpp

#include <stdio.h>

class HashTableLinearProbing{
private:
    int size;
    int *hashTable;

public:
    HashTableLinearProbing(int size);
    ~HashTableLinearProbing();
    
    
    
    // ---------- linear probing ---------
    int hashFunction(int key);
    int hashProbingFunction(int index, int key);
    void insertItem(int key);
    int searchItem(int key);
    
    int *getHashTable(){
        return hashTable;
    }
    int getSize(){
        return this->size;
    }
    
    // ---------- quadratic hashing -------------------
    int hashQuadProbingFunction(int index, int key);
    void insertQuadItem(int key);
    int searchQuadItem(int key);
    
    void show();
};

#endif /* HashTableLInearProbing_hpp */
