//
//  main.cpp
//  BCAI
//
//  Created by Max Botviniev on 15.10.15.
//  Copyright (c) 2015 Max Botviniev. All rights reserved.
//

#include <iostream>
#include "Communicator.h"
#include "Piece.h"

using std::cout;

//FRONTEND
//-----------------------

class Tile {
    const static unsigned int lines_per_tile_c = 3;
    char * lines_v[lines_per_tile_c];
public:
    Tile( bool color_v, char info_v[] );
    char * GetLine( unsigned int index );
    ~Tile();
};

    Tile::Tile( bool color_v, char info_v[] ) {
        
    char info_line_l[7];
        info_line_l[0] = info_line_l[5] = color_v ? ' ' : '*';
        info_line_l[1] = info_v[0];
        info_line_l[2] = info_v[1];
        info_line_l[3] = info_v[2];
        info_line_l[4] = info_v[3];
        info_line_l[6] = '\0';
    
        
    //Save standart lines
    lines_v[0] = new char[6];
    strcpy( lines_v[0], color_v ? "      " : "******" );
    lines_v[1] = new char[6];
    strcpy( lines_v[1], info_line_l );
    lines_v[2] = new char[6];
    strcpy( lines_v[2], color_v ? "      " : "******" );
}


char * Tile::GetLine( unsigned int index ) {
    return lines_v[ index ];
}

Tile::~Tile() {
    for( int i = 0; i < lines_per_tile_c; i++)
    {
        delete lines_v[i];
    }
}

//----------------------

void Frontend( /*char * board_state_r*/ ) {

    char tile_info[] =  "BPB2";
    Tile tileWhite( true, tile_info );
    Tile tileBlack( false, tile_info );
    
    bool whiteFirst = false;
    int index = 0;
    for( int y = 0; y < 8 * 3; y++ ) {
        
        index = index < 2 ? ( (y+3) % 3) : y % 3;
        if( index % 3 == 0 ) whiteFirst = !whiteFirst;
        
        for( int x = 0; x < 8; x++ ) {
            
            if(x % 2 == 0 && whiteFirst) {
                cout << tileWhite.GetLine( index );
            }
            else {
                cout << tileBlack.GetLine( index );
            }
        }
        
        cout << std::endl;
    }
}

int main(int argc, const char * argv[]) {
    
    //BCAI::Communicator communicator;
    //string output = communicator.GetDecision("KA1");
   
    Frontend();
    
    return 0;
}


