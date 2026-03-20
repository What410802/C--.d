#include<iostream>
using std::cin, std::cout, std::endl;
#include<string>
using uch = unsigned char;
using ush = unsigned short;
using uint = unsigned int;
using ull = unsigned long long;
using ll = long long;
#define _ noexcept


int main()_{
	std::ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	uint n; cin>>n;
	for(uint i=0;i<15;i++){
		std::string s;
		uint pass;
		cin>>s>>pass;
		cout<<s<<' '<<'L'<<(pass==0?'3':(pass==n?'1':'2'))<<'\n';
	}
	return 0;
}