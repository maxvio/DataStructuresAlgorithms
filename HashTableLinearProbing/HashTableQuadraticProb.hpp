//
//  HashTableQuadraticProb.hpp
//  HashTableLinearProbing
//
//  Created by viorel maxim on 2020-07-02.
//  Copyright © 2020 viorel maxim. All rights reserved.
//

#ifndef HashTableQuadraticProb_hpp
#define HashTableQuadraticProb_hpp

#include <stdio.h>
#include "HashTable.hpp"
#include "HashTableLinearProb.hpp"

class HashTableQuadraticProb : public HashTable{
public:
    HashTableQuadraticProb(int size);
    

    int hashQuadraticProbingFunction(int index, int key);
//    int hashFunction(int key);
    void insertItem(int key);
    int searchItem(int key);
};

#endif /* HashTableQuadraticProb_hpp */
