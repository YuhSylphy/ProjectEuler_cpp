#define BOOST_RESULT_OF_USE_DECLTYPE

#include "stdafx.h"

#include <iostream>
#include <vector>
#include <string>

#include "pe.h"

#include <boost/range/irange.hpp>
#include <boost/range/numeric.hpp>
#include <boost/range/adaptor/transformed.hpp>

#include <functional>

using namespace euler;

int main(int argc, char* argv[])
{
	using namespace boost::adaptors;

	std::vector<std::string> state = 
	{
		"Problem 17",
		"",
		"If the numbers 1 to 5 are written out in words: one, two, three, four, five, "
		"then there are 3 + 3 + 5 + 4 + 4 = 19 letters used in total."
		""
		"If all the numbers from 1 to 1000 (one thousand) inclusive "
		"were written out in words, how many letters would be used?"
		""
		""
		"NOTE: Do not count spaces or hyphens. "
		"For example, 342 (three hundred and forty-two) contains 23 letters "
		"and 115 (one hundred and fifteen) contains 20 letters. "
		"The use of \"and\" when writing out numbers is in compliance with British usage. "
	};

	auto f = []() -> int
	{
		std::function<int(int)> const letters = [&](int n) -> int
		{
			// 一桁～teen,
			switch(n)
			{
			case   0: return 0;
			case   1: return 3; // one
			case   2: return 3; // two
			case   3: return 5; // three
			case   4: return 4; // four
			case   5: return 4; // five
			case   6: return 3; // six
			case   7: return 5; // seven
			case   8: return 5; // eight
			case   9: return 4; // nine
			case  10: return 3; // ten
			case  11: return 6; // eleven
			case  12: return 6; // twelve
			case  13: return 8; // thirteen
			case  14: return 8; // fourteen
			case  15: return 7; // fifteen
			case  16: return 7; // sixteen
			case  17: return 9; // seventeen
			case  18: return 8; // eighteen
			case  19: return 8; // nineteen
			case  20: return 6; // twenty
			case  30: return 6; // thirty
			case  40: return 5; // forty
			case  50: return 5; // fifty
			case  60: return 5; // sixty
			case  70: return 7; // seventy
			case  80: return 6; // eighty
			case  90: return 6; // ninety
			case 100: return 10; // one hundred
			case 1000: return 11; // one thousand
			default:
			if(n > 100)
			{
				return letters(n / 100) 
					+ 7 // hundred
					+ (n % 100 > 0 ? 3 + letters(n % 100) : 0);
			}
			else
			{
				// std::cout << ", " << letters(n - (n % 10)) << ", " << letters(n % 10) << std::endl;
				return letters(n - (n % 10)) + letters(n % 10);
			}
			throw;
			}
			return 0x7FFFFFFF;
		};

		return boost::accumulate(
			boost::irange(1, 1000+ 1) | transformed(letters),
			0);
	};
	
	solve(f, state);
	
	return 0;
}
