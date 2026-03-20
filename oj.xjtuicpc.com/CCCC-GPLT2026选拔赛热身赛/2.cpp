#include<iostream>
using std::cin, std::cout, std::endl;

using uch = unsigned char;
using ush = unsigned short;
using uint = unsigned int;
using ull = unsigned long long;
using ll = long long;
#define _ noexcept

void maze(ll &a, const ll b)_{
	if(a<b){
		a=b;
	}
}

int main()_{
	std::ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	uint n; cin>>n;
	int a[n];
	for(uint i=0;i<n;i++){
		cin>>a[i];
	}
	ll mode0=0, ans=0;
	for(uint i=0;i<n;i+=2){
		mode0+=a[i];
		maze(ans, mode0);
	}
	ll mode1=0;
	for(uint i=1;i<n;i+=2){
		mode1+=a[i];
		maze(ans, mode1);
	}
	cout<<ans<<'\n';
	return 0;
}