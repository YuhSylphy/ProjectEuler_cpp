#define BOOST_RESULT_OF_USE_DECLTYPE

#include "stdafx.h"

#include <iostream>
#include <vector>
#include <string>

#include "pe.h"

#include <array>
// #include <unordered_map>
// #include <functional>

#include <boost/range/irange.hpp>
#include <boost/range/algorithm.hpp>
// #include <boost/range/adaptor/transformed.hpp>
// #include <boost/range/adaptor/indexed.hpp>
// #include <boost/range/adaptor/memoized.hpp>

using namespace euler;

int main(int argc, char* argv[])
{
	// using namespace boost::adaptors;
	// using namespace yuh::adaptors;

	std::vector<std::string> state = 
	{
		"Problem 15",
		"",
		"Starting in the top left corner of a 22 grid, there are 6 routes (without backtracking) to the bottom right corner.",
		"",
		"How many routes are there through a 2020 grid?",
	};
	
	auto f = []() -> uint64_t
	{
		int const grid = 20;
		std::array<std::array<uint64_t, grid+1>, grid+1> nodes;
		
		nodes[0][0] = 1;
		for( auto i: boost::irange(1, grid+1) )
		{
			nodes[0][i] = 1;
			nodes[i][0] = 1;
		} 
		for( auto i: boost::irange(1, grid+1) )
		for( auto j: boost::irange(1, grid+1) )
		{
			nodes[i][j] = nodes[i-1][j] + nodes[i][j-1];
		}
		
		return nodes[grid][grid];
	};
	
	solve(f, state);
	
	return 0;
}
