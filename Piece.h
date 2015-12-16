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
		//Constructors / Destructors
		Piece();
		Piece(Position _position_v, unsigned int _score_v, bool _white_v, char _type_v);
		Piece(const Piece & _copy);
		~Piece();
        //Accesors
        bool White();
		Position & GetPosition();
		unsigned int GetScore();
		char GetType();
		size_t Axes();
        //Algorythms
        virtual bool AlowedMove();
		void operator = ( Piece & other);
		friend std::ostream & operator << (std::ostream & out, Piece & piece);
    }; 
}
#endif /* defined(__BCAI__Piece__) */
