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
        
        
        //Parse Pieces data to Pieces list and to Tiles array
        for( int str_piece_index_l = 0; str_piece_index_l < strlen(input_info_p); str_piece_index_l += 4 ) {
            
            char x_l = input_info_p[str_piece_index_l +2];
            char y_l = input_info_p[str_piece_index_l +3];
            
            char str_piece_l[] = {
                input_info_p[str_piece_index_l],
                input_info_p[str_piece_index_l +1],
                x_l,
                y_l
            };
            
            pieces.push_back( Parse( str_piece_l ) );
            tiles_table_v[x_l - 'A'][y_l - '0']->PutPiece( & pieces[pieces.size() -1] );
            
            //TEST
            /*Position pos( 'E', 8 );
            if( pos == pieces[pieces.size() -1].GetPosition() ) {
                
                std::cout << pieces[pieces.size() -1].GetType() << std::endl;
                std::cout << "Tile Empty? - " << tiles_table_v[x_l - 'A'][y_l - '0']->Empty() << std::endl;
                std::cout << "Score: " << pieces[pieces.size() -1].GetScore() << std::endl;
            }*/
        }
        
    }
    
    //Pieces Factory
    Piece Board::Parse( const char * str_piece_p ) {
        
        bool white_l = str_piece_p[0] == '+';
        Position pos_l( str_piece_p[2], str_piece_p[3] - '0' );

        switch ( str_piece_p[1] ) {
                
            case 'K':       return King(    pos_l, 30,  white_l, str_piece_p[1] );
            case 'Q':       return Queen(   pos_l, 9,   white_l, str_piece_p[1] );
            case 'R':       return Rook(    pos_l, 5,   white_l, str_piece_p[1] );
            case 'S':       return Steed(   pos_l, 3,   white_l, str_piece_p[1] );    //Knight
            case 'O':       return Officer( pos_l, 3,   white_l, str_piece_p[1] );    //Bishop
            default:        return Pawn(    pos_l, 1,   white_l, str_piece_p[1] );
        }
    }
    
}
