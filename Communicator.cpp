//
//  Communicator.cpp
//  BCAI
//
//  Created by Max Botviniev on 15.10.15.
//  Copyright (c) 2015 Max Botviniev. All rights reserved.
//

#include "Communicator.h"





namespace BCAI {
    
    std::string Communicator::GetDecision( std::string input_info_v ) {
        
        Board board( input_info_v );
        
        Piece * result = board.GetMove();
        
        std::string mystring;
        
        return input_info_v + "_: " + * (result->GetX());
    }
}