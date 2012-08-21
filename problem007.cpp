#include "stdafx.h"
#include <iostream>
#include <vector>
#include <string>

#include "pe.h"

#include <yuh/prime.h>

using namespace euler;

int main(int argc, char* argv[])
{
	std::vector<std::string> state = 
	{
		"Problem 7",
		"",
		"By listing the first six prime numbers: 2, 3, 5, 7, 11, and 13, we can see that the 6th prime is 13.",
		"",
		"What is the 10 001st prime number?",
	};
	auto f = []() -> int
	{
		static const auto tgt = 10001;
		return *yuh::prime(tgt).begin();
	};
	
	solve(f, state);
	
	return 0;
}
