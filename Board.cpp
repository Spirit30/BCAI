//
//  Board.cpp
//  BCAI
//
//  Created by Max Botviniev on 20.10.15.
//  Copyright (c) 2015 Max Botviniev. All rights reserved.
//

#include "Board.h"

namespace BCAI {
    
    Board::Board( const char * input_info_p)
    {
        //Create Tiles
        for( int x_index_l = 0; x_index_l < 8; x_index_l++ ) {
            
            for( int y_index_l = 0; y_index_l < 8; y_index_l++ ) {
            
                Position position( 'A' + x_index_l, y_index_l +1 );
                tiles_table_v[x_index_l][y_index_l] = new Tile( position );
            }
        }
        
        
        //Parse Pieces data to Pieces list and to Tiles array
        for( int str_piece_index_l = 0; str_piece_index_l < strlen(input_info_p); str_piece_index_l += 4 ) {
            
            IndexPair indexes( input_info_p[str_piece_index_l +2], input_info_p[str_piece_index_l +3] );
            
            char str_piece_l[] = {
                input_info_p[str_piece_index_l],
                input_info_p[str_piece_index_l +1],
                input_info_p[str_piece_index_l +2],
                input_info_p[str_piece_index_l +3]
            };
            
            pieces.push_back( Parse( str_piece_l ) );
            tiles_table_v[indexes.x_v][indexes.y_v]->PutPiece( & pieces[pieces.size() -1] );
            
            //Parse debug
            std::cout << tiles_table_v[indexes.x_v][indexes.y_v]->GetAdress() <<
            " contains Piece: " <<
            tiles_table_v[indexes.x_v][indexes.y_v]->piece_p->GetType() << std::endl;
        }
        
    }
    
    //Pieces Factory
    Piece & Board::Parse( const char * str_piece_p ) {
        
        bool white_l = str_piece_p[0] == '+';
        Position pos_l( str_piece_p[2], str_piece_p[3] - '0' );

        switch ( str_piece_p[1] ) {
                
            case 'K':   return * new King(    pos_l, 30,  white_l, str_piece_p[1] );
            case 'Q':   return * new Queen(   pos_l, 9,   white_l, str_piece_p[1] );
            case 'R':   return * new Rook(    pos_l, 5,   white_l, str_piece_p[1] );
            case 'S':   return * new Steed(   pos_l, 3,   white_l, str_piece_p[1] );    //Knight
            case 'O':   return * new Officer( pos_l, 3,   white_l, str_piece_p[1] );    //Bishop
            default:    return * new Pawn(    pos_l, 1,   white_l, str_piece_p[1] );
        }
    }
    
    bool Board::AlowedMove( const char * move_p ) {
        
        IndexPair from( move_p[0], move_p[1] );
        
        //Check FROM
        if( tiles_table_v[from.x_v][from.y_v]->Empty() ) {
            
            std::cout << "Tile-From " << from << " is Empty!" << std::endl;
            return false;
        }
        
        IndexPair to( move_p[2], move_p[3] );
        
        //Check TO
        //If same color Piece stands on destination Tile
        if( ! tiles_table_v[to.x_v][to.y_v]->Empty() ) {
            
            if( tiles_table_v[from.x_v][from.y_v]->piece_p->White() == tiles_table_v[to.x_v][to.y_v]->piece_p->White() ) {
                
                std::cout << "Not alowed to put from " << from << " to " << to << ": on the same color Piece! " << std::endl;
                return false;
            }
        }
        
        //EXCEPT STEED !!!
        //----------------
        std::cout << "PIECE: " << tiles_table_v[from.x_v][from.y_v]->piece_p->GetType() << std::endl;
        //Check each Axe direction: Is it path TO
        for( int a = 0; a < tiles_table_v[from.x_v][from.y_v]->piece_p->axes.size(); a++ ) {
            
            IndexPair temp( from + tiles_table_v[from.x_v][from.y_v]->piece_p->axes[a] );
            //Check each Tile on this Axe direction
            while( temp.OnBoard() ) {
                
                //Exit from cycle with result
                if( temp == to ) {
                    
                    std::cout << "SUCCESS: Desired move is on the axe." << std::endl;
                }
                temp += tiles_table_v[from.x_v][from.y_v]->piece_p->axes[a];
            }
            
        }
        //----------------
        
        return true;
    }
    
}
