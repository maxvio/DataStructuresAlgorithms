//
//  HashTable.hpp
//  HashTableLinearProbing
//
//  Created by viorel maxim on 2020-07-02.
//  Copyright © 2020 viorel maxim. All rights reserved.
//

#ifndef HashTable_hpp
#define HashTable_hpp

#include <stdio.h>
class HashTable{
private:
    int size;
    int *hashTable;
public:
    HashTable(int size);
    ~HashTable();
    
//    virtual int hashFunction(int key);
    int hashFunction(int key);
    virtual void insertItem(int key)=0;
    virtual int searchItem(int key)=0;
    
    int *getHashTable();
    int getSize();
    
    void show();
    
};

#endif /* HashTable_hpp */
