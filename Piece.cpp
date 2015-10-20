//
//  Piece.cpp
//  BCAI
//
//  Created by Max Botviniev on 20.10.15.
//  Copyright (c) 2015 Max Botviniev. All rights reserved.
//

#include "Piece.h"
namespace BCAI {
    
    Piece::Piece( char _x_v, char _y_v, unsigned int _score_v )
    {
        x_v = _x_v;
        y_v = _y_v;
        score_v = _score_v;
    }
    
    //---------------------------
    
    char * Piece::GetX()
    {
        return & x_v;
    }
    
    char * Piece::GetY()
    {
        return & y_v;
    }
    
    unsigned int * Piece::GetScore()
    {
        return & score_v;
    }
    
}