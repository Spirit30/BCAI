//
//  Rook.cpp
//  BCAI
//
//  Created by Max Botviniev on 20.10.15.
//  Copyright (c) 2015 Max Botviniev. All rights reserved.
//

#include "Rook.h"

namespace BCAI {
    
    Rook::Rook( Position _position_v, unsigned int _score_v, bool _white_v, char type_v ) : Piece( _position_v, _score_v, _white_v, type_v ) {
        
        axes.push_back( * new Axe(-1,1 ) );
    }
}