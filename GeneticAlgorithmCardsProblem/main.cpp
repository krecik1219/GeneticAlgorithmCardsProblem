#include "CPGAlg.h"
#include <iostream>

using namespace std;

int main()
{
	CPGAlg c_pgalg(10, 37, 240);
	for(int i =0; i<100; ++i)
	{
		CCardBits c_current_best = c_pgalg.cRunIteration();
		cout << c_current_best << endl;
	}

	getchar(); getchar();

	return 0;
}