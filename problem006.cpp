#include "stdafx.h"
#include <iostream>
#include <vector>
#include <string>

#include "pe.h"

#include <boost/range/algorithm.hpp>
#include <boost/range/irange.hpp>
#include <boost/range/numeric.hpp>

using namespace euler;

int main(int argc, char* argv[])
{
	std::vector<std::string> state = 
	{
		"Problem 5",
		"",
		"The sum of the squares of the first ten natural numbers is,",
		"",
		"1\u00B2 + 2\u00B2 + ... + 10\u00B2 = 385",
		"The square of the sum of the first ten natural numbers is,",
		"",
		"(1 + 2 + ... + 10)\u00B2 = 55\u00B2 = 3025",
		"Hence the difference between the sum of the squares of the first ten natural numbers and the square of the sum is 3025 \u2212 385 = 2640.",
		"",
		"Find the difference between the sum of the squares of the first one hundred natural numbers and the square of the sum.",
	};
	auto f = []() -> int
	{
		const auto nums = boost::irange(1, 101);
		
		return std::pow(boost::accumulate(nums, 0), 2) - 
			boost::accumulate(nums, 0, [](int lhs, int rhs){ return lhs + rhs * rhs; });
		
	};
	
	solve(f, state);
	
	return 0;
}
