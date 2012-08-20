#include "stdafx.h"
#include <iostream>
#include <vector>
#include <string>

#include "pe.h"

#include <boost/range/algorithm.hpp>

#include <yuh/prime.h>

using namespace euler;

int main(int argc, char* argv[])
{
	std::vector<std::string> state = 
	{
		"Problem 3",
		"The prime factors of 13195 are 5, 7, 13 and 29.",
		"",
		"What is the largest prime factor of the number 600851475143 ?",
	};
	auto f = []() -> long long
	{
		const auto tgt = 600851475143;
		
		return *boost::max_element(yuh::prime_factor(tgt));
 	};

	solve(f, state);
	
	return 0;
}
