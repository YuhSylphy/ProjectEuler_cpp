#include "stdafx.h"
#include <iostream>
#include <vector>
#include <string>

#include "pe.h"

#include <cmath>

#include <boost/range/algorithm.hpp>
#include <boost/range/irange.hpp>
#include <boost/range/adaptor/reversed.hpp>
#include <boost/range/adaptor/filtered.hpp>
#include <boost/range/adaptor/regular_extension/filtered.hpp>

#include <yuh/math.hpp>

using namespace euler;

int main(int argc, char* argv[])
{
	std::vector<std::string> state = 
	{
		"Problem 4",
		"",
		"A palindromic number reads the same both ways. The largest palindrome made from the product of two 2-digit numbers is 9009 = 91 × 99.",
		"",
		"Find the largest palindrome made from the product of two 3-digit numbers.",
	};
	auto f = []() -> int
	{
		using namespace boost::adaptors;

		return *boost::find_if(
			boost::irange(100 * 100, 999 * 999) //範囲内を
			| reversed // 上から走査
			| filtered(yuh::is_palindromic<int>) // 回文数
			,
			[](int x) -> bool{
				for( auto f: boost::irange( 100, static_cast<int>(std::floor(std::sqrt(x))) ) | 
						 boost::adaptors::reversed )
				{   // 可能性がある数を大きい方から
					
					//これ以上小さくしても相手が3桁にならない
					if( x  >= 1000 * f ) break; 
					
					if( x % f == 0)
					{
						if( 100 <= x / f ) // 3桁
							return true;
					}
				}
				return false;
			});
 	};

	solve(f, state);
	
	return 0;
}
