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

ull get_t0(ull fac)_{
	ull ret=0;
	while(fac){ // From observation
		fac/=5;
		ret+=fac;
	}
	return ret;
}

ll q(ull t0)_{
	ull l=0,r=t0*5,mid;
	ll ans=-1;
	while(l<=r){
		mid=l+((r-l)>>1);
		const auto cur_t0=get_t0(mid);
		if(cur_t0==t0){
			r=mid-1;
			ans=mid;
		}
		else if(cur_t0<t0){
			l=mid+1;
		}
		else{
			r=mid-1;
		}
	}
	return ans;
}

int main()_{
	std::ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	ull k; cin>>k;
	/*
		5~9: 1; 10: 2; 15: 3; 20: 4; 25: 6; 30: 7; ...; 124: 28; 125: 31.
		5 is more scarce.
	*/
	cout<<q(k)<<'\n';
	return 0;
}