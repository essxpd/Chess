#include <iostream>
#include <vector>
#include <utility>

using namespace std;

enum Pieces { B_K = -6, B_Q, B_R, B_B, B_KN, B_P, E, W_P, W_KN, W_B, W_R, W_Q, W_K };

class Board
{
public:
	Board();	
	//vector<pair<int,int>> getMoves(pair<int,int>&);

	// Starting position of the board for convenience	
	static vector<vector<int>> starting_position;
};
