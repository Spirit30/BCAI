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
namespace BCAI {
    
    class Position {
        
    private:
        const char x;
        const unsigned int y;
    public:
        Position( char _x, unsigned int _y ) : x(_x), y(_y) { };
    };
}
#endif /* Position_hpp */