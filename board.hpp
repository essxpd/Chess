#include <iostream>
#include <vector>
#include <utility>

using namespace std;

enum Pieces { B_K = -6, B_Q, B_R, B_B, B_KN, B_P, E, W_P, W_KN, W_B, W_R, W_Q, W_K };

class Board
{
public:
	Board();	
	vector<pair<int,int>> getMoves(pair<int,int>);
	vector<pair<int,int>> getMoves(int,int);
	vector<vector<int>>& state();

	vector<int>& operator[](unsigned int i) { return board[i]; }
	
	//const vector<vector<int>>& operator[](unsigned int i) const {return board[i]; }

	//vector<vector<int>>& operator()(int x, int y) { return board[x][y]; }
	

	// Starting position of the board for convenience	
	static vector<vector<int>> starting_position;

private:
	void get_pawn_moves(char, int, int, vector<pair<int,int>>&);
	void get_knight_moves(char, int, int, vector<pair<int,int>>&);
	void get_bishop_moves(char, int, int, vector<pair<int,int>>&);
	void get_rook_moves(char, int, int, vector<pair<int,int>>&);

	vector<vector<int>> board;

};
