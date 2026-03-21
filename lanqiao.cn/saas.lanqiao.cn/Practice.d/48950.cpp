#include<iostream>
using std::cin, std::cout, std::endl;
#include<string>
using uint = unsigned int;
using ull = unsigned long long;
using ll = long long;
using uch = unsigned char;
#define _ noexcept

#define L 500002
uint k;
std::string s;
char c1,c2;
uint pref1[L];

int main()_{
	std::ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	cin>>k>>s>>c1>>c2;
	pref1[0]=(s[0]==c1);
	for(uint i=1;i<s.length();i++){
		pref1[i]=pref1[i-1]+(s[i]==c1);
	}
	ull ans=0;
	for(uint i=k-1;i<s.length();i++){
		if(s[i]==c2){
			ans+=pref1[i-(k-1)];
		}
	}
	cout<<ans<<endl;
	return 0;
}