#include "CPGAlg.h"
#include <iostream>

using namespace std;

static const int i_PROBLEM_SIZE = 18;

int main()
{
	CCardBits c_rnd_cards(i_PROBLEM_SIZE);
	int i_sum = c_rnd_cards.iTotalSum();
	int i_prod = c_rnd_cards.iTotalProduct();

	CPGAlg c_pgalg(i_PROBLEM_SIZE, i_sum, i_prod);
	cout << "Problem to optimize:" << endl << c_rnd_cards << endl;
	cout << "Press any key to start" << endl;
	getchar();
	for(int i =0; i<1000; ++i)
	{
		CCardBits c_current_best = c_pgalg.cRunIteration();
		cout << (i + 1) << ". " << c_current_best << endl;
	}

	cout << endl << "Finished" << endl;
	getchar(); getchar();

	return 0;
}