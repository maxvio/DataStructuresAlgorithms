//
//  HashTableLinearProb.hpp
//  HashTableLinearProbing
//
//  Created by viorel maxim on 2020-07-02.
//  Copyright © 2020 viorel maxim. All rights reserved.
//

#ifndef HashTableLinearProb_hpp
#define HashTableLinearProb_hpp

#include <stdio.h>

#include "HashTable.hpp"

class HashTableLinearProb : public HashTable{
public:
    HashTableLinearProb(int size);
    
//    int hashFunction(int key);
    void insertItem(int key);
    int searchItem(int key);
    
    int hashProbingFunction(int index, int key);
};

#endif /* HashTableLinearProb_hpp */
