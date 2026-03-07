#include<iostream>
using std::cin, std::cout, std::endl;
#include<numeric>
#include<array>
#include<utility>
using uch = unsigned char;
using ush = unsigned short;
using uint = unsigned int;
using ull = unsigned long long;
using ll = long long;
#define _ noexcept

constexpr uint ndaysp1=21;
constexpr auto get_coef()_{
	std::array<std::pair<uint,uint>,ndaysp1> ret{{{0,0},{1,0},{1,1}}}; // pair.first: coef for p; pair.second: coef for 1
	for(uint i=3;i<ndaysp1;i++){
		ret[i].first=ret[i-1].first+ret[i-2].first;
		ret[i].second=ret[i-1].second+ret[i-2].second;
	}
	return ret;
}
constexpr auto coefs=get_coef();

int main()_{
	std::ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	uint T;
	cin>>T;
	uint a,b; ull x;
	ull p_term;
	while(T--){
		cin>>a>>x>>b;
		p_term = x - coefs[a].second;
		if(p_term%coefs[a].first==0){
			cout<<(ull)coefs[b].first*p_term/coefs[a].first+coefs[b].second<<endl;
		}
		else{
			cout<<"-1"<<endl;
		}
	}
	return 0;
}