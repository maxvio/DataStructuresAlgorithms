//
//  HashTableDoubleHashing.hpp
//  HashTableLinearProbing
//
//  Created by viorel maxim on 2020-07-02.
//  Copyright © 2020 viorel maxim. All rights reserved.
//

#ifndef HashTableDoubleHashing_hpp
#define HashTableDoubleHashing_hpp

#include <stdio.h>
#include "HashTableLInearProbing.hpp"

class HashTableDoubleHashing : public HashTableLinearProbing{
private:
    int prime;
public:
    HashTableDoubleHashing(int size, int prime);

    // ------------ double hashing --------------
    
    int hashDouleFunction(int key, int i);
    int doubleHashing(int key);
    void insertDoubleHashingItem(int key);
    int searchDoubleHashingItem(int key);
    
protected:
    int hashH2(int key);
};

#endif /* HashTableDoubleHashing_hpp */
