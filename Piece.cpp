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
        
        //Foreach Axe direction
        for( int i = 0; i < axes.size(); i++ ) {
            
            
            while( true ) {
                
                std::cout << "adf";
            }
            
        }
        return false;
    }*/
}