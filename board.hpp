#include <iostream>
#include <vector>

using namespace std;

enum Pieces { B_K = -6, B_Q, B_R, B_B, B_KN, B_P, E, W_P, W_KN, W_B, W_R, W_Q, W_K };
const int p = 100;
const int kn = 320;
const int b = 330;
const int r = 500;
const int q = 900;
const int k = 20000;

class Board
{
public:
	Board();	

	static void init_boards();

	// Starting position of the board for convenience	
	static vector<vector<int>> starting_position;

	// Piece-Square tables for positional scores for specific pieces
	static vector<vector<int>> pst_w_p;
	static vector<vector<int>> pst_w_kn;
	static vector<vector<int>> pst_w_b;
	static vector<vector<int>> pst_w_r;
	static vector<vector<int>> pst_w_q;
	static vector<vector<int>> pst_w_k_mid;
	static vector<vector<int>> pst_w_k_end;
	static vector<vector<int>> pst_b_p;
	static vector<vector<int>> pst_b_kn;
	static vector<vector<int>> pst_b_b;
	static vector<vector<int>> pst_b_r;
	static vector<vector<int>> pst_b_q;
	static vector<vector<int>> pst_b_k_mid;
	static vector<vector<int>> pst_b_k_end;

private:
	static void flip(vector<vector<int>>&);
};
