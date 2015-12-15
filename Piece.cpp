//
//  Piece.cpp
//  BCAI
//
//  Created by Max Botviniev on 20.10.15.
//  Copyright (c) 2015 Max Botviniev. All rights reserved.
//

#include "Piece.h"

namespace BCAI {
    

    //---------------------------
    
	bool Piece::White() {
        
        return white_v;
    }
    
	Position & Piece::GetPosition() {
        
        return position_v;
    }
	unsigned int Piece::GetScore() {
        
        return score_v;
    }
    
	char Piece::GetType() {
        
        return type_v;
    }

	size_t Piece::Axes() {

		return axes.size();
	}
    
    /*bool Piece::AlowedMove() {
        
        //Check each Axe direction
        for( int a = 0; a < axes.size(); a++ ) {
            
            //IndexPair temp_position( )
            //Check each Tile on this Axe direction
            
            
        }
        std::cout << "Decline in Piece" << std::endl;
        return false;
    }*/

	Piece::~Piece() {

		std::cout << * this << " - is Destroyed!" << std::endl;
	}

	void Piece::operator = ( Piece & other) {

		if (&other == this) {

			std::cout << "WASTE COPY: " << *this << std::endl;
		}
		std::cout << other << " ASSIGNED TO: " << *this << std::endl;

		position_v = other.position_v;
		type_v = other.type_v;
		white_v = other.white_v;
		score_v = other.score_v;
		axes = other.axes;	//!!!
	}

	std::ostream & operator << (std::ostream & out, Piece & piece) {

		out << "Piece Output || " <<
			"Position: " << piece.GetPosition() <<
			", Type: " << piece.GetType() <<
			", Color: " << (piece.White() ? "White" : "Black") <<
			", Axes: " << piece.Axes();

		return out;
	}
}