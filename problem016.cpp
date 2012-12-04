#define BOOST_RESULT_OF_USE_DECLTYPE

#include "stdafx.h"

#include <iostream>
#include <vector>
#include <string>

#include "pe.h"

#include <boost/range/irange.hpp>
#include <boost/range/numeric.hpp>


using namespace euler;

int main(int argc, char* argv[])
{

	std::vector<std::string> state = 
	{
		"Problem 16",
		"",
		"2^15 = 32768 and the sum of its digits is 3 + 2 + 7 + 6 + 8 = 26.",
		"",
		"What is the sum of the digits of the number 2^1000?",
	};

	auto f = []() -> int
	{
		int const exp = 1000;
		int const base = 2;
		int const dgt = 10;

		std::vector<uint8_t> digits = {1};
		digits.reserve(310);

		for( auto i: boost::irange(0, exp) )
		{
			// 繰り上がり
			int C = 0;
			for( auto& d: digits )
			{
				// 一ケタ分に掛けて繰り上がりと分離
				d = d * base + C;
				C = d / dgt;
				d %= dgt;
			}
			while (C > 0)
			{   
				// 繰り上がりが残ってたら桁を増やす
				digits.push_back(C % dgt);
				C /= dgt;
			}
		}

		// あとは総和を返すだけ
		return boost::accumulate(digits, 0);
	};
	
	solve(f, state);
	
	return 0;
}
