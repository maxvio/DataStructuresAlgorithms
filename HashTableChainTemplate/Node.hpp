//
//  Node.hpp
//  HashTableChainTemplate
//
//  Created by viorel maxim on 2020-07-03.
//  Copyright © 2020 viorel maxim. All rights reserved.
//

#ifndef Node_hpp
#define Node_hpp

#include <stdio.h>

template<class T>
class Node{
//private:
//    int data;
//    Node *next;
public:
    T data;
    Node *next;
    
    Node(T data): data(data),next(nullptr){};

//    Node(int data);
//    int getData();
//    Node * getNext();
//    void setData(int data);
//    void setNext(Node *p);
};


#endif /* Node_hpp */
