#include <iostream>

int main(){
	#if defined(__clang__)
		std::cout << "`__clang__` defined. Compiler: clang++\n";
	#endif
	#if defined(__GNUC__)
		std::cout << "`__GNUC__` defined. Compiler: g++\n";
	#endif
	#if defined(__GNUG__)
		std::cout << "`__GNUG__` defined. Compiler: g++\n";
	#endif
	#if defined(_MSC_VER)
		std::cout << "`_MSC_VER` defined. Compiler: MSVC\n";
	#endif

	const auto ver = __cplusplus;
	std::cout << "C++ standard: ";
	if (ver == 202002L)      std::cout << "C++20\n";
	else if (ver == 201703L) std::cout << "C++17\n";
	else if (ver == 201402L) std::cout << "C++14\n";
	else if (ver == 201103L) std::cout << "C++11\n";
	else if (ver == 199711L) std::cout << "C++98\n";
	else                     std::cout << "pre-standard or draft (" << ver << ")\n";

	return 0;
}