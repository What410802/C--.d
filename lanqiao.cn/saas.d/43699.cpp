#include<iostream>
using std::cin, std::cout, std::endl;
#include<cmath>
using uint = unsigned int;
using ull = unsigned long long;
using ll = long long;
using uch = unsigned char;
#include <cstdint>

constexpr bool is_perfect_square(const uint n) noexcept {
	if(n<=1)
		return true;
	switch(n&0xf){
		case 0: case 1: case 4: case 9: break;
		default: return false;
	}
	// Hacker's Delight
	uint x = n, y = 0;  // y is the result
	for(uint b = 0x40000000; b != 0; b >>= 2){ // 2^30 covers the range of y
		uint t = y | b; // candidate
		y >>= 1;
		if (x >= t) {
			x -= t;
			y |= b;     // success
		}
	}
	return y*y==n;
}

uint n;

int main(){
	cin.tie(nullptr);
	std::ios::sync_with_stdio(false);
	cin>>n;
	uint sqrt_n = std::sqrt(n);
	for(uint i=0;i<=sqrt_n;i++){
		uint i_sq = i*i;
		for(uint j=i;j<=sqrt_n;j++){
			uint i_j_sq = i_sq + j*j;
			for(uint k=j;k<=sqrt_n;k++){
				uint i_j_k_sq = i_j_sq + k*k;
				uint fourth_sq = n - i_j_k_sq;
				// if(fourth_sq < k*k){
				// 	// Lagrange is wrong.
				// }
				if(is_perfect_square(fourth_sq)){
					cout<<i<<' '<<j<<' '<<k<<' '<<std::sqrt(fourth_sq)<<endl;
					return 0;
				}
			}
		}
	}
	// return 0;
}