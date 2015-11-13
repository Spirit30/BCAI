//
//  Officer.h
//  BCAI
//
//  Created by Max Botviniev on 20.10.15.
//  Copyright (c) 2015 Max Botviniev. All rights reserved.
//

#ifndef __BCAI__Officer__
#define __BCAI__Officer__

#include <stdio.h>
#include "Piece.h"
namespace BCAI {
    class Officer : public Piece
    {
    public:
        Officer( Position _position_v, unsigned int _score_v, bool _white_v )  : Piece(_position_v, _score_v, _white_v) {};
    };
}
#endif /* defined(__BCAI__Officer__) */
