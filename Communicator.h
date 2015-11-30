//
//  Communicator.h
//  BCAI
//
//  Created by Max Botviniev on 15.10.15.
//  Copyright (c) 2015 Max Botviniev. All rights reserved.
//

#ifndef __BCAI__Communicator__
#define __BCAI__Communicator__

//--------------
#include "Board.h"
//TEMP
#include "functions.h"

namespace BCAI {
    
    class Communicator {
        
    public:
        char * GetDecision( const char * game_p ) const;
        bool RulesAdvisor( const char * game_p, const char * move_p, bool white_turn_v ) const;
    };
    
}
#endif /* defined(__BCAI__Communicator__) */
