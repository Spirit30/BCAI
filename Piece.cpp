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
    
    unsigned int Piece::GetScore() {
        
        return score_v;
    }
    
    Position & Piece::GetPosition() {
        
        return position_v;
    }
    
    char Piece::GetType() {
        
        return type_v;
    }
    
}