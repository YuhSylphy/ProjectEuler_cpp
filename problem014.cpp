#define BOOST_RESULT_OF_USE_DECLTYPE

#include "stdafx.h"

#include <iostream>
#include <vector>
#include <string>

#include "pe.h"

#include <unordered_map>
#include <functional>

#include <boost/range/irange.hpp>
#include <boost/range/algorithm.hpp>
#include <boost/range/adaptor/transformed.hpp>
#include <boost/range/adaptor/indexed.hpp>
#include <boost/range/adaptor/memoized.hpp>

using namespace euler;

int main(int argc, char* argv[])
{
	using namespace boost::adaptors;
	// using namespace yuh::adaptors;

	std::vector<std::string> state = 
	{
		"Problem 14",
		"",
		"The following iterative sequence is defined for the set of positive integers:",
		"",
		"n → n/2 (n is even)",
		"n → 3n + 1 (n is odd)",
		"",
		"Using the rule above and starting with 13, we generate the following sequence:",
		"13 → 40 → 20 → 10 → 5 → 16 → 8 → 4 → 2 → 1",
		"",
		"It can be seen that this sequence (starting at 13 and finishing at 1) contains 10 terms. Although it has not been proved yet (Collatz Problem), it is thought that all starting numbers finish at 1.",
		"",
		"Which starting number, under one million, produces the longest chain?",
		"",
		"NOTE: Once the chain starts the terms are allowed to go above one million.",
	};
	
	auto f = []() -> int
	{
		std::function<uint32_t(uint32_t)> collatz = 
		[&collatz]( uint32_t n ) -> uint32_t
		{
			static std::unordered_map<uint32_t, uint32_t> buf{ {1U, 1U} };
			struct initializer{
				template<typename Map>
				initializer(Map& buf)
				{
					buf.rehash(4000037);
				}
			} static initr(buf);
			
			// 0にはならないので存在チェックになるはず
			// 一度呼び出したKeyは必ず埋まるので無駄にもならない
			if(buf[n] == 0) 
			{
				buf[n] = 1 + collatz(
					n % 2 == 0 
					? n / 2         // even
					: 3 * n + 1 );  // odd
			}
			return buf[n];
		};
		
		static const uint32_t tgt = 1000 * 1000;
		
		return boost::max_element(
			boost::irange(1U, tgt) | transformed(collatz) | indexed(1)
			).index();
	};
	
	solve(f, state);
	
	return 0;
}
