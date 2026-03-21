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

uint w,h,v;

int main()_{
	std::ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	cin>>w>>h>>v;
	for(uint i=0;i<h;i++){
		for(uint j=0;j<w;j++){
			cout<<'Q';
		}
		cout<<'\n';
	}
	for(uint i=0;i<w;i++){
		for(uint j=0;j<w+v;j++){
			cout<<'Q';
		}
		cout<<'\n';
	}
	return 0;
}