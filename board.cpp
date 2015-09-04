#include "board.hpp"

vector<vector<int>> Board::starting_position 
{
	{ W_R,  W_P, 0, 0, 0, 0, B_P, B_R  },
	{ W_KN, W_P, 0, W_B, 0, 0, B_P, B_KN },
	{ W_B,  W_P, 0, 0, 0, 0, B_P, B_B  },
	{ W_Q,  0, 0, 0, 0, 0, B_P, B_Q  },
	{ W_K,  W_P, 0, 0, 0, 0, B_P, B_K  },
	{ W_B,  W_P, 0, 0, 0, 0, B_P, B_B  },
	{ W_KN, W_P, 0, 0, B_B, 0, B_P, B_KN },
	{ W_R,  W_P, 0, 0, 0, 0, B_P, B_R  }
};

Board::Board() 
{
	board = vector<vector<int>>(starting_position.begin(), starting_position.end());
}

vector<pair<int,int>> Board::getMoves(int x,int y)
{
	return getMoves(make_pair(x,y));
}

vector<pair<int,int>> Board::getMoves(pair<int,int> pos)
{
	vector<pair<int,int>> moves;

	switch(board[pos.first][pos.second]) 
	{
	case W_P:
		get_pawn_moves('w', pos.first, pos.second, moves);
		break;
	case B_P:
		get_pawn_moves('b', pos.first, pos.second, moves);
		break;
	case W_KN:
		get_knight_moves('w', pos.first, pos.second, moves);
		break;
	case B_KN:
		get_knight_moves('b', pos.first, pos.second, moves);
		break;
	case W_B:
		get_bishop_moves('w', pos.first, pos.second, moves);
		break;
	case B_B:
		get_bishop_moves('b', pos.first, pos.second, moves);
		break;
	case W_R:
		get_rook_moves('w', pos.first, pos.second, moves);
		break;
	case B_R:
		get_rook_moves('b', pos.first, pos.second, moves);
	}

	return moves;
}

vector<vector<int>>& Board::state()
{
	return board;
}

void Board::get_pawn_moves(char c, int x, int y, vector<pair<int,int>>& moves)
{
	if(c == 'w')
	{
		if(y < 7 && board[x][y+1] == E)
		{
			moves.push_back(make_pair(x,y+1));
			if(y == 1 && board[x][3] == E)
				moves.push_back(make_pair(x,3));
		}
		
		if(x < 7 && y < 7 && board[x+1][y+1] < 0)
			moves.push_back(make_pair(x+1,y+1));
		if(x > 0 && y < 7 && board[x-1][y+1] < 0)
			moves.push_back(make_pair(x-1,y+1));
		
	}
	else
	{
		if(y > 0 && board[x][y-1] == E)
		{
			moves.push_back(make_pair(x,y-1));
			if(y == 6 && board[x][4] == E)
				moves.push_back(make_pair(x,4));
		}

		if(x < 7 && y > 0 && board[x+1][y-1] > 0)
			moves.push_back(make_pair(x+1,y-1));
		if(x > 0 && y > 0 && board[x-1][y-1] > 0)
			moves.push_back(make_pair(x-1,y-1));
	}
}

