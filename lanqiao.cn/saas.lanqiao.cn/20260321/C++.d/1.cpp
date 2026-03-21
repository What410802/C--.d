#include<iostream>
using std::cin; using std::cout;
#include<iomanip>
#include<string>
#include<vector>

#include<numeric>
#include<functional>
using uch = unsigned char;
using ush = unsigned short;
using uint = unsigned int;
using ull = unsigned long long;
using ll = long long;
#define _ noexcept


int main()_{
	std::ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	// 1. C_50^2 - C_7^2 = [1204]
	// 2. 4->2: 0:00; 1: 01; 2: 10; 3: 11. So only 0,1 satisfy. 2024_10 = 133220_4. ans=1*2^5 + 2^5 - card{0} = 64-1 = 63
	/* 3. {0,1,2,3,4,5,6,7,8,9}^3
		= {0,1,8,7,4,5,6,3,2,9}
			   ^ ^       ^ ^
		So just to find those end with 7.
		[1,999]: 100
		[1000, 1999]: 100
		[2000, 2025]: {09,19}: 2
		ans=202
	*/
	/*
		5. l=1e4, ab=9
		ans	= 9^l - 8^l * 2 + 7^l
			= 157509472
	*/
/*
	6. 2429042904288
*/
	return 0;
}