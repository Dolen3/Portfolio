#pragma once
#include <iostream>
#include <string>

using namespace std;

class FibLFSR {
public:


	FibLFSR(std::string seed);

	int step();

	std::string getInitialSeed() const;
	void setInitialSeed(std::string nString);

	int generate(int k);
	
	friend std::ostream& operator<< (std::ostream& out, const FibLFSR& lfsr);

protected:
	std::string initialSeed = "";
	int output;
};




