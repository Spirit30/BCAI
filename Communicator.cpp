//
//  Communicator.cpp
//  BCAI
//
//  Created by Max Botviniev on 15.10.15.
//  Copyright (c) 2015 Max Botviniev. All rights reserved.
//

#include "Communicator.h"

//Debug
#include <iostream>

namespace BCAI {
    
    //Init Point for AI block
    char * Communicator::GetDecision( const char * game_p ) const {
        
        //...
        char  * AI_move = new char[4] /*{ 'A', '7', 'A', '6' }*/ ;
        
        //Get Move
        //Board board( input_info_p );
        //Piece * result = board.GetMove();
        //....
        
        InputFill(AI_move);
        
        return AI_move;
    }
    
    bool Communicator::RulesAdvisor( const char * game_p, const char * move_p, bool white_turn_v ) const {
        
        //Empty input case
        //-------------------
        if( strlen(move_p) == 0 || strlen(game_p) == 0 ) {
            
            std::cout << "Waste RulesAdvisor call." << std::endl;
            return false;
        }
        //-------------------
        
        //If User moves other side piece
        //-------------------
        /*char color_l = '0';
        //Foreach str-Piece: +RA1
        for( int str_piece_index_l = 0; str_piece_index_l < strlen(game_p); str_piece_index_l += 4 ) {
            
            for( int i = 2; i < 4; i++) {
                
                int index = str_piece_index_l + i;
                
                if( game_p[ index ] != move_p[ i -2 ] ) break;
                else if( i == 3 ) {
                    
                    color_l = game_p[ str_piece_index_l ];
                }
            }
        }
        
        if( color_l != '+' && color_l != '-' ) std::cout << "Something wrong: " << color_l << std::endl;
        
        bool white_piece_l = color_l == '+';
        if( white_piece_l != white_turn_v ) {
            
            std::cout << "Not alowed to move piece of oponnent: " << move_p << std::endl;
            return false;
        }*/
        //-------------------
    
        Board board( game_p );
        
        return board.AlowedMove( move_p );
    }
}