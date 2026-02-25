#include<iostream>
using std::cin, std::cout, std::endl;
#include<string>
using uint = unsigned int;
using ull = unsigned long long;
using ll = long long;
using uch = unsigned char;
#define _ noexcept

int main()_{
	std::ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	std::string s; cin>>s;
	uint ans=0;
	for(uint i=1;i<s.length();){
		if(s[i]==s[i-1] || s[i]=='?' || s[i-1]=='?'){
			ans++;
			i+=2;
		}
		else{
			i++;
		}
	}
	cout<<ans<<endl;
	return 0;
}