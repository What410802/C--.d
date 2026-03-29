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
	uint n; cin>>n;
	uint ans=0x7fffffff;
	for(uint i=0;i<n;i++){
		uint in; cin>>in;
		if(ans>in){
			ans=in;
		}
		cout<<ans<<(i==n-1?'\n':' ');
	}
	return 0;
}