#include "stdafx.h"
#include <iostream>
#include "pe.h"

#include <boost/range/irange.hpp>

using namespace euler;

int main(int argc, char* argv[])
{
	std::vector<std::string> state = 
	{
		"Problem 1",
		"",
		"If we list all the natural numbers below 10 that are multiples of 3 or 5, we get 3, 5, 6 and 9. The sum of these multiples is 23.",
		"",
		"Find the sum of all the multiples of 3 or 5 below 1000.",
	};
	auto f = []() -> int
	{
		const auto below = 1000;
		auto sum = 0;

		for( auto i: boost::irange(0, below) )
		{
			if(!( i % 3 && i % 5))
			{
				sum += i;
			}
		}

		return sum;
	};

	solve(f, state);
	
	return 0;
}
