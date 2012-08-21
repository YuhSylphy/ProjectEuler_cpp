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
		"Problem 10",
		"",
		"The sum of the primes below 10 is 2 + 3 + 5 + 7 = 17.",
		"",
		"Find the sum of all the primes below two million.",
	};
	auto f = []() -> long long //32bitじゃ足りない
	{
		static const auto below = 2000000;
		
		
		// 先に篩っておく
		yuh::prime_sift(below);
		const auto& p = yuh::get_prime_list();
		
		// 閾値を越えたところをendとして走査すれば良いはず
		const auto ret = std::accumulate(
			std::begin(p),
			boost::find_if( // 2000000までの素数は全て追加されている 
				p,          // このコードでは関係ないはずだけど，siftは「そこまでしか無い」ことを保証しないので一応find
				[&](long long x) -> bool 
				{   
					return x > below; 
				}),
			0LL);
		return ret;
	};
	solve(f, state);
	
	return 0;
}
