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
uint n;

int main()_{
	std::ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	cin>>n;
	uint no=0;
	for(uint i=0;i<n;i++){
		uint a,b; cin>>a>>b;
		if(b<a){
			no++;
		}
	}
	cout<<(n-no)<<' '<<no<<'\n';
	return 0;
}