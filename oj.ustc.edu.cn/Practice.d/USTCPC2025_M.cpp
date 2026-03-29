#include<iostream>
using std::cin, std::cout, std::endl;
#include<array>
using uch = unsigned char;
using ush = unsigned short;
using uint = unsigned int;
using ull = unsigned long long;
using ll = long long;
#define _ noexcept

constexpr uint MOD=1e9+7;
ull n,k;

template<typename T, size_t N>
struct Mat: std::array<std::array<T,N>,N>{ // Mat[row][col]
	constexpr auto static I()_{
		Mat ret{};
		for(size_t i=0;i<N;i++){
			ret[i][i]=1;
		}
		return ret;
	}

	// using MatThis=Mat<T,N>;
	auto operator*(const Mat &other)const _{
		Mat ret{};
		for(size_t i=0;i<N;i++){
			for(size_t j=0;j<N;j++){
				for(size_t k=0;k<N;k++){
					(ret[i][j]+=(*this)[i][k]*other[k][j])%=MOD;
				}
			}
		}
		return ret;
	}
	auto operator*=(const Mat &other)_{
		return *this = *this * other;
	}
	auto pow(auto exp)const _{
		Mat ret=I(), M = *this; // identity mat I
		while(exp>0){
			if(exp&1)
				ret *= M;
			M *= M; exp>>=1;
		}
		return ret;
	}
};

// uint solve(const ull n, const ull k)_{
// 	const uint kmod=k%MOD;
// 	if(n==k){
// 		return kmod;
// 	}
// 	Mat<ll,3>coef{{
// 		static_cast<ll>((static_cast<ull>(kmod+4)*kmod)%MOD), kmod, 1,
// 	}}, a{{
// 		(kmod+2)%MOD,	1,	0,
// 		-1,				0,	0,
// 		(kmod*2)%MOD,	0,	1,
// 	}};
// 	coef *= a.pow(n/k - 2);
// 	return (coef[0][0]+MOD)%MOD;
// }

uint solve(ull n, ull k)_{
	if(n==k){
		return k%MOD;
	}
	const ull m=n/k; // m>1
	k%=MOD;
	constexpr	uint a_0=2;
	const		uint a_1=(k+2)%MOD;
	Mat<ull,2> a{{
		a_1,	MOD-1 /*-1*/,
		1,		0,
	}};
	a=a.pow(m-1);
	const 		uint a_m=(a[0][0]*a_1 + a[0][1]*a_0)%MOD;
	return (a_m + MOD - 2)%MOD;
}

int main()_{
	std::ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	cin>>n>>k;
	// /* ans= // classified by the remaining edges of 0 (originally n/k)
	// 	1: n/k * n
	// 	2: C_(n/k)^2 * edges_1 * edges_2, where edges_1+edges_2 == n/k
	// 	r: C_(n/k)^r * Product_(i=1)^(r) shares_i*k, where Sum_(i=1)^(r) shares_i*k == n && shares_i in [1,n/k]
	// 	so ans = Sum_(r=1)^(n/k) Sum_(Sum_(i=1)^(r) shares_i*k == n && shares_i in [1,n/k]) Product_(i=1)^(r) shares_i*k
	// */
	/*
		f[n] = sum_(sum shares_i = n/k) (shares_1 * (prod_(i in [1,n/k]) shares_i * k))
		f[n] = 2k + (2+k)f[n-1] - f[n-2] (everything can %MOD), where f[1]=k, f[2]=4k+k^2, and f[n] is the answer.
	*/
	cout<<solve(n,k)<<endl;
	return 0;
}