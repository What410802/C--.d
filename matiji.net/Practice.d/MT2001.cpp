#include<iostream>
using std::cin, std::cout;
#include<iomanip>
#include<string>
#include<numeric>
using uch = unsigned char;
using ush = unsigned short;
using uint = unsigned int;
using ull = unsigned long long;
using ll = long long;
#define _ noexcept

uint sums[3];
uint get_sum(const std::string &s)_{
	uint ret=0;
	for(const char c: s){
		ret+=c-'0';
	}
	return ret;
}
uint get_ans()_{
	uint ret=sums[0]>>1;
	ret+=std::min(sums[1],sums[2]);
	return ret;
}

int main()_{
	std::ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	uint n; cin>>n;
	for(uint i=0;i<n;i++){
		std::string s; cin>>s;
		sums[get_sum(s)%3]++;
	}
	cout<<get_ans()<<'\n';
	return 0;
}