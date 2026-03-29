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

constexpr uint MOD=10007;
uint n,m;
uint lb=0x7fffffff,ub=0;

int main()_{
	std::ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	cin>>n>>m;
	for(uint i=0;i<n;i++){
		uint in; cin>>in;
		lb=std::min(lb,in);
		ub=std::max(ub,in);
	}
	uint ans=0;
	for(uint i=0;i<m;i++){
		uint l,r; cin>>l>>r;
		if(r<lb || l>ub){
			ans+=n;
		}
		else{
			ans+=n-(std::min(r,ub)-std::max(l,lb)+1);
		}
		ans%=MOD;
	}
	cout<<ans<<'\n';
	return 0;
}