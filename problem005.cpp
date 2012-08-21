#include "stdafx.h"
#include <iostream>
#include <vector>
#include <string>

#include "pe.h"

#include <set>
#include <iterator>
#include <functional>

#include <boost/range/algorithm.hpp>
#include <boost/range/irange.hpp>
#include <boost/range/numeric.hpp>

#include <pstade/oven/io.hpp>

#include <yuh/math.hpp>
#include <yuh/prime.h>

using namespace euler;

int main(int argc, char* argv[])
{
	std::vector<std::string> state = 
	{
		"Problem 5",
		"",
		"2520 is the smallest number that can be divided by each of the numbers from 1 to 10 without any remainder.",
		"",
		"What is the smallest positive number that is evenly divisible by all of the numbers from 1 to 20?",
	};
	auto f = []() -> int
	{
		typedef std::multiset<long long> set_type;
		static const auto tgt = 20;

		std::vector<set_type> factors;
		factors.reserve(tgt);
		
		// [1, 20]をそれぞれ素因数分解してfactorsに
		boost::transform(
			boost::irange(1, tgt + 1),
			std::back_inserter(factors),
			[](int x) -> set_type {
				return yuh::prime_factor(x);
			});

		// 各素因数のunionをとった後全要素の積を取って返す
		return boost::accumulate(
			boost::accumulate(
				factors,
				set_type(),
				[](const set_type& lhs, const set_type& rhs) -> set_type {
					set_type ret;
					// lhs(これまでのunion)とrhs(今見ているset)のunion
					boost::set_union(lhs, rhs, std::inserter(ret, std::begin(ret)));
					return ret;
				}),
			1, 
			std::multiplies<long long>());
 	};

	solve(f, state);
	
	return 0;
}
