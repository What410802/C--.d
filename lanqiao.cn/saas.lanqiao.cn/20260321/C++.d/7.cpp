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

struct Cnt{
	uint cnt:2;
	void operator++()_{
		++cnt;
	}
	operator uint()const _{
		return cnt;
	}
	char get_char()const _{
		return "2025"[cnt];
	}
}cnt;

int main()_{
	std::ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	uint h,w; cin>>h>>w;
	for(uint i=0;i<h;i++){
		cnt.cnt=i;
		for(uint j=0;j<w;j++){
			cout<<cnt.get_char();
			cnt.cnt++;
		}
		cout<<'\n';
	}
	return 0;
}