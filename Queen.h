//
//  Queen.h
//  BCAI
//
//  Created by Max Botviniev on 20.10.15.
//  Copyright (c) 2015 Max Botviniev. All rights reserved.
//

#ifndef __BCAI__Queen__
#define __BCAI__Queen__

#include <stdio.h>
#include "Piece.h"
namespace BCAI {
    class Queen : public Piece
    {
    public:
        Queen( char _x_v, char _y_v, unsigned int _score_v = 9 ) : Piece( _x_v, _y_v, _score_v ) {};
    };
}
#endif /* defined(__BCAI__Queen__) */
