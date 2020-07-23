//
//  HashTableChain.hpp
//  HashTableChainTemplate
//
//  Created by viorel maxim on 2020-07-03.
//  Copyright © 2020 viorel maxim. All rights reserved.
//

#ifndef HashTableChain_hpp
#define HashTableChain_hpp

#include <stdio.h>

template<class T, class U>
class HashTableChain{
public:
    T* *hashTable;
    HashTableChain();
    ~HashTableChain();
    
    int hashFunction(U key);
    void insertItem(U key);
    int searchItem(U key);
    void show();
};

#endif /* HashTableChain_hpp */
