//
//  main.cpp
//  BCAI
//
//  Created by Max Botviniev on 15.10.15.
//  Copyright (c) 2015 Max Botviniev. All rights reserved.
//

#include <iostream>
#include <vector>
#include "Communicator.h"

//FRONTEND Classes
//-----------------------

class Tile {
public:
    const static unsigned int TILES_PER_AXE = 8;
    const static unsigned int TILES = 64;
    const static unsigned int LINES = 3;
    const static unsigned int CHARS_PER_ROW = 6;
    //-------------
    Tile( bool color_v, char info_v[] );
    char * GetLine( unsigned int index );
    //~Tile();
private:
    char * lines_v[LINES];
};

    Tile::Tile( bool white_v, char info_v[] ) {
        
    char info_line_l[6];
        info_line_l[0] = info_line_l[5] = '|';  //white_v ? '|' : '|';
        info_line_l[1] = info_v[0];
        info_line_l[2] = info_v[1];
        info_line_l[3] = info_v[2];
        info_line_l[4] = info_v[3];
        
    lines_v[0] = new char[6];
    lines_v[1] = new char[6];
    lines_v[2] = new char[6];
        
    strcpy( lines_v[0], white_v ? "|    |" : "|####|" );
    strcpy( lines_v[1], info_line_l );
    strcpy( lines_v[2], white_v ? "|____|" : "|####|" );
}


char * Tile::GetLine( unsigned int index ) {
    return lines_v[ index ];
}

/*Tile::~Tile() {
    for( int i = 0; i < LINES; i++)
    {
        delete lines_v[i];
    }
}*/

//FRONTEND
//-----------------------

std::vector<Tile> ParseDecision( char * decision_p )
{
    std::vector<Tile> result;
    bool white_l = true;
    for(int i = 0; i < Tile::TILES; i++)
    {
        Tile tile( white_l, decision_p );
        //std::cout << white_l << std::endl;
        white_l = !white_l;
        
        result.push_back( tile );
    }
    return result;
}

//-----------

inline unsigned int ClampTilesRowOrder( unsigned int index )
{
    return index < ( Tile::LINES -1 ) ? ( index +1 ) : 0;
}

//-----------

char * GetOutput( std::vector<Tile> parsed_decision_p ) {

    //Data
    //-----------
    const unsigned int CHARS_PER_LINE = Tile::CHARS_PER_ROW * Tile::TILES_PER_AXE; // 6 horisontal chars for Tile * 8 horizontal Tiles per Board
    const unsigned int LINES_PER_BOARD = Tile::LINES * Tile::TILES_PER_AXE; // 3 rows per Tile * 8 vertical Tiles per Board
    
    const unsigned int OUTPUT_LEGHT =  CHARS_PER_LINE * LINES_PER_BOARD +
                                    //rows_per_board_l + // '\n' for each row
                                    1; // for '\0' terminator
    
    //Fill
    //-----------
    char * resullt_p = new char[ OUTPUT_LEGHT ];
    
    unsigned int tiles_row_index_l = -1;
    //unsigned int tile_index = 0;
    
    
    for( int y = 0; y < OUTPUT_LEGHT -1; y++ ) {
        
        unsigned int char_order_in_line_v = y % CHARS_PER_LINE;
        //If board line ends
        if( char_order_in_line_v == 0 ) {
            //Start new line
            resullt_p[ y ] = '\n';
            //Increment line content index
            tiles_row_index_l = ClampTilesRowOrder( tiles_row_index_l );
            //tile_index -= Tile::TILES_PER_AXE;
        }
        else {
            //Increment symbol of tile's row
            unsigned int tile_row_char_index_l = y % Tile::CHARS_PER_ROW;
            
            //!!!
            //Update index of current Tile
            //tile_index = char_order_in_line_v % Tile::TILES_PER_AXE;
            //std::cout << tile_index << std::endl;
            
            //Insert current symbol to output text
            resullt_p[ y ] = parsed_decision_p[   0   ].GetLine( tiles_row_index_l )[ tile_row_char_index_l ];
        }
    }
    resullt_p[ OUTPUT_LEGHT -1 ] = '\0';
    
    return resullt_p;
}

//-----------------------

int main(int argc, const char * argv[]) {
    
    BCAI::Communicator communicator;

    char * output = GetOutput( ParseDecision( communicator.GetDecision(argv[0]) ) );
    std::cout << output;
    delete[] output;
    
    return 0;
}


