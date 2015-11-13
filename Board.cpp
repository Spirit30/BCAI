//
//  Board.cpp
//  BCAI
//
//  Created by Max Botviniev on 20.10.15.
//  Copyright (c) 2015 Max Botviniev. All rights reserved.
//

#include "Board.h"


//-------------
//DEBUG
#include <iostream>

namespace BCAI {
    
    Board::Board( const char * input_info_p)
    {
        //Create Tiles
        for( int x_index_l = 0; x_index_l < 8; x_index_l++ ) {
            
            for( int y_index_l = 0; y_index_l < 8; y_index_l++ ) {
            
                Position position( 'A' + x_index_l, y_index_l +1 );
                Tile tile( position );
                tiles_table_v[x_index_l][y_index_l] = & tile;
            }
        }
        
        
        //Parse data to Pieces list and Tiles array
        for( int str_piece_index_l = 0; str_piece_index_l < 4; str_piece_index_l++ ) {
            
            char x_l = input_info_p[str_piece_index_l +2];
            char y_l = input_info_p[str_piece_index_l +3];
            
            char str_piece_l[] = {
                input_info_p[str_piece_index_l],
                input_info_p[str_piece_index_l +1],
                x_l,
                y_l
            };
            
            Piece piece = Parse( str_piece_l );
            pieces.push_back(piece);
            tiles_table_v[x_l - 'A'][y_l - '0']->PutPiece( & pieces[str_piece_index_l] );
        }
        
        std::cout << tiles_table_v[4][4]->Empty() << std::endl;
        std::cout << tiles_table_v[7][7]->Empty() << std::endl;
    }
    
    //Pieces Factory
    Piece Board::Parse( const char * str_piece_p ) {
        
        bool white_l = str_piece_p[0] == '+';
        Position pos_l( str_piece_p[2], str_piece_p[3] - '0' );
        
        switch ( str_piece_p[1] ) {
                
            case 'K':       return King( pos_l, 30, white_l );
            case 'Q':       return Queen( pos_l, 9, white_l );
            case 'R':       return Rook( pos_l, 5, white_l );
            case 'S':       return Steed( pos_l, 3, white_l );      //Knight
            case 'O':       return Officer( pos_l, 3, white_l );    //Bishop
            default /*P*/:  return Pawn( pos_l, 1, white_l );
        }
    }
    
}
