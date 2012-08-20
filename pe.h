#pragma once
#include <iostream>
#include <chrono>
#include <boost/format.hpp>

namespace euler
{
	template <typename Func, typename Range>
	void solve(Func solver, const Range& state)
	{
		std::cout << "Project Euler" << std::endl;
		for( const auto& line: state)
		{   //問題文
			std::cout << line << std::endl;
		}
		std::cout << std::endl;

		//測定
		auto const begin = std::chrono::system_clock::now();
		const auto ans = solver();
		auto const end = std::chrono::system_clock::now();
	   
		auto const time = std::chrono::duration_cast
			<std::chrono::microseconds>(end - begin);

		//出力
		std::cout << boost::format("time   : %|| μs") % time.count() << std::endl;
		std::cout << boost::format("answer : %||") % ans << std::endl;
	}
	
}
