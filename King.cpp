//
//  King.cpp
//  BCAI
//
//  Created by Max Botviniev on 20.10.15.
//  Copyright (c) 2015 Max Botviniev. All rights reserved.
//

#include "King.h"
namespace BCAI {

	King::King(Position _position_v, unsigned int _score_v, bool _white_v, char type_v)
		: Piece(_position_v, _score_v, _white_v, type_v) {

		axes = *new std::vector<IndexPair>(8);
		//ROOK
		axes[0] = *new IndexPair(-1, 0);
		axes[1] = *new IndexPair(1, 0);
		axes[2] = *new IndexPair(0, -1);
		axes[3] = *new IndexPair(0, 1);
		//OFFICER
		axes[4] = *new IndexPair(-1, -1);
		axes[5] = *new IndexPair(-1, 1);
		axes[6] = *new IndexPair(1, 1);
		axes[7] = *new IndexPair(1, -1);
	}
}
