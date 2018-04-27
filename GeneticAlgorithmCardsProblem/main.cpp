#include "CPGAlg.h"
#include <iostream>

using namespace std;

int main()
{
	CPGAlg c_pgalg(14, 39, 39916800);
	for(int i =0; i<1000; ++i)
	{
		CCardBits c_current_best = c_pgalg.cRunIteration();
		cout << c_current_best << endl;
	}

	getchar(); getchar();

	return 0;
}