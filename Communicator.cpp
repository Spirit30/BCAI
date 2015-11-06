//
//  Communicator.cpp
//  BCAI
//
//  Created by Max Botviniev on 15.10.15.
//  Copyright (c) 2015 Max Botviniev. All rights reserved.
//

#include "Communicator.h"



namespace BCAI {
    
    char * Communicator::GetDecision( const char input_game_c[] ) {
        
        char  * AI_move = new char[4] /*{ 'A', '7', 'A', '6' }*/ ;
        
        //Get Move
        //Board board( input_info_p );
        //Piece * result = board.GetMove();
        //....
        
        InputFill(AI_move);
        
        return AI_move;
    }
}