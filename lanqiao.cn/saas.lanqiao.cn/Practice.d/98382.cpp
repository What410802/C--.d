#include<iostream>
using std::cin, std::cout, std::endl;

using uint = unsigned int;
using ull = unsigned long long;
using ll = long long;
using uch = unsigned char;
#define _ noexcept

#define N 300002
uint d_a[N], zero_pref[N], one_pref[N]; // The sum of d[[0,i]] is the value of a[i]. The sum of normal[[0,i]] is pref[i]; the sum of normal[[l,r]] is pref[r]-pref[l-1].
uint l[N], r[N];

int main()_{
	std::ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	uint n,m;
	cin>>n>>m;
	for(uint i=0;i<m;i++){
		cin>>l[i]>>r[i];
		d_a[l[i]]++;
		d_a[r[i]+1]--;
	}
	for(uint i=1;i<=n;i++){
		d_a[i]+=d_a[i-1];
		zero_pref[i]+=zero_pref[i-1]+(d_a[i]==0);
		one_pref[i]+=one_pref[i-1]+(d_a[i]==1);
	} // Now a
	for(uint i=0;i<m;i++){
		cout<< zero_pref[n] + one_pref[r[i]] - one_pref[l[i]-1] <<endl;
	}
	return 0;
}