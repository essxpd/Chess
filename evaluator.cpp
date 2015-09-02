#include "evaluator.hpp"

Evaluator::Evaluator()
{

}

int Evaluator::evaluate( vector<vector<int>> const& board )
{
	for(int y = 7; y >= 0; y--)
	{
		for(int x = 0; x < 8; x++)
			std::cout << std::setw(3) <<  board[x][y];
		std::cout << std::endl;
	}

	return 0;
}
