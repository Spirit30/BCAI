//
//  Board.cpp
//  BCAI
//
//  Created by Max Botviniev on 20.10.15.
//  Copyright (c) 2015 Max Botviniev. All rights reserved.
//

#include "Board.h"


namespace BCAI {
    
    Board::Board( char * input_info_p)
    {
        //Parse data pieces list
        /*for( int i = 0; i < input_info_r.length(); i++ )
        {
            switch ( input_info_r[ i ] )
            {
                case 'K':
                {
                    pieces.push_back( new King( input_info_r[ i+1 ], input_info_r[ i+2 ], 1 ) );
                    i+=2;
                    break;
                }
                default:
                {
                    break;
                }
            }
        }*/
    }
    
    Piece * Board::GetMove()
    {
        return pieces[0];
    }
    
}
