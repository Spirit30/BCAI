//
//  Piece.h
//  BCAI
//
//  Created by Max Botviniev on 20.10.15.
//  Copyright (c) 2015 Max Botviniev. All rights reserved.
//

#ifndef __BCAI__Piece__
#define __BCAI__Piece__

#include <stdio.h>
#include <vector>


#include <typeinfo>


//-------------------
#include "Position.hpp"

#include <iostream>

namespace BCAI {
    
    class Piece {
        
    private:
        //Data
        Position position_v;
		char type_v;
		bool white_v;
		unsigned int score_v;
    public:
        std::vector<IndexPair> axes;
        //---------------------
		//Constructors
		Piece() : position_v(Position('Z', 666)), score_v(777), white_v(6), type_v('E') {};

        Piece( Position _position_v, unsigned int _score_v, bool _white_v, char _type_v ) : 
			position_v(_position_v), score_v(_score_v), white_v(_white_v), type_v(_type_v) {
		
			std::cout << * this << " Created." << std::endl;
		};
		Piece(const Piece & _copy) :
			position_v(_copy.position_v), score_v(_copy.score_v), white_v(_copy.white_v), type_v(_copy.type_v) {

			axes = _copy.axes; //!!!

			std::cout << * this << " Copy constructed!" << std::endl;
		};
		~Piece();
        //Accesors
        bool White();
		Position & GetPosition();
		unsigned int GetScore();
		char GetType();
		size_t Axes();
        //Algorythms
        //virtual bool AlowedMove();
		void operator = ( Piece & other);
		friend std::ostream & operator << (std::ostream & out, Piece & piece);
    }; 
}
#endif /* defined(__BCAI__Piece__) */
