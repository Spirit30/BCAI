//
//  Board.h
//  BCAI
//
//  Created by Max Botviniev on 20.10.15.
//  Copyright (c) 2015 Max Botviniev. All rights reserved.
//

#ifndef __BCAI__Board__
#define __BCAI__Board__

#include <stdio.h>
#include <string>
#include <vector>
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
    //private:
        
    public:
        std::vector<Piece*> pieces;
        //------------------------
        Board( std::string & input_info_v);
        Piece * GetMove();
    };

}

#endif /* defined(__BCAI__Board__) */
