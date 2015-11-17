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
        
        std::cout << "GetScore: " << score_v << '\n';
        return score_v;
    }
    
}