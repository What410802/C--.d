#include<iostream>
using std::cin, std::cout, std::endl;

using uch = unsigned char;
using ush = unsigned short;
using uint = unsigned int;
using ull = unsigned long long;
using ll = long long;
#define _ noexcept

constexpr uint MOD=1e9+7;
ull n,k;

template<typename T>
struct Mat2x2{
	T a,b, c,d; // [a b; c d]
	Mat2x2 operator*(const Mat2x2 &other)const _{
		return {
			a * other.a + b * other.c,
			a * other.b + b * other.d,
			c * other.a + d * other.c,
			c * other.b + d * other.d
		};
	}
	auto operator*=(const Mat2x2 &other)_{
		return *this = *this * other;
	}
	Mat2x2<T> pow(T exp)const _{
		Mat2x2<T> ret = {1, 0, 0, 1}, M = *this; // identity mat I
		while(exp>0){
			if(exp&1)
				ret *= M;
			M *= M; exp>>=1;
		}
		return ret;
	}
};

template<typename T = ull>
T sum_compositions_fast(const T n, const T k)_{
	/// assert(n % k != 0);
	const T m = n / k;
	if (m == 0) return 1;
	if (m == 1) return k;
	
	T f1 = k, f2 = k * k + 2 * k;
	if (m == 2) return f2;
	
	auto Mp = Mat2x2<ull>({k+2, -1ull, 1, 0}).pow(m-2);
	
	// V2 = [f2; f1]
	// Result = first component of Mp * V2
	return Mp.a * f2 + Mp.b * f1;
}

int main()_{
	std::ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	cin>>n>>k;
	/* ans= // classified by the remaining edges of 0 (originally n/k)
		1: n/k * n
		2: C_(n/k)^2 * edges_1 * edges_2, where edges_1+edges_2 == n/k
		r: C_(n/k)^r * Product_(i=1)^(r) shares_i*k, where Sum_(i=1)^(r) shares_i*k == n && shares_i in [1,n/k]
		so ans = Sum_(r=1)^(n/k) Sum_(Sum_(i=1)^(r) shares_i*k == n && shares_i in [1,n/k]) Product_(i=1)^(r) shares_i*k
	*/
	cout<<sum_compositions_fast(n,k)<<endl;
	return 0;
}