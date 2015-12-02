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


#include <typeinfo>


//-------------------
#include "Position.hpp"


#include <iostream>

namespace BCAI {
    
    struct Axe {
        
        int x_v;
        int y_v;
        
        Axe( int _x_v, int _y_v ) {
            
            x_v = _x_v;
            y_v = _y_v;
        }
    };
    
    class Piece {
        
    private:
        //Data
        bool white_v;
        Position position_v;
        unsigned int score_v;
        char type_v;
    protected:
        std::vector<Axe> axes;
    public:
        Piece( Position _position_v, unsigned int _score_v, bool _white_v, char _type_v ) : position_v(_position_v), score_v(_score_v), white_v(_white_v), type_v(_type_v) { };
        //Accesors
        bool White();
        Position & GetPosition();
        unsigned int GetScore();
        char GetType();
        //Algorythms
        //virtual bool AlowedMove();
    };
    
}
#endif /* defined(__BCAI__Piece__) */
