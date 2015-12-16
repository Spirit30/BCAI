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
       Pawn( Position _position_v, unsigned int _score_v, bool _white_v, char type_v );
    };
}

#endif /* defined(__BCAI__Pawn__) */
