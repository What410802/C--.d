#include<iostream>
using std::cin; using std::cout; constexpr auto LF='\n';
#include<iomanip>
#include<string>
#include<vector>
#define vec std::vector

// #include<random>
// std::random_device rd;
// std::mt19937_64 gen(rd());

#include<numeric>
using std::min, std::max;
using uch = unsigned char; using ch = char;
using ush = unsigned short;
using uint = unsigned int;
using ull = unsigned long long; using ll = long long;

#define MOD 998244353u
#define N 100009
uint n;


int main(){
	std::ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	uint t; cin>>t;
	while(t--){
		uint n,s; cin>>n>>s;
		uint p;
		for(uint i=0;i<n;i++){
			cin>>p;
			if(const uint nxs=(s+p+1)>>1; nxs>s){
				s=nxs;
			}
		}
		cout<<s<<LF;
	}
	return 0;
}
/*
5
2 3
1 5
3 3
2 6 1
4 5
5 5 5 5
5 1000000000
1000000000 1000000000 1000000000 1000000000 1000000000
10 100
97 135 103 130 147 89 93 215 175 261

4
5
5
1000000000
219
*/