#include "evaluator.hpp"

const int Evaluator::p_val = 100;
const int Evaluator::kn_val = 320;
const int Evaluator::b_val = 330;
const int Evaluator::r_val = 500;
const int Evaluator::q_val = 900;
const int Evaluator::k_val = 20000;

Evaluator::Evaluator()
{

}

int Evaluator::evaluate( vector<vector<int>> const& board )
{
	int b_score = 0;
	int w_score = 0;

	int num_w_p = 0;
	int num_b_p = 0;
	int num_w_kn = 0;
	int num_b_kn = 0;
	int num_w_b = 0;
	int num_b_b = 0;
	int num_w_r = 0;
	int num_b_r = 0;
	int num_w_q = 0;
	int num_b_q = 0;

	pair<int,int> w_k_pos;
	pair<int,int> b_k_pos;
	
	cout << endl;

	for(int y = 7; y >= 0; y--)
	{
		for(int x = 0; x < 8; x++)
		{
			std::cout << std::setw(3) <<  board[x][y];
		
			// Piece value plus piece position value
			switch(board[x][y])
			{
			case W_P:
				w_score += p_val + pst_w_p[x][y];
				num_w_p++;
				break;
			case B_P:
				b_score += p_val + pst_b_p[x][y];
				num_b_p++;
				break;
			case W_KN:
				w_score += kn_val + pst_w_kn[x][y];
				num_w_kn++;
				break;
			case B_KN:
				b_score += kn_val + pst_b_kn[x][y];
				num_b_kn++;
				break;
			case W_B:
				w_score += b_val + pst_w_b[x][y];
				num_w_b++;
				break;
			case B_B:
				b_score += b_val + pst_b_b[x][y];
				num_b_b++;
				break;
			case W_R:
				w_score += r_val + pst_w_r[x][y];
				num_w_r++;
				break;
			case B_R:
				b_score += r_val + pst_b_r[x][y];
				num_b_r++;
				break;
			case W_Q:
				w_score += q_val + pst_w_q[x][y];
				num_w_q++;
				break;
			case B_Q:
				b_score += q_val + pst_b_q[x][y];
				num_b_q++;
				break;
			case W_K:
				w_k_pos = make_pair(x,y);
				break;
			case B_K:
				b_k_pos = make_pair(x,y);
				break;
			}			
		}

		std::cout << std::endl;
	}

	// Determine what stage of the game it is for the king
	if( (num_w_q == 0 && num_b_q == 0) 
	   || (num_w_q == 1 && (num_w_kn + num_w_b + num_w_r < 2))
	   || (num_b_q == 1 && (num_b_kn + num_b_b + num_b_r < 2)) )
	{
		w_score += pst_w_k_end[w_k_pos.first][w_k_pos.second];
		b_score += pst_b_k_end[b_k_pos.first][b_k_pos.second];
	}
	else
	{
		w_score += pst_w_k_mid[w_k_pos.first][w_k_pos.second];
		b_score += pst_b_k_mid[b_k_pos.first][b_k_pos.second];
	}

	cout << endl;

	cout << "White score: " << w_score << endl;
	cout << "Black score: " << b_score << endl;

	return w_score - b_score;
}

void Evaluator::flip(vector<vector<int>> &table)
{
	for(int x = 0; x < 8; x++)
	{
		for(int y = 0; y < 4; y++)
		{
			swap(table[x][y], table[x][7-y]);
		}
	}
}

void Evaluator::init_pst()
{
	flip(pst_b_p);
	flip(pst_b_kn);
	flip(pst_b_b);
	flip(pst_b_r);
	flip(pst_b_q);
	flip(pst_b_k_mid);
	flip(pst_b_k_end);
}


// Piece square tables
vector<vector<int>> Evaluator::pst_w_p 
{
	{ 0,   5,  5,  0,  5, 10, 50, 0 },
	{ 0,  10, -5,  0,  5, 10, 50, 0 },
	{ 0,  10,-10,  0, 10, 20, 50, 0 },
	{ 0, -20,  0, 20, 25, 30, 50, 0 },
	{ 0, -20,  0, 20, 25, 30, 50, 0 },
	{ 0,  10, -5,  0,  5, 10, 50, 0 },
	{ 0,  10, -5,  0,  5, 10, 50, 0 },
	{ 0,   5,  5,  0,  5, 10, 50, 0 }
};

