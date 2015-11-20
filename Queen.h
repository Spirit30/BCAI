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
        Queen( Position _position_v, unsigned int _score_v, bool _white_v, char type_v )  : Piece( _position_v, _score_v, _white_v, type_v ) {};
    };
}
#endif /* defined(__BCAI__Queen__) */
