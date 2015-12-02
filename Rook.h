//
//  Rook.h
//  BCAI
//
//  Created by Max Botviniev on 20.10.15.
//  Copyright (c) 2015 Max Botviniev. All rights reserved.
//

#ifndef __BCAI__Rook__
#define __BCAI__Rook__

#include <stdio.h>
#include "Piece.h"
namespace BCAI {
    class Rook : public Piece
    {
    public:
        Rook( Position _position_v, unsigned int _score_v, bool _white_v, char type_v );
    };
}
#endif /* defined(__BCAI__Rook__) */
