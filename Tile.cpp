//
//  Tile.cpp
//  BCAI
//
//  Created by Max Botviniev on 13.11.15.
//  Copyright © 2015 Max Botviniev. All rights reserved.
//

#include "Tile.hpp"
namespace BCAI {
    
    void Tile::PutPiece(BCAI::Piece *_piece_p) {
        
        piece_p = _piece_p;
    }
    
    bool Tile::Empty() {
        
        return ! piece_p;
    }
    
    Position & Tile::GetAdress() {
        
        return adress_v;
    }
}