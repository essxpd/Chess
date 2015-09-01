#include <iostream>
#include "evaluator.hpp"

using namespace std;

const int 

int main()
{
	board[8][8] = {
		{ W_R, W_KN, W_B, W_Q, W_K, W_B, W_KN, W_R },
		{ W_P, W_P,  W_P, W_P, W_P, W_P, W_P,  W_P },
		{ 0,   0,    0,   0,   0,   0,   0,    0   },
		{ 0,   0,    0,   0,   0,   0,   0,    0   },
		{ 0,   0,    0,   0,   0,   0,   0,    0   },
		{ 0,   0,    0,   0,   0,   0,   0,    0   },
		{ B_P, B_P,  B_P, B_P, B_P, B_P, B_P,  B_P },
		{ B_R, B_KN, B_B, B_Q, B_K, B_B, B_KN, B_R }
	};

	cout << Evaluator::evaluate() << endl;	
	return 0;
}
