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
#include <cstdio>
#include <vector>
    #ifdef WIN_BCAI
    #include <string>
    #endif
#include <exception>
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

    //Frontent version
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
    char * game_p;
public:
    GameState();
    void Save( char * move_p );
    char * Get();
    size_t Length();
};

GameState::GameState() {
    
    char init_game_l[] = "+RA1+SB1+OC1+QD1+KE1+OF1+SG1+RH1+PA2+PB2+PC2+PD2+PE2+PF2+PG2+PH2-PA7-PB7-PC7-PD7-PE7-PF7-PG7-PH7-RA8-SB8-OC8-QD8-KE8-OF8-SG8-RH8";
    game_p = new char[128];
    for(int i = 0; i < std::strlen(init_game_l); i++) {
        
        game_p[i] = init_game_l[i];
    }
}

void GameState::Save( char * move_p ) {
    
    std::cout << game_p << std::endl;

    //DELETE beated Piece
    //Foreach str-Piece: +RA1
    for( int str_piece_index_l = 0; str_piece_index_l < Length(); str_piece_index_l+=4 ) {
     
        for( int i = 2; i < 4; i++) {
            
            int index = str_piece_index_l + i;

            if( game_p[ index ] != move_p[ i ] ) {
                
                break;
            }
            //If pos of new move == one of the pieces position -> DELETE this piece
            else if( i == 3 ) {
                
                size_t len_l = Length() -4 +1;
                char temp_game_l[ len_l ];
                std::strncpy( temp_game_l, game_p, index -3 );
                temp_game_l[ index -3 ] = '\0';
                std::strcat(temp_game_l, game_p + index + 1);
                temp_game_l[ index +1 ] = '\0';
                delete[] game_p;
                game_p = new char [ len_l ];
                std::strcpy(game_p, temp_game_l);
                
                std::cout << "DELETED Piece" << std::endl;
                std::cout << game_p << std::endl;
            }
        }
    }
    
    //SAVE moved Piece
    //Foreach str-Piece: +RA1
    for( int str_piece_index_l = 0; str_piece_index_l < Length(); str_piece_index_l+=4 ) {
        
        for( int i = 2; i < 4; i++) {
            
            int index = str_piece_index_l + i;
            
            if( game_p[ index ] != move_p[ i -2 ] ) {
                
                break;
            }
            else if( i == 3 ) {
                
                game_p[ index -1 ] = move_p[ i -1 ];
                game_p[ index ] = move_p[ i ];
                std::cout << "REC" << std::endl;
                std::cout << game_p << std::endl;
            }
        }
    }
}

char * GameState::Get() {
    
    return game_p;
}

size_t GameState::Length() {
    
    return std::strlen(game_p);
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
                    
                    //std::cout << "Move: " << decision_p << std::endl;
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

class InputSideEx: public std::exception
{
    virtual const char* what() const throw() {
        
        return "Invalid input. Please use 'w' or 'b' chars only.";
    }
    
} inputSideEx;

//-----------------------

//True if White
bool ChooseSide() {
    
    std::cout << "Choose white or black: w / b ?" << std::endl;
    char color_l = '\0';
    bool choosed = false;
    while ( std::cin && !choosed ) {
        
        try {
            
            std::cin >> color_l;
            color_l = std::tolower(color_l);
            choosed = color_l == 'w' || color_l == 'b';
            if( !choosed ) throw inputSideEx;
        }
        catch( std::exception & inputSideEx ) {
            
            std::cin.clear();
            std::cout << inputSideEx.what() << std::endl;
        }
    }
    std::cin.get();
    
    bool result = color_l == 'w';
    std::cout << "Thank you! USER 1 side is: " << ( result ? "White" : "Black" ) << ", USER 2 side is: " << ( ! result ? "White" : "Black" ) << std::endl << std::endl;
    return result;
}

//-----------------------

class InputMoveEx: public std::exception
{
    virtual const char* what() const throw() {
        
        return "Invalid input. Please use chars A-H and digits 1-8.";
    }
    
} inputMoveEx;

//-----------------------

void InputFill( char * input_storage_p ) {
    
    const unsigned int input_length_l = 4;
    unsigned int char_index_l = 0;
    
    while (std::cin && char_index_l < input_length_l) {
        
        try {
            
            std::cin.get (input_storage_p[char_index_l]);
            input_storage_p[char_index_l] = toupper(input_storage_p[char_index_l]);
            
            //Check if input chars are NOT related to coordinates system
            if( (input_storage_p[char_index_l] < 'A' || input_storage_p[char_index_l] > 'H') &&
                (input_storage_p[char_index_l] < '1' || input_storage_p[char_index_l] > '8') ) {
                
                throw inputMoveEx;
            }
            else {
                
                char_index_l++;
            }
        }
        catch (std::exception & inputMoveEx) {
            
            char_index_l = 0;
            std::cout << inputMoveEx.what() << std::endl;
        }
    }
    std::cin.get();
}

//-----------------------

void Print( GameState & game_state_r, const char * move_p ) {
    //Parse MOVE string to this Frontend data structure ( list of Tiles )
    std::vector<Tile> parsed_decision_v;
 
    parsed_decision_v = ParseDecision( parsed_decision_v, move_p, game_state_r.Get() );
    
    //Serialize list of Tiles to output string
    char * output = SerializeToOutput( parsed_decision_v );
    std::cout << output;
    delete[] output;
}

//-----------------------

void UserMove( const BCAI::Communicator & communicator, const char * input_game_p, char * move_p, bool white_side_l ) {
    
    bool validMove = false;
    while ( ! validMove ) {
        
        InputFill(move_p);
        validMove = communicator.RulesAdvisor( input_game_p, move_p, white_side_l );
        
        if( ! validMove ) std::cout << "This move is not allowed! Please, repeat input." << std::endl;
    }
}

//-----------------------

int main(int argc, const char * argv[]) {
    
    //User side
    bool white_side_l = ChooseSide();
    
    //Frontend memory stored in argv[0] if call from other app
    GameState game_state_v;
    
    //AI ENTRY POINT
    BCAI::Communicator communicator;
    
    char * previous_move_p = new char[4];
    //MAIN LOOP
    int turn_l = 1;
    while ( turn_l < INT_MAX ) {
        
        char * move_p = new char[4];
        
        if( turn_l % 2 ) {
            
            std::cout << "USER 1 MOVE # " << turn_l << std::endl;
            UserMove( communicator, game_state_v.Get(), move_p, white_side_l );
            game_state_v.Save( move_p );
        }
        else {
            
            std::cout << "USER 2 MOVE # " << turn_l << std::endl;
            UserMove( communicator, game_state_v.Get(), move_p, ! white_side_l );
            game_state_v.Save( move_p );
        }
        
        Print( game_state_v, move_p );
        delete[] move_p;
        
        //Print( game_state_v, communicator.GetDecision(game_state_v.Get()) );
        turn_l++;
    }
    delete[] previous_move_p;
    
#ifdef WIN_BCAI
	system("Pause");
#endif

    return 0;
}


