#include<iostream>
using std::cin, std::cout, std::endl;
// #include<stack>
#include<list>
#include<string>
#include<string_view>
using uch = unsigned char;
using ush = unsigned short;
using uint = unsigned int;
using ull = unsigned long long;
using ll = long long;
#define _ noexcept

std::string s;
const std::string static substr = "flag{";
bool is_begin_of_flag(std::string::iterator it)_{
	if(it + substr.length() >= s.end()){
		return false;
	}
	for(uint i=0;i<substr.length();i++){
		if(*(it+i) != substr[i]){
			return false;
		}
	}
	return true;
}

int main()_{
	std::ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	cin>>s;
	decltype(s)::iterator prev_begin = s.end();
	for(std::string::iterator it=s.begin();it!=s.end();){
		if(is_begin_of_flag(it)){
			prev_begin = it;
			it+=substr.length(); ///
		}
		else{
			switch(*it){
				case '{':{ // bad ending
					// decltype(stk)().swap(stk); // Clear stk.
					prev_begin = s.end();
				} break;
				case '}':{
					if(prev_begin != s.end()){ // success
						cout<<std::string_view(s).substr(prev_begin-s.begin(), it+1-prev_begin)<<endl;
						return 0;
					}
				} break;
			}
			++it;
		}
	}
	cout<<"NOT FOUND"<<endl;
	return 0;
}