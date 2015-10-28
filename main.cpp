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

//FRONTEND Classes
//-----------------------

class Tile {
public:
    const static unsigned int CHARS_PER_ROW = 6;
    const static unsigned int LINES = 3;
    Tile( bool color_v, char info_v[] );
    char * GetLine( unsigned int index );
    ~Tile();
private:
    char * lines_v[LINES];
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
    for( int i = 0; i < LINES; i++)
    {
        delete lines_v[i];
    }
}

//FRONTEND
//-----------------------

inline unsigned int ClampTilesRowOrder( unsigned int index )
{
    return index < ( Tile::LINES -1 ) ? ( index +1 ) : 0;
}

//-----------

char * GetOutput( /*char * board_state_r*/ ) {

    //Data
    //-----------
    unsigned int chars_per_row_l = Tile::CHARS_PER_ROW * 8; // 6 horisontal chars for Tile * 8 horizontal Tiles per Board
    unsigned int rows_per_board_l = Tile::LINES * 8; // 3 rows per Tile * 8 vertical Tiles per Board
    
    unsigned int output_length_l =  chars_per_row_l * rows_per_board_l +
                                    //rows_per_board_l + // '\n' for each row
                                    1; // for '\0' terminator
    
    char tile_info[] =  "BPB2";
    Tile whiteTile( true, tile_info );
    Tile blackTile( false, tile_info );
    
    
    //Fill
    //-----------
    char * resullt_p = new char[ output_length_l ];
    
    unsigned int vertical_tile_char_index_l = -1;
    
    for( int y = 0; y < output_length_l -1; y++ ) {
        
        //If board line ends
        if( y % chars_per_row_l == 0 ) {
            //Start new line
            resullt_p[ y ] = '\n';
            //Increment line content index
            vertical_tile_char_index_l = ClampTilesRowOrder( vertical_tile_char_index_l );
        }
        else {
            //Increment symbol of line
            unsigned int horizontal_tile_char_index_l = y % Tile::CHARS_PER_ROW;
            //Insert current symbol to output text
            resullt_p[ y ] = blackTile.GetLine( vertical_tile_char_index_l )[ horizontal_tile_char_index_l ];
        }
    }
    resullt_p[ output_length_l -1 ] = '\0';
    
    return resullt_p;
}

//-----------------------

int main(int argc, const char * argv[]) {
    
    //BCAI::Communicator communicator;
    //string output = communicator.GetDecision("KA1");
    
    char * output = GetOutput();
    cout << output;
    delete[] output;
    
    return 0;
}