vector<vector<int>> Evaluator::pst_w_kn
{
	{ -50, -40, -30, -30, -30, -30, -40, -50 },
	{ -40, -20, 5, 0,  5, 0, -20, -40 },
	{ -30, 0, 10, 15, 15, 10, 0, -30 },
	{ -30, 5, 15, 20, 20, 15, 5, -30 },
	{ -30, 5, 15, 20, 20, 15, 5, -30 },
	{ -30, 0, 10, 15, 15, 10, 0, -30 },
	{ -40, -20, 5, 0,  5, 0, -20, -40 },
	{ -50, -40, -30, -30, -30, -30, -40, -50 }
};

vector<vector<int>> Evaluator::pst_w_b
{
	{ -20, -10, -10, -10, -10, -10, -10, -20 },
	{ -10, 5, 10, 0, 5, 0, 0, -10 },
	{ -10, 0, 10, 10, 5, 5, 0, -10 },
	{ -10, 0, 10, 10, 10, 10, 0, -10 },
	{ -10, 0, 10, 10, 10, 10, 0, -10 },
	{ -10, 0, 10, 10, 5, 5, 0, -10 },
	{ -10, 5, 10, 0, 5, 0, 0, -10 },
	{ -20, -10, -10, -10, -10, -10, -10, -20 }
};

vector<vector<int>> Evaluator::pst_w_r
{
{ 0, -5, -5, -5, -5, -5, 5, 0 },
	{ 0, 0, 0, 0, 0, 0, 10, 0 },
	{ 0, 0, 0, 0, 0, 0, 10, 0 },
	{ 5, 0, 0, 0, 0, 0, 10, 0 },
	{ 5, 0, 0, 0, 0, 0, 10, 0 },
	{ 0, 0, 0, 0, 0, 0, 10, 0 },
	{ 0, 0, 0, 0, 0, 0, 10, 0 },
	{ 0, -5, -5, -5, -5, -5, 5, 0 }
};

vector<vector<int>> Evaluator::pst_w_q
{
	{ -20, -10, -10, 0, -5, -10, -10, -20 },
	{ -10, 0, 5, 0, 0, 0, 0, -10 },
	{ -10, 5, 5, 5, 5, 5, 0, -10 },
	{ -5, 0, 5, 5, 5, 5, 0, -5 },
	{ -5, 0, 5, 5, 5, 5, 0, -5 },
	{ -10, 0, 5, 5, 5, 5, 0, -10 },
	{ -10, 0, 0, 0, 0, 0, 0, -10 },
	{ -20, -10, -10, -5, -5, -10, -10, -20 }
};

vector<vector<int>> Evaluator::pst_w_k_mid
{
	{ 20, 20, -10, -20, -30, -30, -30, -30 },
	{ 30, 20, -20, -30, -40, -40, -40, -40 },
	{ 10, 0, -20, -30, -40, -40, -40, -40 },
	{ 0, 0, -20, -40, -50, -50, -50, -50 },
	{ 0, 0, -20, -40, -50, -50, -50, -50 },
	{ 10, 0, -20, -30, -40, -40, -40, -40 },
	{ 30, 20, -20, -30, -40, -40, -40, -40 },
	{ 20, 20, -10, -20, -30, -30, -30, -30 }
};

vector<vector<int>> Evaluator::pst_w_k_end
{
	{ -50, -30, -30, -30, -30, -30, -30, -50 },
	{ -30, -30, -10, -10, -10, -10, -20, -40 },
	{ -30, 0, 20, 30, 30, 20, -10, -30 },
	{ -30, 0, 30, 40, 40, 30, 0, -20 },
	{ -30, 0, 30, 40, 40, 30, 0, -20 },
	{ -30, 0, 20, 30, 30, 20, -10, -30 },
	{ -30, -30, -10, -10, -10, -10, -20, -40 },
	{ -50, -30, -30, -30, -30, -30, -30, -50 }
};

vector<vector<int>> Evaluator::pst_b_p(pst_w_p.begin(), pst_w_p.end());
vector<vector<int>> Evaluator::pst_b_kn(pst_w_kn.begin(), pst_w_kn.end());	
vector<vector<int>> Evaluator::pst_b_b(pst_w_b.begin(), pst_w_b.end());
vector<vector<int>> Evaluator::pst_b_r(pst_w_r.begin(), pst_w_r.end());	
vector<vector<int>> Evaluator::pst_b_q(pst_w_q.begin(), pst_w_q.end());	
vector<vector<int>> Evaluator::pst_b_k_mid(pst_w_k_mid.begin(), pst_w_k_mid.end());	
vector<vector<int>> Evaluator::pst_b_k_end(pst_w_k_end.begin(), pst_w_k_end.end());
