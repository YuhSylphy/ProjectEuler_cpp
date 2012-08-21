#include "stdafx.h"
#include <iostream>
#include <vector>
#include <string>

#include "pe.h"

#include <array>
#include <algorithm>
#include <boost/range/irange.hpp>
#include <boost/range/adaptor/reversed.hpp>
#include <yuh/math.hpp>

using namespace euler;

int main(int argc, char* argv[])
{
	std::vector<std::string> state = 
	{
		"Problem 9",
		"",
		"A Pythagorean triplet is a set of three natural numbers, a  b  c, for which,",
		"a\u00B2 + b\u00B2 = c\u00B2",
		"",
		"For example, 3\u00B2 + 4\u00B2 = 9 + 16 = 25 = 5\u00B2.",
		"",
		"There exists exactly one Pythagorean triplet for which a + b + c = 1000.",
		"Find the product abc.",
	};
	auto f = []() -> int
	{
		// 0 < a < b < c && a + b + c = 1000 を満たすように走査
		for( const auto c: boost::irange(334, 999))
		{
			for( const auto b: boost::irange((1000 - c) / 2 + 1, std::min(c, 1000 - c)))
			{
				const auto a = 1000 - b - c;
				// ピタゴラス数を見つけたら積を返す
				// 「exactly one」なので見つけた時点で返せば良い
				if ( yuh::is_Pythagorean(a, b, c) ) 
					return a * b * c;
			}

		}
		
		return 0;
	};
	solve(f, state);
	
	return 0;
}
