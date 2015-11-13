//
//  Board.h
//  BCAI
//
//  Created by Max Botviniev on 20.10.15.
//  Copyright (c) 2015 Max Botviniev. All rights reserved.
//

#ifndef __BCAI__Board__
#define __BCAI__Board__

#include <vector>
//----------------
#include "Tile.hpp"
//----------------
#include "Piece.h"
//----------------
#include "King.h"
#include "Queen.h"
#include "Rook.h"
#include "Officer.h"
#include "Steed.h"
#include "Pawn.h"

namespace BCAI {

    class Board
    {
    private:
        Tile * tiles_table_v[8][8];
        std::vector<Piece> pieces;
    public:
        //------------------------
        Board( const char * input_info_p );
        Piece Parse( const char str_piece_v[4] );
    };

}

#endif /* defined(__BCAI__Board__) */
