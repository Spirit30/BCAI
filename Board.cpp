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
        for( int str_piece_index_l = 0; str_piece_index_l < strlen(input_info_p); str_piece_index_l+=4 ) {
            
            //std::cout << "Piece Index: " << str_piece_index_l << std::endl;
            
            char x_l = input_info_p[str_piece_index_l +2];
            char y_l = input_info_p[str_piece_index_l +3];
            
            //std::cout << x_l << " - " << y_l << std::endl;
            
            char str_piece_l[] = {
                input_info_p[str_piece_index_l],
                input_info_p[str_piece_index_l +1],
                x_l,
                y_l
            };
            
            Piece piece = Parse( str_piece_l );
            pieces.push_back(piece);
            //std::cout << (x_l - 'A') << " - " << (y_l - '0') << std::endl;
            tiles_table_v[x_l - 'A'][y_l - '0']->PutPiece( & pieces[str_piece_index_l] );
        }
        
        //std::cout << tiles_table_v[0][0]->Empty() << std::endl;
        std::cout << tiles_table_v[7][7]->Empty() << std::endl;
        std::cout << (tiles_table_v[7][7]->piece_p->GetScore()) << std::endl;
    }
    
    //Pieces Factory
    Piece Board::Parse( const char * str_piece_p ) {
        
        bool white_l = str_piece_p[0] == '+';
        Position pos_l( str_piece_p[2], str_piece_p[3] - '0' );
        
        unsigned int king_score_l = 30;
        unsigned int queen_score_l = 9;
        unsigned int rook_score_l = 5;
        unsigned int steed_officer_score_l = 3;
        unsigned int pawn_score_l = 1;
        
        switch ( str_piece_p[1] ) {
                
            case 'K':       return King( pos_l, king_score_l, white_l );
            case 'Q':       return Queen( pos_l, queen_score_l, white_l );
            case 'R':       return Rook( pos_l, rook_score_l, white_l );
            case 'S':       return Steed( pos_l, steed_officer_score_l, white_l );      //Knight
            case 'O':       return Officer( pos_l, steed_officer_score_l, white_l );    //Bishop
            default:        return Pawn( pos_l, pawn_score_l, white_l );
        }
    }
    
}
