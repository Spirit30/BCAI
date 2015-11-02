//
//  main.cpp
//  BCAI
//
//  Created by Max Botviniev on 15.10.15.
//  Copyright (c) 2015 Max Botviniev. All rights reserved.
//
//#define WIN_BCAI
//#define MAC_BCAI

#include <iostream>
#include <vector>
#include <string>
#include "Communicator.h"

//FRONTEND Classes
//-----------------------

class Tile {
public:
    //Data
    //-------------
    const static unsigned int TILES_PER_AXE = 8;
    const static unsigned int TILES = 64;
    const static unsigned int ROWS = 3;
    const static unsigned int CHARS_PER_ROW = 6;
    //-------------
    Tile( const bool & white_r, const char * piece_info_r, const char & x_r, const unsigned int & y_r );
    const char * GetLine( unsigned int index ) const;
private:
    bool white_v;
    //char x_v = '?';
    //unsigned int y_v = 0;
    char tile_info_v[6];
    char piece_info_v[6];
    char FillInternalSpace();
};

    Tile::Tile( const bool & white_r, const char * piece_info_r, const char & x_r, const unsigned int & y_r ) {
        
        white_v = white_r;
        //x_v = x_r;
        //y_v = y_r;
        
        piece_info_v[2] = piece_info_r[0] ? piece_info_r[0] : FillInternalSpace();
        piece_info_v[3] = piece_info_r[0] ? piece_info_r[1] : FillInternalSpace();
        
        tile_info_v[1] = x_r;
        tile_info_v[2] = std::to_string(y_r)[0];
        tile_info_v[3] = tile_info_v[4] = piece_info_v[1] = piece_info_v[4] = FillInternalSpace();
        
        tile_info_v[0] = tile_info_v[5] = piece_info_v[0] = piece_info_v[5] = '|';
}

inline char Tile::FillInternalSpace()
{
    return white_v ? ' ' : '#';
}


const char * Tile::GetLine( unsigned int index ) const {
    
    switch( index )
    {
        case 0: return tile_info_v;                     //TOP
        case 1: return piece_info_v;                    //MIDDLE / INFO
        case 2: return white_v ? "|____|" : "|####|";   //BOTTOM
        default: return NULL;
    }
}

//-----------------------

class GameState
{
private:
    const char * init_game_p = "+RA1+SB1+OC1+QD1+KE1+OF1+SG1+RH1+PA2+PB2+PC2+PD2+PE2+PF2+PG2+PH2-PA7-PB7-PC7-PD7-PE7-PF7-PG7-PH7-RA8-SB8-OC8-QD8-KE8-OF8-SG8-RH8";
public:
    const char * Get();
    size_t Length();
};

const char * GameState::Get() {
    
    return init_game_p;
}

size_t GameState::Length() {
    
    return std::strlen(init_game_p);
}

//FRONTEND
//-----------------------

std::vector<Tile> ParseDecision( std::vector<Tile> & parsed_decision_r, const char * decision_p, char * game_p )
{

    bool decision_aplied_l = false;
    
    //bool decision_aplied_l = false;

    //Loop variables for Tiles
    bool white_l = true;
    char x_v = 'I';
    unsigned int y_v = 9;
    char piece_l[2];
    
    for(int tile_index_l = 0; tile_index_l < Tile::TILES; tile_index_l++)
    {

        //----------
        //If new line begins
        if( tile_index_l % Tile::TILES_PER_AXE == 0) {
            
            x_v -= Tile::TILES_PER_AXE;
            y_v--;
        }
        //Change color if not a new line
        else {
            
            white_l = !white_l;
        }
        //Parse piece data
        piece_l[0] = NULL;
        for( int piece_index_l = 0; piece_index_l < strlen(game_p); piece_index_l += 4) {
            
            
            if( ! decision_aplied_l ) {
            
                if( game_p[ piece_index_l + 2 ] == decision_p[ 0 ] &&
                    game_p[ piece_index_l + 3 ] == decision_p[ 1 ] ) {
                    
                    
                    
                   game_p[ piece_index_l + 2 ] = decision_p[ 2 ];
                   game_p[ piece_index_l + 3 ] = decision_p[ 3 ];
                    
                    std::cout << "Move: " << decision_p << std::endl;
                    
                    decision_aplied_l = true;
                }
            }
            
            //Compare pieces position to current Tile
            //std::cout << x_v << "_vs_" << game[ piece_index_l + 2 ] << std::endl;
            //std::cout << y_v << "_vs_" << (game[ piece_index_l + 3 ] - '0') << std::endl;
            
            //If Piece position equals to current Tile
            if( x_v == game_p[ piece_index_l + 2 ] &&
                y_v == game_p[ piece_index_l + 3 ] - '0') {
                
                piece_l[0] = game_p[ piece_index_l ];
                piece_l[1] = game_p[ piece_index_l + 1 ];
                
                //std::cout << piece_l << std::endl;
            }
        }
        
        Tile tile( white_l, piece_l, x_v, y_v );
        x_v++;
        //----------
        parsed_decision_r.push_back( tile );
    }
    return parsed_decision_r;
}