void Board::get_knight_moves(char c, int x, int y, vector<pair<int,int>> &moves)
{
	if(c == 'w')
	{
		// Move 1 right, 2 up
		if( x < 7 && y < 6 && board[x+1][y+2] <= 0)
			moves.push_back(make_pair(x+1, y+2));
		// Move 1 right, 2 down
		if( x < 7 && y > 1 && board[x+1][y-2] <= 0)
			moves.push_back(make_pair(x+1, y-2));
		// Move 1 left, 2 up
		if( x > 0 && y < 6 && board[x-1][y+2] <= 0)
			moves.push_back(make_pair(x-1, y+2));
		// Move 1 left, 2 down
		if( x > 0 && y > 1 && board[x-1][y-2] <= 0)
			moves.push_back(make_pair(x-1, y-2));
		// Move 2 right, 1 up
		if( x < 6 && y < 7 && board[x+2][y+1] <= 0)
			moves.push_back(make_pair(x+2, y+1));
		// Move 2 right, 1 down
		if( x < 6 && y > 0 && board[x+2][y-1] <= 0)
			moves.push_back(make_pair(x+2, y-1));
		// Move 2 left, 1 up
		if( x > 1 && y < 7 && board[x-2][y+1] <= 0)
			moves.push_back(make_pair(x-2, y+1));
		// Move 2 left, 1 down
		if( x > 1 && y > 0 && board[x-2][y-1] <= 0)
			moves.push_back(make_pair(x-2, y-1));
	}
	else
	{
		// Move 1 right, 2 up
		if( x < 7 && y < 6 && board[x+1][y+2] >= 0)
			moves.push_back(make_pair(x+1, y+2));
		// Move 1 right, 2 down
		if( x < 7 && y > 1 && board[x+1][y-2] >= 0)
			moves.push_back(make_pair(x+1, y-2));
		// Move 1 left, 2 up
		if( x > 0 && y < 6 && board[x-1][y+2] >= 0)
			moves.push_back(make_pair(x-1, y+2));
		// Move 1 left, 2 down
		if( x > 0 && y > 1 && board[x-1][y-2] >= 0)
			moves.push_back(make_pair(x-1, y-2));
		// Move 2 right, 1 up
		if( x < 6 && y < 7 && board[x+2][y+1] >= 0)
			moves.push_back(make_pair(x+2, y+1));
		// Move 2 right, 1 down
		if( x < 6 && y > 0 && board[x+2][y-1] >= 0)
			moves.push_back(make_pair(x+2, y-1));
		// Move 2 left, 1 up
		if( x > 1 && y < 7 && board[x-2][y+1] >= 0)
			moves.push_back(make_pair(x-2, y+1));
		// Move 2 left, 1 down
		if( x > 1 && y > 0 && board[x-2][y-1] >= 0)
			moves.push_back(make_pair(x-2, y-1));

	}
}

void Board::get_bishop_moves(char c, int x, int y, vector<pair<int,int>>& moves)
{
	if(c == 'w')
	{
		// Up-Right
		for(int i = 1; x + i < 8 && y + i < 8; i++)
		{
			if(board[x+i][y+i] <= 0)
				moves.push_back(make_pair(x+i, y+i));
			if(board[x+i][y+i] != 0)
				break;
		}
		// Down-Right
		for(int i = 1; x + i < 8 && y - i >= 0; i++)
		{
			if(board[x+i][y-i] <= 0)
				moves.push_back(make_pair(x+i, y-i));
			if(board[x+i][y-i] != 0)
				break;
		}
		// Down-Left
		for(int i = 1; x - i >= 0 && y - i >= 0; i++)
		{
			if(board[x-i][y-i] <= 0)
				moves.push_back(make_pair(x-i, y-i));
			if(board[x-i][y-i] != 0)
				break;
		}
		// Up-Left
		for(int i = 1; x - i >= 0 && y + i < 8; i++)
		{
			if(board[x-i][y+i] <= 0)
				moves.push_back(make_pair(x-i, y+i));
			if(board[x-i][y+i] != 0)
				break;
		}
	}
	else
	{
		// Up-Right
		for(int i = 1; x + i < 8 && y + i < 8; i++)
		{
			if(board[x+i][y+i] >= 0)
				moves.push_back(make_pair(x+i, y+i));
			if(board[x+i][y+i] != 0)
				break;
		}
		// Down-Right
		for(int i = 1; x + i < 8 && y - i >= 0; i++)
		{
			if(board[x+i][y-i] >= 0)
				moves.push_back(make_pair(x+i, y-i));
			if(board[x+i][y-i] != 0)
				break;
		}
		// Down-Left
		for(int i = 1; x - i >= 0 && y - i >= 0; i++)
		{
			if(board[x-i][y-i] >= 0)
				moves.push_back(make_pair(x-i, y-i));
			if(board[x-i][y-i] != 0)
				break;
		}
		// Up-Left
		for(int i = 1; x - i >= 0 && y + i < 8; i++)
		{
			if(board[x-i][y+i] >= 0)
				moves.push_back(make_pair(x-i, y+i));
			if(board[x-i][y+i] != 0)
				break;
		}
	}
}

void Board::get_rook_moves(char c, int x, int y, vector<pair<int,int>>& moves)
{

}

