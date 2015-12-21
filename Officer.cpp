//
//  Officer.cpp
//  BCAI
//
//  Created by Max Botviniev on 20.10.15.
//  Copyright (c) 2015 Max Botviniev. All rights reserved.
//

#include "Officer.h"

namespace BCAI {

	Officer::Officer(Position _position_v, unsigned int _score_v, bool _white_v, char type_v) 
		: Piece(_position_v, _score_v, _white_v, type_v) {
	
		axes = *new std::vector<IndexPair>(4);
		axes[0] = IndexPair(-1, -1);
		axes[1] = IndexPair(-1, 1);
		axes[2] = IndexPair(1, 1);
		axes[3] = IndexPair(1, -1);
	}
}
