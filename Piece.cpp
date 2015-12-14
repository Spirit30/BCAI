//
//  Piece.cpp
//  BCAI
//
//  Created by Max Botviniev on 20.10.15.
//  Copyright (c) 2015 Max Botviniev. All rights reserved.
//

#include "Piece.h"

namespace BCAI {
    

    //---------------------------
    
    bool Piece::White() {
        
        return white_v;
    }
    
    Position & Piece::GetPosition() {
        
        return position_v;
    }
    unsigned int Piece::GetScore() {
        
        return score_v;
    }
    
    char Piece::GetType() {
        
        return type_v;
    }
    
    /*bool Piece::AlowedMove() {
        
        //Check each Axe direction
        for( int a = 0; a < axes.size(); a++ ) {
            
            //IndexPair temp_position( )
            //Check each Tile on this Axe direction
            
            
        }
        std::cout << "Decline in Piece" << std::endl;
        return false;
    }*/
}