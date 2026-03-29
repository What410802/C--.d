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
	uint n,q; cin>>n>>q;
	std::vector<uint>hard(n);
	for(uint i=0;i<n;i++){
		cin>>hard[i];
	}
	uint force,ans;
	while(q--){
		cin>>force;
		ans=0;
		for(uint i=0;i<n;i++){
			hard[i]/=force;
			ans+=hard[i];
		}
		cout<<ans<<'\n';
	}
	return 0;
}