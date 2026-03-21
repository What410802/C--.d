#include<iostream>
using std::cin, std::cout, std::endl;
#include<numeric>
// #include<type_traits>
#include<algorithm>
using uint = unsigned int;
using ull = unsigned long long;
using ll = long long;
using uch = unsigned char;
#define _ noexcept
#define uint ull

/*template<typename T=ll>
class Fraction{
	public:
	T num;
	std::make_unsigned<T> den;
	Fraction(const T n, const std::make_unsigned<T> d):num(n), den(d) _ {}
	Fraction(T n = 0, T d = 1)_{
		// assert(d != 0);
		if(d<0){
			n = -n;
			d = -d;
		}
		const T g = std::gcd(std::abs(n), d);
		num = n/g;
		den = d/g;
	}
	Fraction& operator=(const Fraction& rhs)_{
		num = rhs.num;
		den = rhs.den;
		return *this;
	}
	Fraction operator()()_{}
	Fraction operator+(const Fraction& rhs) const _{
		const T new_den
		 = den / std::gcd(den, rhs.den) * rhs.den;
		const std::make_unsigned<T> new_num
		 = num * (new_den / den) + rhs.num * (new_den / rhs.den);
		return Fraction(new_num, new_den);
	}
	Fraction operator-(const Fraction& rhs) const _{
		const T new_den
		 = den / std::gcd(den, rhs.den) * rhs.den;
		const std::make_unsigned<T> new_num
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

	double to_double() const _{ return (double)num/den; }
	
	friend std::ostream& operator<<(std::ostream& os, const Fraction& f)const _{
		// if (f.den == 1)
		// 	os << f.num;
		// else
			os << f.num << "/" << f.den;
		return os;
	}
	friend std::istream& operator>>(std::istream& is, Fraction& f)_{
		T n;
		std::make_unsigned<T> d = 1;
		char c;
		is >> n;
		if (is.peek() == '/') {
			is >> c >> d;
		}
		f = Fraction(n, d);
		return is;
	}
};

Fraction<> rats[N-1];*/
#define N 101
uint x[N];
uint de[N-1], nu[N-1];
// uint normal_gcd(uint a, uint b)_{ // Prefer a>=b;
// 	while(b){ // a, b = b, a%b
// 		// const uint t=b;
// 		// b=a%b;
// 		// a=t;
// 		a%=b; // After this, a must < b
// 		std::swap(a,b); // After this, a must > b
// 	}
// 	return a;
// }
uint log_gcd(uint a, uint b)_{ // If a<=1 || b<=1, the bigger is returned.
	for(;;){
		if(a<b){
			std::swap(a,b);
		} // After this, a must >= b
		if(b>1){
			a /= b; // [a, b] == n pow [ta,tb], where all numbers are integer
		}
		else{
			return a;
		}
	}
}

int main()_{
	std::ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	uint n; cin>>n;
	for(uint i=0;i<n;i++){
		cin>>x[i];
	}
	std::sort(x, x+n);
	n = std::unique(x, x+n) - x;
	uint gcd_de = 0, gcd_nu = 0;
	for(uint i=0;i<n-1;i++){
		const uint gcd = std::gcd(x[i], x[i+1]);
		de[i] = x[i]/gcd;
		nu[i] = x[i+1]/gcd;
		gcd_de = log_gcd(gcd_de, de[i]);
		gcd_nu = log_gcd(gcd_nu, nu[i]); ////
	}
	/*ull common_de = de[0]; /// std::lcm does not tolerate 0
	for(uint i=1;i<n-1;i++){
		common_de = std::lcm(common_de, de[i]);
	}
	ull gcd_nu = 0;
	for(uint i=0;i<n-1;i++){
		// nu[i] = nu[i]*common_de/de[i];
		// de[i] = common_de;
		gcd_nu = std::gcd(gcd_nu, nu[i]*common_de/de[i]); /// std::gcd tolerates 0
	}*/
	const uint gcd_final = std::gcd(gcd_nu, gcd_de);
	gcd_nu /= gcd_final;
	gcd_de /= gcd_final;
	cout<<gcd_nu<<'/'<<gcd_de<<endl;
	return 0;
}