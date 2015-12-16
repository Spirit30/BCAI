//
//  Position.hpp
//  BCAI
//
//  Created by Max Botviniev on 13.11.15.
//  Copyright © 2015 Max Botviniev. All rights reserved.
//

#ifndef Position_hpp
#define Position_hpp

#include <stdio.h>
#include <iostream>
#include <cmath>

namespace BCAI {
    
    struct Position {
        
        char x;
        unsigned int y;
        Position( char _x, unsigned int _y ) : x(_x), y(_y) { };
		Position & operator = (const Position & other);
        bool operator == ( Position & other ) const;
        friend std::ostream & operator << (std::ostream & os, Position & pos);
    };
    
    //-------------------------
    //-------------------------
    
    struct IndexPair {
        
        int x_v = 66;
        int y_v = 99;
        
		IndexPair();
		IndexPair(int _x_v, int _y_v);
        IndexPair( char _x_v, char _y_v );
        IndexPair( const IndexPair & other );
        IndexPair( const Position & pos );
        bool OnBoard();
        IndexPair Abs(const IndexPair & other);
		IndexPair Normilized();
		IndexPair Direction( IndexPair to );
        void operator += (const IndexPair & other);
        IndexPair operator + (const IndexPair & other);
		IndexPair operator - (const IndexPair & other);
		void operator = (IndexPair & other);
        bool operator == ( IndexPair & other ) const;
        bool operator > ( IndexPair & other ) const;
        friend std::ostream & operator << (std::ostream & os, const IndexPair & indexes);
    };
}
#endif /* Position_hpp */
