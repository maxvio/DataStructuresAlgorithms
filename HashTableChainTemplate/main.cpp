//
//  main.cpp
//  HashTableChainTemplate
//
//  Created by viorel maxim on 2020-07-03.
//  Copyright © 2020 viorel maxim. All rights reserved.
//

#include <iostream>
#include "HashTableChain.hpp"
#include "HashTableChain.cpp"
#include "Node.hpp"

int main(int argc, const char * argv[]) {
    
    std::cout << " ================== Double hashtable ================= " << std::endl;
    
    HashTableChain<Node<double>,double> hashD;
    
    int n = 9;
    double A[9] = {16.3, 12.5, 25.5, 39.9, 6.66, 122.22, 5.55, 68.888, 75.7777};
    
    for (int i=0; i<n; i++){
        hashD.insertItem(A[i]);
    }
    std::cout << "---------- Show has table --------- " << std::endl;
    hashD.show();
    std::cout << std::endl;
    
    std::cout << "---------- Successful Search --------" << std::endl;
    double key = 16.3;
    double results = hashD.searchItem(key);
    std::cout << "Key: " << key << ", found at index : " << results << std::endl;
    std::cout << "---------- Unsuccessful search -------" << std::endl;
    key = 125.5;
    results = hashD.searchItem(key);
    std::cout << "Key: " << key << ", found at index : " << results << std::endl;
    
    
    std::cout << " ================== Character hashtable ================= " << std::endl;
    
    HashTableChain<Node<char>,char> hashC;
    
    char B[] = {'a', 'c', 'g', 'q', 'm', 's', 'w', 'u', 'k'};
    n = sizeof(B)/sizeof(B[0]);
    
    for (int i=0; i<n; i++){
        hashC.insertItem(B[i]);
    }
    
    std::cout << "---------- Show has table --------- " << std::endl;
    hashC.show();
    std::cout << std::endl;
    
    std::cout << "---------- Successful Search --------" << std::endl;
    char keyC = 'k';
    int resultsC = hashC.searchItem(keyC);
    std::cout << "Key: " << keyC << ", found at index : " << resultsC << std::endl;
    std::cout << "---------- Unsuccessful search -------" << std::endl;
    keyC = 'z';
    resultsC = hashC.searchItem(key);
    std::cout << "Key: " << keyC << ", found at index : " << resultsC << std::endl;
    
    
    return 0;
}
