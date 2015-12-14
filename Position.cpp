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
    
    //-------------------------
    //-------------------------
    
    IndexPair::IndexPair( char _x_v, char _y_v ) {
        
        x_v = _x_v - 'A';
        y_v = _y_v - '0' -1;    // Index begins from 0, that's why: -1
    }
    
    IndexPair::IndexPair( const IndexPair & other ) {
        
        x_v = other.x_v;
        y_v = other.y_v;
    }
    
    IndexPair::IndexPair( const Position & pos ) {
        
        x_v = pos.x - 'A';
        y_v = pos.y - 1;        // Index begins from 0, that's why: -1
    }
    
    bool IndexPair::OnBoard() {
        
        return x_v > -1 && x_v < 8 && y_v > -1 && y_v < 8;
    }
    
    IndexPair IndexPair::Abs(const IndexPair & other) {
        
        return IndexPair( std::abs(other.x_v), std::abs(other.y_v) );
    }
    
    void IndexPair::operator += (const IndexPair & other) {
        
        this->x_v += other.x_v;
        this->y_v += other.y_v;
    }
    
    IndexPair IndexPair::operator + (const IndexPair & other) {
        
        return IndexPair( this->x_v + other.x_v, this->y_v + other.y_v );
    }
    
    bool IndexPair::operator == ( IndexPair & other )const {
        
        return this->x_v == other.x_v && this->y_v == other.y_v;
    }
    
    bool IndexPair::operator > ( IndexPair & other )const {
        
        return this->x_v > other.x_v && this->y_v > other.y_v;
    }
    
    std::ostream & operator << (std::ostream & os, const IndexPair & indexes)
    {
        os << "( x_i: " << indexes.x_v << ", " << "y_i: " << indexes.y_v << ")";
        return os;
    }
}