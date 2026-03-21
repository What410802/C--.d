#include<iostream>
using std::cin, std::cout, std::endl;
#include<string>
#include<list>
using uint = unsigned int;
using ull = unsigned long long;
using ll = long long;
using uch = unsigned char;
#define _ noexcept

class Piece{
	public:
	char c;
	uint l;
	Piece(const char c_out, const uint l_out)_: c(c_out), l(l_out){}
	bool len_odd() const _{
		return l&1;
	}
	bool is_01() const _{
		return c!='?';
	}
	bool is_q() const _{
		return c=='?';
	}
};
std::list<Piece>pcs;

int main()_{
	std::ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	std::string s; cin>>s;
	char curr = '\0';
	for(const char c:s){
		if(c==curr){
			pcs.back().l++;
		}
		else{
			pcs.emplace_back(c, 1);
			curr = c;
		}
	}
	auto it0 = pcs.begin(), it1 = ++pcs.begin();
	if(it1 == pcs.end()){ // pcs.length() == 1
		cout<<it0->l / 2<<endl; // Whether 0, 1, or ?
		return 0;
	}
	auto it2 = ++ ++pcs.begin();
	if(it2 == pcs.end()){ // pcs.length() == 2
		cout<<((it0->is_q() || it1->is_q()) ? (it0->l + it1->l)/2 : it0->l/2 + it1->l/2)<<endl; // They won't be the same char. : ...
		return 0;
	}
	for(;it2!=pcs.end();){
		if(it1->is_q() && it0->c == it2->c){ // This will avoid the condition that the front or the back is a q.
			it0->l += it1->l + it2->l;
			it1 = pcs.erase(it1); // == it2
			it2 = pcs.erase(it2);
		}
		else{
			++it0,++it1,++it2;
		}
	}
	// it0 -- it1 -- end()
	if(it1->is_q()){ // The back is a q
		it0->l += it1->l;
		pcs.erase(it1);
	}
	if(pcs.begin()->is_q()){ // The front is a q
		(++pcs.begin())->l += pcs.begin()->l;
		pcs.erase(pcs.begin());
	}
	/* Now, the conditions include:
		- 0..0 / 1..1 ; 0..0 1..1 / 1..1 0..0 : .l>=1, does not contain ?..?
		- 0..0 ?..? 1..1 ... 1..1 or so : .l>=3, ?..? are always in the internal and have different bits on each's 2 sides
	*/
	for(it1 = pcs.begin(); it1 != pcs.end(); ++it1){
		if(it1->is_q()){
			goto _still_need_efforts;
		}
	}
	goto _we_win;
	_still_need_efforts:;
	
	_we_win:; // Now there are only 0..0 / 1..1
	uint ans=0;
	for(it1 = pcs.begin(); it1 != pcs.end(); ++it1){
		ans+=it1->l/2;
	}
	cout<<ans<<endl;
	return 0;
}