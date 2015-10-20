//
//  main.cpp
//  BCAI
//
//  Created by Max Botviniev on 15.10.15.
//  Copyright (c) 2015 Max Botviniev. All rights reserved.
//

#include <iostream>
#include "Communicator.h"
using std::string;
using std::cout;
    
int main(int argc, const char * argv[]) {
    
    BCAI::Communicator communicator;
    string output = communicator.GetDecision("KA1");
    cout << output;
    
    return 0;
}
