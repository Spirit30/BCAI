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
    
    bool Board::AllowedMove( const char * move_p ) {
        
        IndexPair from( move_p[0], move_p[1] );
        
        //Check FROM
        if( tiles_table_v[from.x_v][from.y_v]->Empty() ) {
            
            std::cout << "Tile-From " << from << " is Empty!" << std::endl;
            return false;
        }
        
        IndexPair to( move_p[2], move_p[3] );
        
		//Check is move performed
		if (from == to) {

			std::cout << "Move didn't performed!" << std::endl;
			return false;
		}

        //Check TO
        //If same color Piece stands on destination Tile
        if( ! tiles_table_v[to.x_v][to.y_v]->Empty() ) {
            
			if ( GetPiece(from).White() == GetPiece(to).White() ) {
                
                std::cout << "Not alowed to put from " << from << " to " << to << ": on the same color Piece! " << std::endl;
                return false;
            }
        }

		//ASK Piece
        //----------------
		switch (GetPiece(from).GetType())
		{
			case 'P': return AllowedMovePawn(from, to);
			case 'K': return AllowedMoveKing(from, to);
			//...
			
			//R, O, Q
			default: return AllowedMoveAxe(from, to);
		}
    }

	int Board::DesiredAxe(IndexPair & from, IndexPair & to) {

		//Check each Axe direction: Is it path TO
		for (int a = 0; a < GetPiece(from).axes.size(); a++) {
            
            IndexPair A = GetPiece(from).axes[a];
            IndexPair B = from.Direction(to).Normilized();

			if (A == B) {

				std::cout << "SUCCESS: Desired move is on this axe: " << GetPiece(from).axes[a] << std::endl;
				return a;
			}
			std::cout << "Checked axe: " << GetPiece(from).axes[a] << std::endl;
		}
		std::cout << "FAIL: Move do NOT belongs to any Axe of choosen Piece: " << GetPiece(from) << std::endl;
		std::cout << "Move from: " << from << " to: " << to << std::endl;

		return -1;
	}

	bool Board::AllowedMoveAxe(IndexPair & from, IndexPair & to) {

		int desired_axe_index_l = DesiredAxe( from, to );

		if ( desired_axe_index_l == -1) {

			return false;
		}

		//Create next adress after position on this axe
		IndexPair step(from + GetPiece(from).axes[desired_axe_index_l]);
		//Check each Tile on this Axe direction
		while (step.OnBoard()) {

			//Exit if decline
			if (step == to) {

				std::cout << "SUCCESS: No other pieces on the Axe." << std::endl;
				break;
			}
			else if (!tiles_table_v[step.x_v][step.y_v]->Empty()) {

				std::cout << "FAIL: Other piece ( " << GetPiece(step) << " ) on the axe." << std::endl;
				return false;
			}
			
			step += GetPiece(from).axes[desired_axe_index_l];
		}

		//----------------
		return true;
	}

	bool Board::AllowedMoveKing(IndexPair & from, IndexPair & to) {

		int desired_axe_index_l = DesiredAxe(from, to);

		if (desired_axe_index_l == -1) {

			return false;
		}

		//Create next adress after position on this axe
		IndexPair step(from + GetPiece(from).axes[desired_axe_index_l]);

		return step == to;
	}
    
	bool Board::AllowedMovePawn(IndexPair & from, IndexPair & to) {

		int desired_axe_index_l = DesiredAxe(from, to);

		if (desired_axe_index_l == -1) {

			return false;
		}

		//Create next adress after position on this axe
		IndexPair step(from + GetPiece(from).axes[desired_axe_index_l]);
		//Check Bounds
		if (!step.OnBoard()) {

			std::cout << "End of Board is achieved: " << GetPiece(from) << std::endl;
			return false;
		}
		//FRONT
		if (desired_axe_index_l == 1 ) {

			bool first_move_l = from.y_v == ( GetPiece(from).White() ? 1 : 6 );
			unsigned int max_step_length_l = first_move_l ? 2 : 1;
			
			if (std::abs(to.y_v - from.y_v) > max_step_length_l) {

				std::cout << "Step length allowed: " << max_step_length_l << std::endl;
				return false;	
			}
			else if (!tiles_table_v[step.x_v][step.y_v]->Empty()) {

				std::cout << "Other piece in front: " << GetPiece(step) << std::endl;
				return false;
			}
			else if (	first_move_l && 
				!tiles_table_v[step.x_v + GetPiece(from).axes[desired_axe_index_l].x_v][step.y_v + GetPiece(from).axes[desired_axe_index_l].y_v]->Empty()) {

				std::cout << "Other piece in front: " << GetPiece(step) << std::endl;
				return false;
			}
		}
		//ON ANGLE
		else /*if (desired_axe_index_l == 0 || desired_axe_index_l == 2)*/ {

			if (tiles_table_v[step.x_v][step.y_v]->Empty() ||
				GetPiece(from).White() == GetPiece(step).White()) {

				std::cout << "Not allowed beat ON ANGLE - " << GetPiece(from) << std::endl;
				return false;
			}
		}

		//----------------
		return true;
	}
}
