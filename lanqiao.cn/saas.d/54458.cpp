#include<iostream>
using std::cin, std::cout, std::endl;
#include<array>
using uint = unsigned int;
using ull = unsigned long long;
using ll = long long;
using uch = unsigned char;
#define _ noexcept

constexpr uint N=100001;
constexpr uint MOD=998244353;
constexpr std::array<uint,N> Factorials()_{
	std::array<uint,N> ret{1};
	for(uint i=1;i<N;i++){
		ret[i]=(ull)ret[i-1]*i%MOD;
	}
	return ret;
}
constexpr std::array<uint,N> Powers(const uint a)_{
	std::array<uint,N> ret{1};
	for(uint i=1;i<N;i++){
		ret[i]=(ull)ret[i-1]*a%MOD;
	}
	return ret;
}

constexpr auto factorials = Factorials();
constexpr auto powers = Powers(10);

uint qpow(uint a,uint n)_{
	uint ret=1;
	while(n){
		if(n&1){
			ret=(ull)ret*a%MOD;
		}
		a=(ull)a*a%MOD; n>>=1;
	}
	return ret;
}
uint C(const uint n, const uint m)_{
	if(n<m){
		return 0;
	}
	return (ull)factorials[n]*qpow((ull)factorials[m]*factorials[n-m]%MOD, MOD-2)%MOD;
}
uint n,m;
uint not_less_than(const uint mp)_{
	if(mp*4>n){
		return 0;
	}
	const uint vd=n-3*mp;
	return (ull)C(vd,mp)*powers[vd-mp]%MOD;
}

int main()_{
	std::ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	cin>>n>>m; // vd=n-3*m is the number of valid digits. The answer is C_vd^m * 10^(vd-m). e.g., n=5,m=1, vd=2, ans=20.
	uint ans=0;
	for(uint mp=m;mp*4<=n;mp++){
		const uint abs=(ull) C(mp,m) * not_less_than(mp) %MOD;
		ans+=(mp-m)&1 ? MOD -abs : abs;
		if(ans>MOD){ans-=MOD;}
	}
	cout<<ans<<endl;
	return 0;
}