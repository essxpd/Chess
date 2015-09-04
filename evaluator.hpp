#include <iostream>
#include <iomanip>
#include <vector>
#include <utility>
#include "board.hpp"

using namespace std;

class Evaluator
{
public:
	Evaluator();	
	static void init_pst();
	static int evaluate( vector<vector<int>> const& board );

private:
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

	// Piece value
	const static int p_val;
	const static int kn_val;
	const static int b_val;
	const static int r_val;
	const static int q_val;
	const static int k_val;
	
	// Flips whites pst for black
	static void flip(vector<vector<int>>&);
};
