#include <iostream>
#include <string>
#include "FibLFSR.hpp"
using namespace std;


int main()
{
	FibLFSR first("1011011000110110");

	cout << first.getInitialSeed() << " " << first.generate(5) << endl;

	cout << endl;
	for (int i = 0; i < 10; i++)
	{
		cout << first.getInitialSeed() << " " << first.step() << endl;
	}

	cout << endl;

	FibLFSR second("0111011010110110");
	
	for (int i = 0; i < 10; i++)
	{
		cout << second.getInitialSeed() << " " << second.step() << endl;
	}

	return 0;
}

