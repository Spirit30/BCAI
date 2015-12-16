//
//  Rook.cpp
//  BCAI
//
//  Created by Max Botviniev on 20.10.15.
//  Copyright (c) 2015 Max Botviniev. All rights reserved.
//

#include "Rook.h"

namespace BCAI {
    
    Rook::Rook( Position _position_v, unsigned int _score_v, bool _white_v, char type_v ) : Piece( _position_v, _score_v, _white_v, type_v ) {
        
		axes = * new std::vector<IndexPair>(4);
        axes[0] = IndexPair(-1, 0 );
        axes[1] = IndexPair( 1, 0 );
        axes[2] = IndexPair( 0,-1 );
        axes[3] = IndexPair( 0, 1 );

    }

	bool Rook::AlowedMove() {

		/*//----------------
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

		return true;
	}
}