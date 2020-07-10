//
//  main.cpp
//  TestGit
//
//  Created by viorel maxim on 2020-07-10.
//  Copyright © 2020 viorel maxim. All rights reserved.
//

#include <iostream>
#include <vector>

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World from test git!\n";
    
    std::vector<int> data;
    
    data.push_back(10);
    data.push_back(5);
    data.push_back(23);
    data.push_back(1);
    
    for(auto i=data.begin();i!=data.end();++i){
        std::cout << "data = " << *i  << std::endl;
    }
    
    
    return 0;
}