//-----------

inline unsigned int ClampTilesRowOrder( unsigned int index )
{
    return index < ( Tile::ROWS -1 ) ? ( index +1 ) : 0;
}

//-----------

char * SerializeToOutput( const std::vector<Tile> & parsed_decision_r ) {

    //Data
    //-----------
    const unsigned int CHARS_PER_LINE = Tile::CHARS_PER_ROW * Tile::TILES_PER_AXE; // 6 horisontal chars for Tile * 8 horizontal Tiles per Board
    const unsigned int LINES_PER_BOARD = Tile::ROWS * Tile::TILES_PER_AXE; // 3 rows per Tile * 8 vertical Tiles per Board
    
    const unsigned int OUTPUT_LENGHT =  CHARS_PER_LINE * LINES_PER_BOARD +
                                        LINES_PER_BOARD + // '\n' for each row
                                        1; // for '\0' terminator
    
    //Fill
    //-----------
    char * resullt_p = new char[ OUTPUT_LENGHT ];
    
    unsigned int line_index_l = 0;
    unsigned int tiles_row_index_l = -1;
    unsigned int tile_index_l = 8;
    
    unsigned int symbol_index_l = 0;
    while( symbol_index_l < OUTPUT_LENGHT -1 ) {
        
        //If line begins
        if( symbol_index_l % CHARS_PER_LINE == 0 ) {
            
            //Start new line
            resullt_p[ symbol_index_l ] = '\n';
            
            //Increment line content index
            tiles_row_index_l = ClampTilesRowOrder( tiles_row_index_l );
            
            //Return index of Tiles
            tile_index_l = line_index_l / Tile::ROWS * Tile::TILES_PER_AXE;
            line_index_l++;
            //std::cout << "_Vertical_return_" << tile_index_l << std::endl;
        }
        else {
            
            //Increment symbol of tile's row
            unsigned int tile_row_char_index_l = symbol_index_l % Tile::CHARS_PER_ROW;

            //Update index offset of current Tile
            if( tile_row_char_index_l == 0 ) tile_index_l++;
            //std::cout << "_Horizontal_offset_" << tile_index_l  << std::endl;
            
            //Insert current symbol to output text
            resullt_p[ symbol_index_l ] = parsed_decision_r[ tile_index_l ].GetLine( tiles_row_index_l )[ tile_row_char_index_l ];
            
        }
        symbol_index_l++;
    }
    resullt_p[ OUTPUT_LENGHT -1 ] = '\0';
    
    return resullt_p;
}

//-----------------------

int main(int argc, const char * argv[]) {
    
    //Frontend memory stored in argv[0] if call from other app
    GameState game_state;
    
    //Get AI MOVE
    BCAI::Communicator communicator;
    char * move_p = communicator.GetDecision( game_state.Get() );

    //Parse MOVE string to this Frontend data structure ( list of Tiles )
    std::vector<Tile> parsed_decision_v;
    char * game_p = new char[game_state.Length()];
    std::strcpy(game_p, game_state.Get());
    parsed_decision_v = ParseDecision( parsed_decision_v, move_p, game_p );
    delete game_p;
    
    //Serialize list of Tiles to output string
    char * output = SerializeToOutput( parsed_decision_v );
    std::cout << output;
    delete[] output;
    
#ifdef WIN_BCAI
	system("Pause");
#endif

    return 0;
}


