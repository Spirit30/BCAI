//
//  Piece.cpp
//  BCAI
//
//  Created by Max Botviniev on 20.10.15.
//  Copyright (c) 2015 Max Botviniev. All rights reserved.
//

#include "Piece.h"

namespace BCAI {
    
	Piece::Piece() : position_v(Position('Z', 666)), score_v(777), white_v(6), type_v('E') {};
	Piece::Piece(Position _position_v, unsigned int _score_v, bool _white_v, char _type_v) :
		position_v(_position_v), score_v(_score_v), white_v(_white_v), type_v(_type_v) {

		//std::cout << * this << " Created." << std::endl;
	};
	Piece::Piece(const Piece & _copy) :
		position_v(_copy.position_v), score_v(_copy.score_v), white_v(_copy.white_v), type_v(_copy.type_v) {

		axes = _copy.axes; //!!!

		//std::cout << *this << " Copy constructed!" << std::endl;
	};

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
    
	/*bool Piece::AlowedMove(const Board & board_r, const IndexPair & from, const IndexPair & to) {
        
		std::cout << "Permited by Base Piece" << std::endl;
        return true;
    }*/

	Piece::~Piece() {

		//std::cout << * this << " - is Destroyed!" << std::endl;
	}

	void Piece::operator = ( Piece & other) {

		if ( & other == this ) {

			std::cout << "WASTE COPY: " << * this << std::endl;
		}
		//std::cout << other << " ASSIGNED TO: " << * this << std::endl;

		position_v = other.position_v;
		type_v = other.type_v;
		white_v = other.white_v;
		score_v = other.score_v;
		axes = other.axes;
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