//
//  Tile.hpp
//  BCAI
//
//  Created by Max Botviniev on 13.11.15.
//  Copyright © 2015 Max Botviniev. All rights reserved.
//

#ifndef Tile_hpp
#define Tile_hpp

#include <stdio.h>
#include "Piece.h"

namespace BCAI  {

    class Tile {
        
    private:
        Position adress_v;
    public:
        Piece * piece_p = NULL;
        Tile( Position _adress_v ) : adress_v(_adress_v) { };
        void PutPiece( Piece * _piece_p );
        bool Empty();
        Position & GetAdress();
    };
}

#endif /* Tile_hpp */
