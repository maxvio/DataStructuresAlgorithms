//
//  HashTableFolding.hpp
//  HashTableLinearProbing
//
//  Created by viorel maxim on 2020-07-24.
//  Copyright © 2020 viorel maxim. All rights reserved.
//

#ifndef HashTableFolding_hpp
#define HashTableFolding_hpp

#include <stdio.h>
#include <vector>
#include <string>

class HashTableFolding{
private:
    int size;
    std::string* data;
public:
    HashTableFolding(int size);
    ~HashTableFolding();
    
    void insertItem(std::string key);
    int getSumOfAsciiCode (std::string key);
    int sumOfDigits(int number);
    
    std::string* getData();
    std::string getItem(int index);
    
    int findFreeIndex(int index);
    
    int searchItem(std::string key);
    
    int getSize();
    
    void show();    
};

#endif /* HashTableFolding_hpp */
