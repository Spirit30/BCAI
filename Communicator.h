//
//  Communicator.h
//  BCAI
//
//  Created by Max Botviniev on 15.10.15.
//  Copyright (c) 2015 Max Botviniev. All rights reserved.
//

#ifndef __BCAI__Communicator__
#define __BCAI__Communicator__

#include <stdio.h>
#include <string>
//--------------
#include "Board.h"

namespace BCAI {
    
    class Communicator {
        
    public:
        std::string GetDecision( std::string input_info_v );
        
    };
    
}
#endif /* defined(__BCAI__Communicator__) */
