//
//  Position.cpp
//  BCAI
//
//  Created by Max Botviniev on 13.11.15.
//  Copyright © 2015 Max Botviniev. All rights reserved.
//

#include "Position.hpp"

namespace BCAI {
    
    bool Position::operator == ( Position & other )const {
        
        return this->x == other.x && this->y == other.y;
    }
    
    std::ostream & operator<<(std::ostream & os, const Position & pos)
    {
        os << "( X: " << pos.x << ", " << "Y: " << pos.y << ")";
        return os;
    }
}