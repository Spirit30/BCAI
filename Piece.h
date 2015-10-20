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

namespace BCAI {
    
    class Piece {
        
    private:
        char x_v = 'X';
        char y_v = 'Y';
        unsigned int score_v = 666;
        
    public:
        Piece( char _x_v, char _y_v, unsigned int _score_v );
        unsigned int * GetScore();
        char * GetX();
        char * GetY();
    };
    
}
#endif /* defined(__BCAI__Piece__) */
