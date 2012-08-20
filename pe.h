#pragma once
#include <iostream>
#include <chrono>
#include <boost/format.hpp>

namespace euler
{
	/** 
	 * Project Eulerを解いて処理時間と解を出力する
	 *
	 * @param Func 引数なしの関数オブジェクト型．返り値はvoid以外．
	 * @param Range SinglePathRange．
	 *
	 * @param solver 問題を解く関数．解答を返す．
	 * @param state 問題文を想定．計測前に出力する．
	 * 
	 * @return solver()の返り値．
	 */
	template <typename Func, typename Range>
	auto solve(Func solver, const Range& state) -> decltype(solver())
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
	   

		//処理時間
		auto const time = std::chrono::duration_cast
			<std::chrono::microseconds>(end - begin);

		//出力
		std::cout << boost::format("time   : %|| μs") % time.count() << std::endl;
		std::cout << boost::format("answer : %||") % ans << std::endl;

		return ans;
	}
	
}
