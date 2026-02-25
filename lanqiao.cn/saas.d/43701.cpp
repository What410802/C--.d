#include<iostream>
using std::cin, std::cout, std::endl;
#include<string>
#include<cmath>
// #include<utility>
#include<algorithm>
using uint = unsigned int;
using ull = unsigned long long;
using ll = long long;
using uch = unsigned char;
#define _ noexcept

#define N 1001
uint publ[N][N];

int main()_{
	std::ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	std::string s; cin>>s;
	const uint l=s.length();
	std::string sr = s; std::reverse(sr.begin(), sr.end());
	for(uint i=0;i<l;i++){
		for(uint j=0;j<l;j++){
			publ[i+1][j+1] = s[i]==sr[j] ? publ[i][j] + 1 : std::max(publ[i][j+1], publ[i+1][j]);
		}
	}
	cout<<l - publ[l][l]<<endl;
	return 0;
}