#include<iostream>
using std::cin, std::cout, std::endl;
#include<numeric>
using uint = unsigned int;
using ull = unsigned long long;
using ll = long long;
using uch = unsigned char;
#define _ noexcept

uint n,m;
#define N 100002
constexpr uint L = 1000002<<1;
uint cen[N]; // multiplied by 2
uint cntpre[L]/*, cntpost[L]*/;

// #segment-center in [l,r] = #sc in [0,r] - #sc in [0,l-1].
int main()_{
	std::ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	cin>>n>>m;
	for(uint i=0;i<n;i++){
		uint l,r; cin>>l>>r;
		cen[i] = l+r;
		cntpre[cen[i]]++;
		// cntpost[cen[i]]++;
	}
	std::partial_sum(cntpre, cntpre+L, cntpre); // cntpre[l] is the count of center-of-segment in range [0,l]
	// for(uint i=L-2;i<L;i--){ // Same as cntpre. cntpost[l] is the count of that in [l, L-1]
	// 	cntpost[i] += cntpost[i+1];
	// }
// for(uint i=0;i<20;i++){
// 	cout<<i<<' '<<cntpre[i]<<'\t';
// }
// cout<<endl;
	for(uint i=0;i<m;i++){
		uint lin,rin;
		cin>>lin>>rin; lin<<=1; rin<<=1;
		cout<<cntpre[rin]-cntpre[lin-1]<<endl;
	}
	return 0;
}