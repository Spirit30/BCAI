//
//  Pawn.h
//  BCAI
//
//  Created by Max Botviniev on 20.10.15.
//  Copyright (c) 2015 Max Botviniev. All rights reserved.
//

#ifndef __BCAI__Pawn__
#define __BCAI__Pawn__

#include <stdio.h>
#include "Piece.h"
namespace BCAI {
    class Pawn : public Piece
    {
    public:
       Pawn( char _x_v, char _y_v, unsigned int _score_v = 1 ) : Piece( _x_v, _y_v, _score_v ) {};
    };
}

#endif /* defined(__BCAI__Pawn__) */
