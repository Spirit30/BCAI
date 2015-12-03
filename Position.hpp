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

namespace BCAI {
    
    struct Position {
        
        const char x;
        const unsigned int y;
        Position( char _x, unsigned int _y ) : x(_x), y(_y) { };
        bool operator == ( Position & other ) const;
        friend std::ostream & operator << (std::ostream & os, const Position & pos);
    };
}
#endif /* Position_hpp */
