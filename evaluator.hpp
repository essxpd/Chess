#include <iostream>
#include <iomanip>
#include <vector>

using namespace std;

class Evaluator
{
public:
	Evaluator();	

	static int evaluate( vector<vector<int>> const& board );
};
