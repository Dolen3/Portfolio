#include <string>
#include <iostream>
#include <math.h>
#include "FibLFSR.hpp"



FibLFSR::FibLFSR(string seed)
{
	initialSeed = seed;
}


int FibLFSR::step()
{
	//cout << "INITIAL STRING: " << initialSeed << endl;

	int newbit;
	int num1;
	int num2;
	if (initialSeed[0] == '1')
	{
		num1 = 1;
	}
	else
	{
		num1 = 0;
	}
	if (initialSeed[2] == '1')
	{
		num2 = 1;
	}
	else
	{
		num2 = 0;
	}
	newbit = num1 ^ num2;
	if (initialSeed[3] == '1')
	{
		num2 = 1;
	}
	else
	{
		num2 = 0;
	}
	newbit = newbit ^ num2;
	if (initialSeed[5] == '1')
	{
		num2 = 1;
	}
	else
	{
		num2 = 0;
	}
	newbit = newbit ^ num2;


	string temp = "";
	for (int i = 1; i < 16; i++)
	{
		temp += initialSeed[i];
	}


	char add;
	if (newbit == 1)
	{
		add = '1';
	}
	else
	{
		add = '0';
	}

	temp += add;
	initialSeed = temp;
	if (add == '1')
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

std::string FibLFSR::getInitialSeed() const
{
	return initialSeed;
}
void FibLFSR::setInitialSeed(std::string nString) 
{
	initialSeed = nString;
}

int FibLFSR::generate(int k)
{
	int result = 0;
	for (int i = k - 1; i >= 0; i--)
	{
		result += (pow(2, i) * step());
	}
	return result;
}

ostream& operator<< (std::ostream& out, const FibLFSR& lfsr)
{
	out << lfsr.initialSeed;
	return out;
}