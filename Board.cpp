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
            
				Position position('A' + x_index_l, y_index_l + 1);
				tiles_table_v[x_index_l][y_index_l] = new Tile(position);
            }
        }

        //Parse Pieces data to Pieces list and to Tiles array
		pieces = * new std::vector<Piece>( strlen(input_info_p) / 4 );

        for( int str_piece_index_l = 0; str_piece_index_l < strlen(input_info_p); str_piece_index_l += 4 ) {
            
            IndexPair indexes( input_info_p[str_piece_index_l +2], input_info_p[str_piece_index_l +3] );
            
            char str_piece_l[] = {
                input_info_p[str_piece_index_l],
                input_info_p[str_piece_index_l +1],
                input_info_p[str_piece_index_l +2],
                input_info_p[str_piece_index_l +3]
            };
            
			Piece * piece_l = & Parse(str_piece_l);
			pieces[str_piece_index_l / 4] = * piece_l;
            tiles_table_v[indexes.x_v][indexes.y_v]->PutPiece( piece_l );
            
            //TEST
            /*std::cout << tiles_table_v[indexes.x_v][indexes.y_v]->GetAdress() <<
            " contains Piece: " << * tiles_table_v[indexes.x_v][indexes.y_v]->piece_p << std::endl;*/
        }
        
    }
    
    //Pieces Factory
    Piece & Board::Parse( const char * str_piece_p ) {
        
        bool white_l = str_piece_p[0] == '+';
        Position * pos_p = new Position( str_piece_p[2], str_piece_p[3] - '0' );

        switch ( str_piece_p[1] ) {
                
			case 'K':   return * new King(*pos_p, 30, white_l, str_piece_p[1]);
			case 'Q':   return * new Queen(*pos_p, 9, white_l, str_piece_p[1]);
			case 'R':   return * new Rook(*pos_p, 5, white_l, str_piece_p[1]);
			case 'S':   return * new Steed(*pos_p, 3, white_l, str_piece_p[1]);    //Knight
			case 'O':   return * new Officer(*pos_p, 3, white_l, str_piece_p[1]);    //Bishop
			default:    return * new Pawn(*pos_p, 1, white_l, str_piece_p[1]);
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

		//TEST
		std::cout << "LENGTH: " << pieces.size() << std::endl;
		/*for ( int t = 0; t < pieces.size(); t++ )
		{
			std::cout << "Position: " << pieces[t].GetPosition() << ", " <<
				"Type: " << pieces[t].GetType() << ", " <<
				"Color: " << pieces[t].White() << std::endl;
		}
		
		for (int x_t = 0; x_t < 8; x_t++) {

			for (int y_t = 0; y_t < 8; y_t++) {

				if ( ! tiles_table_v[x_t][y_t]->Empty() ) {

					std::cout	<< x_t << " - " << y_t << ", " 
								<< "TEST " << * tiles_table_v[x_t][y_t]->piece_p << std::endl;
				}
			}
		}
		*/
        
        //EXCEPT STEED !!!
        //----------------
		
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
