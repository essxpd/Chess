#include <iostream>
#include <time.h>
#include <sys/time.h>
#include "evaluator.hpp"


using namespace std;
//using namespace std::chrono;
// https://chessprogramming.wikispaces.com/Piece-Square+Tables

int main()
{
	Evaluator::init_pst();
	Board board;
	
	cout << "Score: " << Evaluator::evaluate(board.state()) << endl << endl;	
	
	cout << board.getMoves(6,4).size() << endl;

	return 0;
}
