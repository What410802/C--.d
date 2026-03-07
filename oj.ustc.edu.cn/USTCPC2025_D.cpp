#include<iostream>
using std::cin, std::cout, std::endl;
#include<iomanip>
#include<vector>
#include<numeric> // std::gcd
#define _USE_MATH_DEFINES
#include<cmath>
using uch = unsigned char;
using ush = unsigned short;
using uint = unsigned int;
using ull = unsigned long long;
using ll = long long;
#define _ noexcept

// constexpr uint N=1e5+2;
uint n;
std::vector<int> coef;
auto get_coefs()_{ // div by 101
	if(n==0){
		return std::tuple{coef[0], 0, decltype(coef)(), };
	}
	// if(n==1){
	// 	return std::tuple{coef[0], coef[1], decltype(coef)(), };
	// }
	std::vector<int>divcoef(n-1); // // reserved places for compatibility. // should not use n-1, to avoid n=0
	/*				 __	0		0		a[n]		a[n-1]			a[n-2]-a[n]	a[n-3]-a[n-1]
		1	0	1	/	a[n]	a[n-1]	a[n-2]		a[n-3]			a[n-4]		a[n-5]
					-	a[n]	0		a[n]
					=			a[n-1]	a[n-2]-a[n]	a[n-3]
							-	a[n-1]	0			a[n-1]
							=			a[n-2]-a[n]	a[n-3]-a[n-1]	a[n-4]
									-	a[n-2]-a[n]	0				a[n-2]-a[n]
									=				a[n-3]-a[n-1]	a[n-4]-^	a[n-5]
	*/
	auto remain=coef;
	for(uint i=n-2;i<n;i--){
		divcoef[i]=remain[i+2];
		remain[i]-=divcoef[i]; // remain[i+2] does not affect, and remain[i+1] remains the same.
	}
	auto
		lncoef=remain[1],
		arctancoef=remain[0];
	return std::tuple{arctancoef, lncoef, divcoef, };
}
/*
template<typename T=ll, typename uT=ull>
class Fraction{
	public:
	T num;
	uT den;
	Fraction(const decltype(num) n, const decltype(den) d)_:num(n), den(d){}
	Fraction(const int n, const uint d)_:num(n), den(d){}
	Fraction(T n = 0, T d = 1)_{
		// assert(d != 0);
		if(d<0){
			n = -n;
			d = -d;
		}
		const auto g = std::gcd(std::abs(n), d);
		num = n/g;
		den = d/g;
	}
	Fraction& operator=(const Fraction& rhs)_{
		num = rhs.num;
		den = rhs.den;
		return *this;
	}
	Fraction operator+(const Fraction& rhs) const _{
		const decltype(den) new_den
		 = den / std::gcd(den, rhs.den) * rhs.den;
		const decltype(num) new_num
		 = num * (new_den / den) + rhs.num * (new_den / rhs.den);
		return Fraction(new_num, new_den);
	}
	Fraction operator-(const Fraction& rhs) const _{
		const decltype(den) new_den
		 = den / std::gcd(den, rhs.den) * rhs.den;
		const decltype(num) new_num
		 = num * (new_den / den) - rhs.num * (new_den / rhs.den);
		return Fraction(new_num, new_den);
	}
	Fraction operator*(const Fraction& rhs) const _{
		return Fraction(num * rhs.num, den * rhs.den);
	}
	Fraction operator/(const Fraction& rhs) const _{
		return Fraction(num * rhs.den, den * rhs.num);
	}
	Fraction& operator+=(const Fraction& rhs)_{ return *this = *this + rhs; }
	Fraction& operator-=(const Fraction& rhs)_{ return *this = *this - rhs; }
	Fraction& operator*=(const Fraction& rhs)_{ return *this = *this * rhs; }
	Fraction& operator/=(const Fraction& rhs)_{ return *this = *this / rhs; }

	bool operator==(const Fraction& rhs) const _{
		return num == rhs.num && den == rhs.den;
	}
	bool operator<(const Fraction& rhs) const _{
		return num * rhs.den < rhs.num * den;
	}
	bool operator>(const Fraction& rhs) const _{ return rhs < *this; }
	bool operator<=(const Fraction& rhs) const _{ return !(rhs < *this); }
	bool operator>=(const Fraction& rhs) const _{ return !(*this < rhs); }

	double to_double()const _{ return (double)num/den; }
	long double to_long_double()const _{ return (long double)num/den; }
	
	friend std::ostream& operator<<(std::ostream& os, const Fraction& f)_{
		// if (f.den == 1)
		// 	os << f.num;
		// else
			os << f.num << "/" << f.den;
		return os;
	}
	friend std::istream& operator>>(std::istream& is, Fraction& f)_{
		decltype(num) n;
		decltype(den) d = 1;
		char c;
		is >> n >> c >> d;
		f = Fraction(n, d);
		return is;
	}
};
*/
int main()_{
	std::ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	cin>>n;
	coef.resize(1+n);
	for(uint i=0;i<=n;i++){
		cin>>coef[i];
	}
	const auto [arctancoef, lncoef, divcoef] = get_coefs();
for(const auto i:divcoef){
	cout<<i<<'\t';
}
cout<<endl;
	// Fraction<__int128_t, __uint128_t> ans_divcoef;
	long double ans_divcoef=0;
	for(uint i=1;i<n;i++){ // max pow is n-2
		ans_divcoef+=(long double)divcoef[i-1]/i; //Fraction<__int128_t, __uint128_t>(divcoef[i-1], i);
	}
	/* ans	= ... + int_0^1 ... * x/(x^2+1) + int_0^1 ... * 1/(x^2+1)
			= ... + ... * 1/2 * ln(x^2+1)|_0^1 + ... * arctan(x)|_0^1
			= ... + ... * ln(2)/2 + ... * pi/4
	*/
cout<<"ans_divcoef="<<ans_divcoef<<"; lncoef="<<lncoef<<"; arctancoef="<<arctancoef<<endl;
	long double ans = ans_divcoef + lncoef * (M_LN2/2.L) + arctancoef * M_PI_4;
	cout<<std::setprecision(18)<<ans<<endl;
	return 0;
}