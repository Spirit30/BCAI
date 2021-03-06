//
//  Pawn.cpp
//  BCAI
//
//  Created by Max Botviniev on 20.10.15.
//  Copyright (c) 2015 Max Botviniev. All rights reserved.
//

#include "Pawn.h"
namespace BCAI {

	Pawn::Pawn(Position _position_v, unsigned int _score_v, bool _white_v, char type_v)
		: Piece(_position_v, _score_v, _white_v, type_v) {

		axes = * new std::vector<IndexPair>(3);
		axes[0] = *new IndexPair(-1, _white_v ? 1 : -1);
		axes[1] = *new IndexPair(0, _white_v ? 1 : -1 );
		axes[2] = *new IndexPair(1, _white_v ? 1 : -1);
	}
}
