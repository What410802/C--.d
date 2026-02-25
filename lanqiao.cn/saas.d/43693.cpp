#include<iostream>
using std::cin, std::cout, std::endl;
#include<sstream>
#include<iomanip>
#include<set>
using uint = unsigned int;
using ull = unsigned long long;
using ll = long long;
using uch = unsigned char;
#define _ noexcept


uint get_month_length(uint y, uint m){
	switch(m){
		case 1:
			return 31;
		case 2:
			return y%4 == 0 ? (y%100 == 0 ? (y%400 == 0 ? 29 : 28) : 29) : 28;
		case 3:
			return 31;
		case 4:
			return 30;
		case 5:
			return 31;
		case 6:
			return 30;
		case 7:
			return 31;
		case 8:
			return 31;
		case 9:
			return 30;
		case 10:
			return 31;
		case 11:
			return 30;
		case 12:
			return 31;
	}
}

bool is_month(const uint m)_{
	return 1<=m && m<=12;
}
bool is_day(const uint d, const uint m, const uint y)_{
	return 1<=d && d<=get_month_length(y, m);
}
uint get_year(uint y)_{
	return y<60 ? 2000+y : 1900+y;
}
std::string get(const uint y, const uint m, const uint d)_{
	std::stringstream s;
	s<<y<<'-'
		<<std::setw(2)<<std::setfill('0')<<m<<'-'
		<<std::setw(2)<<std::setfill('0')<<d;
	return s.str();
}
std::string test_comb(const uint y, const uint m, const uint d)_{
	if(is_month(m) && is_day(d, m, y)){
		return get(get_year(y), m, d);
	}
	else{
		return "";
	}
}

int main()_{
	std::ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	uint n1,n2,n3;
	cin>>n1; cin.ignore(1); cin>>n2; cin.ignore(1); cin>>n3;
cout<<n1<<'#'<<n2<<'#'<<n3<<endl;
	std::set<std::string> set;
	for(const auto tp:{std::tuple{n1, n2, n3}, {n3, n1, n2}, {n3, n2, n1}}){ // YY-MM-DD, MM-DD-YY, DD-MM-YY
		const auto [y,m,d] = tp;
		const auto tmp = test_comb(y,m,d);
		if(!tmp.empty()){
			set.emplace(tmp);
		}
	}
	for(const auto &str:set){
		cout<<str<<endl;
	}
	return 0;
}