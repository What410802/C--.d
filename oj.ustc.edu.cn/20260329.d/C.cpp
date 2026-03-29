#include<iostream>
using std::cin; using std::cout;
#include<iomanip>
#include<string>
#include<vector>

#include<list>
#include<numeric>
#include<functional>
using uch = unsigned char;
using ush = unsigned short;
using uint = unsigned int;
using ull = unsigned long long;
using ll = long long;
#define _ noexcept

std::list<char>ls; // decltype(ls)::iterator curr; // stack: for ancestors, each layer should have 0 l/r bias, and the layer should return to the original layer.
// uint underfloor;
std::string in; decltype(in)::iterator iit;

// decltype(in)::iterator eat_lr(decltype(in)::iterator curr)_{
// 	for(;curr!=in.end();++curr){
// 		switch(*curr){
// 			case 'l':
// 			case 'r':{
// 				break;
// 			}
// 			default:{
// 				return curr;
// 			}
// 		}
// 	}
// 	return curr;
// }

// std::pair<bool, decltype(in)::iterator> nx_return(decltype(in)::iterator curr)_{
// 	switch(*curr){
// 		case 'p':{
// 			++curr;
// 			if(curr==in.end()){
// 				return {false, curr};
// 			}
// 			if(*curr=='c'){
// 				return {true, eat_lr(std::next(curr))};
// 			}
// 			if(const auto ret=nx_return(curr); ret.first){
// 				// there exist such p.
// 				curr=ret.second;
// 				if(*curr=='c'){
// 					return {true, eat_lr(std::next(curr))};
// 				}
// 			}
// 		}
// 	}
// }
bool hasback(const char c)_{
	return !ls.empty()&&ls.back()==c;
}
bool hasback(const std::string &cs)_{
	if(ls.empty()){
		return false;
	}
	for(const char c:cs){
		if(c==ls.back()){
			return true;
		}
	}
	return false;
}

int main()_{
	std::ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	uint T; cin>>T;
	while(T--){
		cin>>in;
		ls.clear();
		for(iit=in.begin();iit!=in.end();++iit){
			switch(*iit){
				case 'p':{
					if(hasback('c')){
						ls.pop_back();
					}
					else if(hasback("lrh")){
						ls.back()='p';
					}
					else{
						ls.push_back('p');
					}
				}break;
				case 'c':{
					if(hasback('p')){ // will be ..pc
						// ls.pop_back();
						// if(hasback("lrh")){
						// 	// will be ..l/r/h p c, not possible. So only possible with ..p/c/0 p c
						// }
						ls.back()='h';
					}
					else{
						ls.push_back('c');
					}
				}break;
				case 'l':
				case 'r':{
					if(hasback("ch")){
						;
					}
					else if(hasback("lr")){ // possibles (for l): pl,l
						if((ls.back()=='l')^(*iit=='l')){
							ls.back()='h';
						}
						else{
							;
						}
					}
					else{
						ls.push_back(*iit);
					}
				}break;
			}
		}
		uint cntl=0;
// for(const auto c:ls){
// 	cout<<c;
// }
// cout<<'\n';
		for(auto it=ls.begin();it!=ls.end();){
			switch(*it){
				case 'c':
				case 'l':
				case 'r':{
					goto _cont;
				}
				case 'h':{
					while(cntl>0&&it!=std::prev(ls.end())){
						if(*std::next(it)=='c'){
							ls.erase(std::next(it));
							ls.erase(std::prev(it)); // must be 'p'
							cntl--;
						}
						else{
							goto _cont;
						}
					}
					goto _brk2;
				}
				case 'p':{
					++it;
					++cntl;
				}break;
			}
		}
		_brk2:;
		if(ls.empty() || (std::next(ls.begin())==ls.end()&&ls.front()=='h')){
			cout<<"Yes\n";
		}
		else{
			cout<<"No\n";
		}
		continue;
		_cont:
		cout<<"No\n";
	}
	return 0;
}

/*
p	c	l	r	h=pc
pl	pr	pch	pp/
clc	crc	cc/	cp-
lll	lrh	lc	lpp
rlh	rrr	rc	rpp

ppp	ppl	ppr	pph
ccc	lcc	rcc hcc
-> 	plc	prc	phc
*/
/*
12
l
lr
ppc
cppc
lllpc
lllplrrpcc
lllplrrprrcc
pcllpllcllpllc
pcllpllcllplrc
pcllpllcllprpcc
ppccrrprrcrrpc
ppccrrprrcrr

No
Yes
No
Yes

Yes
Yes
No
No
pcllpllcllplrc:
phc
No
Yes
Yes
Yes
*/