//
//  Piece.h
//  BCAI
//
//  Created by Max Botviniev on 20.10.15.
//  Copyright (c) 2015 Max Botviniev. All rights reserved.
//

#ifndef __BCAI__Piece__
#define __BCAI__Piece__

#include <stdio.h>
#include <vector>
//-------------------
#include "Position.hpp"


//#include <iostream>

namespace BCAI {
    
    class Piece {
        
    private:
        //Data
        bool white_v;
        Position position_v;
        unsigned int score_v;
    protected:
        //variables
        std::vector<Position> avaliable_positions_v;
    public:
        Piece( Position _position_v, unsigned int _score_v, bool _white_v ) : position_v(_position_v), score_v(_score_v), white_v(_white_v) { };
        //virtual std::vector<Position> Avaliable();
        unsigned int GetScore();

    };
    
}
#endif /* defined(__BCAI__Piece__) */
