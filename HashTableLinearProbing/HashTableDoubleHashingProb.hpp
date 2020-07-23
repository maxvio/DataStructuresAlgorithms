//
//  HashTableDoubleHashingProb.hpp
//  HashTableLinearProbing
//
//  Created by viorel maxim on 2020-07-03.
//  Copyright © 2020 viorel maxim. All rights reserved.
//

#ifndef HashTableDoubleHashingProb_hpp
#define HashTableDoubleHashingProb_hpp

#include <stdio.h>
#include "HashTable.hpp"

class HashTableDoubleHashingProb : public HashTable{
private:
    int prime;
public:
    HashTableDoubleHashingProb(int size, int prime);
    
//    int hashFunction(int key);
    int hashDouleFunction(int key, int i);
    int doubleHashing(int key);
    void insertItem(int key);
    int searchItem(int key);
    
protected:
    int hashH2(int key);
    
};

#endif /* HashTableDoubleHashingProb_hpp */
