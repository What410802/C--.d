#include<iostream>
using std::cin, std::cout, std::endl;
// #include<cmath>
#include<vector>
#include<algorithm>
#include<numeric>
#include<set>
using uint = unsigned int;
using ull = unsigned long long;
using ll = long long;
using uch = unsigned char;
#define _ noexcept

constexpr uint max_possible = 9701+1;

int main()_{
	std::ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	uint n; cin>>n;
	std::vector<uint> a; a.resize(n);
	uint gcd=0;
	for(uint i=0;i<n;i++){
		cin>>a[i];
		gcd=std::gcd(gcd, a[i]);
	}
	if(gcd!=1){
		cout<<"INF"<<endl;
		return 0;
	}
	std::sort(a.begin(), a.end()); a.erase(std::unique(a.begin(), a.end()), a.end());
	std::set<uint>mem;
	mem.emplace(1);
	for(const auto ai:a){
		for(const auto elem:mem){ // Can traverse newly inserted elem.
			const uint target = elem + ai;
			if(target <= max_possible){
				mem.emplace(target);
			}
		}
	}
	cout<<max_possible - mem.size()<<endl;
	return 0;
}