#include <iostream>
#include "evaluator.hpp"
#include "board.hpp"

using namespace std;

// https://chessprogramming.wikispaces.com/Piece-Square+Tables

int main()
{
	Board::init_boards();

	Evaluator::evaluate(Board::starting_position);	
	cout << endl << "White Pawns" << endl;
	Evaluator::evaluate(Board::pst_w_p); 
	cout << endl << "White Knights" << endl;
	Evaluator::evaluate(Board::pst_w_kn);
	cout << endl << "White Bishops" << endl;
	Evaluator::evaluate(Board::pst_w_b);
	cout << endl << "White Rooks" << endl;
	Evaluator::evaluate(Board::pst_w_r);
	cout << endl << "White Queen" << endl;
	Evaluator::evaluate(Board::pst_w_q);
	cout << endl << "White King middle" << endl;
	Evaluator::evaluate(Board::pst_w_k_mid);
	cout << endl << "White King end" << endl;
	Evaluator::evaluate(Board::pst_w_k_end);
	cout << endl << "Black Pawns" << endl;
	Evaluator::evaluate(Board::pst_b_p);	
	cout << endl << "Black Knights" << endl;
	Evaluator::evaluate(Board::pst_b_kn);
	cout << endl << "Black Bishops" << endl;
	Evaluator::evaluate(Board::pst_b_b);
	cout << endl << "Black Rooks" << endl;
	Evaluator::evaluate(Board::pst_b_r);
	cout << endl << "Black Queen" << endl;
	Evaluator::evaluate(Board::pst_b_q);
	cout << endl << "Black King middle" << endl;
	Evaluator::evaluate(Board::pst_b_k_mid);
	cout << endl << "Black King end" << endl;
	Evaluator::evaluate(Board::pst_b_k_end);


	return 0;
}
