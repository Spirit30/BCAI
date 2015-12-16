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
            
				tiles_table_v[x_index_l][y_index_l] = new Tile( Position('A' + x_index_l, y_index_l + 1) );
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

	Piece & Board::GetPiece(IndexPair adress) {

		return * tiles_table_v[adress.x_v][adress.y_v]->piece_p;
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
            
			if ( GetPiece(from).White() == GetPiece(to).White() ) {
                
                std::cout << "Not alowed to put from " << from << " to " << to << ": on the same color Piece! " << std::endl;
                return false;
            }
        }
        
        /*//EXCEPT STEED !!!
        //----------------
		int desired_axe_index_l = -1;
        //Check each Axe direction: Is it path TO
		for (int a = 0; a < GetPiece(from).axes.size(); a++) {
            
			if ( GetPiece(from).axes[a] == from.Direction(to).Normilized() ) {

				std::cout << "SUCCESS: Desired move is on this axe: " << GetPiece(from).axes[a] << std::endl;
				desired_axe_index_l = a;
				break;
			}
        }
		if (desired_axe_index_l == -1) {

			std::cout << "FAIL: Move do NOT belongs to any Axe of choosen Piece: " << GetPiece(from) << std::endl;
			return false;
		}

		//Check desired Axe
		IndexPair temp(from + GetPiece(from).axes[ desired_axe_index_l ]);
		//Check each Tile on this Axe direction
		while (temp.OnBoard()) {

			//Exit from cycle with result
			if (temp == to) {

				std::cout << "SUCCESS: No other pieces on the Axe." << std::endl;
				break;
			}
			else if ( ! tiles_table_v[temp.x_v][temp.y_v]->Empty() ) {

				std::cout << "FAIL: Other piece ( " << GetPiece(temp) << " ) on the axe." << std::endl;
				return false;
			}
			temp += GetPiece(from).axes[ desired_axe_index_l ];
		}*/

        //----------------
        //Ask Piece
		return GetPiece(from).AlowedMove();
    }
    
}
