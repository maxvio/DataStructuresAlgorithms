//
//  HashTableChain.cpp
//  HashTableChainTemplate
//
//  Created by viorel maxim on 2020-07-03.
//  Copyright © 2020 viorel maxim. All rights reserved.
//

#include <iostream>
#include "HashTableChain.hpp"

template<class T, class U>
HashTableChain<T,U>::HashTableChain(){
    hashTable = new T* [10];
    for(int i = 0; i < 10; i++)
        hashTable[i] = nullptr;
}


template<class T, class U>
HashTableChain<T,U>::~HashTableChain(){
    for(int i = 0; i < 10; i++){
        T *p = hashTable[i];
        while (hashTable[i]) {
            hashTable[i] = hashTable[i]->next;
            delete p;
            p = hashTable[i];
        }
    }
    delete []hashTable;
}

template<class T, class U>
int HashTableChain<T,U>::hashFunction(U key){
    return (int)key % 10;
}

template<class T, class U>
void HashTableChain<T,U>::insertItem(U key){
    int index = hashFunction(key);

    T* temp = new T(key);

    if(hashTable[index] == nullptr){
        hashTable[index] = temp;
    }else{
        T *p = hashTable[index];
        T *q = hashTable[index];
        while (p && key > p->data) {
            q = p;
            p = p->next;
        }
        if(q == hashTable[index]){
            temp->next = hashTable[index];
            hashTable[index] = temp;
        }else {
            temp->next = q->next;
            q->next = temp;
        }
    }
}


template<class T, class U>
int HashTableChain<T,U>::searchItem(U key){
    int index = hashFunction(key);

    T *p = hashTable[index];
    while (p) {
        if(p->data == key)
            return index;
//            return p->data;
        p = p->next;
    }
    return -1;
}


//template<class T>
template<class T, class U>
void HashTableChain<T,U>::show(){
    for(int i = 0; i<10; i++){
//        std::cout << "----------- i = " << i << std::endl;
        T *p = hashTable[i];
        while (p) {
            std::cout << p->data << " | ";
            p = p->next;
        }
        std::cout << "/:/" << std::endl;
    }
}
