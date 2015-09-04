#include "board.hpp"

vector<vector<int>> Board::starting_position 
{
	{ W_R,  W_P, 0, 0, 0, 0, B_P, B_R  },
	{ W_KN, W_P, 0, 0, 0, 0, B_P, B_KN },
	{ W_B,  W_P, 0, 0, 0, 0, B_P, B_B  },
	{ W_Q,  W_P, 0, 0, 0, 0, B_P, B_Q  },
	{ W_K,  W_P, 0, 0, 0, 0, B_P, B_K  },
	{ W_B,  W_P, 0, 0, 0, 0, B_P, B_B  },
	{ W_KN, W_P, 0, 0, 0, 0, B_P, B_KN },
	{ W_R,  W_P, 0, 0, 0, 0, B_P, B_R  }
};

Board::Board() 
{
}

