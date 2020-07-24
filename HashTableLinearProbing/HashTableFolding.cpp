//
//  HashTableFolding.cpp
//  HashTableLinearProbing
//
//  Created by viorel maxim on 2020-07-24.
//  Copyright © 2020 viorel maxim. All rights reserved.
//

#include <iostream>
#include <vector>
#include <string>
#include "HashTableFolding.hpp"


HashTableFolding::HashTableFolding(int size):size(size){
    data = new std::string[size];
}


HashTableFolding::~HashTableFolding(){
    //    std::cout << "destructor HashTable " <<std::endl;
    delete [] data;
}

int HashTableFolding::getSize(){
    return this->size;
}

std::string* HashTableFolding::getData(){
    return data;
}

int HashTableFolding::getSumOfAsciiCode(std::string key){
    int sum {0};
    
    for(int i{0};i<key.length();i++){
        sum += (int)key[i];
    }
    return sum >10 ? sum%10 : sum;
}

std::string HashTableFolding::getItem(int index){
    if(index >=0 && index < size)
        return this->data[index];
    return nullptr ;
}

int HashTableFolding::findFreeIndex(int index){
    auto i{0};
    while (getItem(index+i).empty() != 0) {
        i++;
    }
    return i;
}

int HashTableFolding::sumOfDigits(int number){
    auto sum {0};
    while (number > 0) {
        int digit = number % 10;
        sum += digit;
        number = number/10;
    }
    return sum;
}

void HashTableFolding::insertItem(std::string key){
    
    int asciiSum = getSumOfAsciiCode(key);
    
    int index = sumOfDigits(asciiSum);
    
    if(getData()[index].empty()){
        this->data[index] = key;
    }
    else{
        int newIndex = findFreeIndex(index);
        this->data[newIndex] = key;
    }
}

int HashTableFolding::searchItem(std::string key){
    int i = 0;
    while (i < getSize()) {
        if(getData()[i] == key){
            return i;
        }
        i++;
    }
    
    return -1;
}

void HashTableFolding::show(){
    for (auto i {0};i<size;i++){
        std::cout << data[i] << " | ";
    }
    std::cout << std::endl;
}



