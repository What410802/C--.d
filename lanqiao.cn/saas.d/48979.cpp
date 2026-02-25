#include<iostream>
using std::cin, std::cout, std::endl;
#include<string>
#include<cmath>
using uint = unsigned int;
using ull = unsigned long long;
using ll = long long;
using uch = unsigned char;
#define _ noexcept

constexpr char prea='a'-1;

int main()_{
	std::ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	std::string s;
	cin>>s;
	if(s.length()==1){
		cout<<s[0]-prea<<endl;
		return 0;
	}
	uint ans[s.length()];
	ans[0]=s[0]-prea;
	ans[1]=std::max(s[0], s[1])-prea;
	for(uint i=2;i<s.length();i++){
		ans[i]=std::max(ans[i-2]+(s[i]-prea), ans[i-1]);
	}
	cout<<ans[s.length()-1]<<endl;
	return 0;
}