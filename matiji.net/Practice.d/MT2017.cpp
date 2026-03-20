#include<iostream>
using std::cin, std::cout;
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

uch times[26][26], max;
uch prev0, prev1;

int main()_{
	std::ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	uint n; cin>>n;
	std::string s; cin>>s;
	s[0]-='A';
	for(uint i=1;i<n;i++){
		s[i]-='A';
		if((++times[s[i-1]][s[i]]) > max){
			max=times[s[i-1]][s[i]];
		}
	}
	// cout<<static_cast<uint>(max)<<'\n';
	for(uint i=0;i<26;i++){
		for(uint j=0;j<26;j++){
			// cout<<i<<' '<<j<<": "<<static_cast<uint>(times[i][j])<<'\n';
			if(times[i][j]==max){
				prev0 = i; prev1 = j;
				goto _out;
			}
		}
	}
	_out:
	cout<<static_cast<char>('A'+prev0)<<static_cast<char>('A'+prev1)<<'\n';
	return 0;
}