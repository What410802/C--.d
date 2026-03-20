#include<iostream>
using std::cin, std::cout;
#include<iomanip>
#include<string>

using uch = unsigned char;
using ush = unsigned short;
using uint = unsigned int;
using ull = unsigned long long;
using ll = long long;
#define _ noexcept

void minus_minus(std::string &s, uint i)_{
	s[i]--;
	for(;;i--){
		if(s[i]<'0'){
			s[i]='9';
			s[i-1]--;
		}
		else{
			break;
		}
		// if(i>=s.length()){ // Processed. Not possible.
		// 	s.insert(s.begin(), '1');
		// 	break;
		// }
	}
}

int main()_{
	std::ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	while(cin.peek()=='0'){
		cin.get();
	}
	std::string s; cin>>s;
	if(s.length()==1){
		cout<<s<<'\n';
		return 0;
	}
	if(s[0]=='1'){ // 1000...
		bool is_1en = true;
		for(uint i=1;i<s.length();i++){
			if(s[i]!='0'){
				is_1en=false;
				break;
			}
		}
		if(is_1en){
			for(uint i=1;i<s.length();i++){
				cout<<'9';
			}
			cout<<'\n';
			return 0;
		}
	}
	auto get_sym = [lm1=s.length()-1](auto pos)_{return lm1-pos;};
	uint i=(s.length()-2)/2, sym=get_sym(i); // in case of 1
	bool has_inequal=false, viable;
	for(; sym<s.length(); i--, sym++){
		if(s[i]!=s[sym]){
			has_inequal = true;
			viable = (s[i]<s[sym]);
			break;
		}
	}
	if(has_inequal){
		if(viable){
		}else{
			minus_minus(s, s.length()/2-(s.length()&1 ? 0 : 1));
		}
		for(uint i=0, sym=get_sym(i);i<sym;i++, sym--){
			s[sym]=s[i];
		}
	}else{}
	cout<<s<<'\n';
	return 0;
}
// 3211: 3113, 3210: 3113, 3002: 2992, 1000: 999, 2000: 1991