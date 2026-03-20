#include<iostream>
using std::cin, std::cout, std::endl;
#include<string>
using uch = unsigned char;
using ush = unsigned short;
using uint = unsigned int;
using ull = unsigned long long;
using ll = long long;
#define _ noexcept

uint n;
std::string s;

uint cntlen(decltype(s)::iterator &it, const char c)_{
	const auto beg=it;
	for(;;){
		if(it == s.end() || *it!=c){
			return it - beg;
		}
		else{
			++it;
		}
	}
}

int main()_{
	std::ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	cin>>n>>s;
	ull ans=0;
	for(auto it=s.begin(); it!=s.end();){
		if(*it != 'x'){
			++it;
			continue;
		}
		const uint cntx = cntlen(it, 'x');
		const uint
			cntj = cntlen(it, 'j'),
			cntt = cntlen(it, 't'),
			cntu = cntlen(it, 'u');
		if(cntj == 0 || cntt == 0 || cntu == 0){
			continue;
		}
		ans += (ull)cntx * cntu;
	}
	cout<<ans<<'\n';
	return 0;
}