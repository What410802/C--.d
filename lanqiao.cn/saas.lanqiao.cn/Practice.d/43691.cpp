#include<iostream>
using std::cin, std::cout, std::endl;
#include<list>
// #include<unordered_set>
#include<tuple> // OJ compiler need this
#include<set>
using uint = unsigned int;
using ull = unsigned long long;
using ll = long long;
using uch = unsigned char;
#define _ noexcept

using cards = std::list<char>;
cards as[2],pub; // front is close to humans
bool turn; // false: as[0]; true: as[1]
std::set<std::tuple<bool,cards,cards,cards>> hsh; // DO NOT forget the bool!

void in(cards &a)_{
	char c;
	while(cin.get(c) && c!='\n'){
		a.emplace_back(c);
	}
}
void out(const cards &a)_{
	for(const auto c:a){
		cout.put(c);
	}
	cout<<endl;
}

int main()_{
	std::ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	in(as[0]);
	in(as[1]);
	for(;;){
out(as[0]); out(as[1]); out(pub); cout<<'#'<<endl; 
		if(as[0].empty() || as[1].empty()){
			out(as[0].empty() ? as[1] : as[0]);
			return 0;
		}
		// proceed
		pub.splice(pub.begin(), as[turn], as[turn].begin());
		// check
		if(pub.empty()){ // nf1
			turn = !turn;
			continue;
		}
		auto same_at = ++pub.begin();
		if(same_at == pub.end()){ // nf2
			turn = !turn;
			continue;
		}
		for(;;++same_at){
			if(same_at == pub.end()){
				// not found 3
				turn = !turn;
				break;
			}
			if(*same_at == pub.front()){
				// found
				as[turn].splice(as[turn].end(), pub, pub.begin(), ++same_at);
				break;
			}
		}
		if(!hsh.emplace(turn,as[0],as[1],pub).second){
			cout<<"-1"<<endl;
			return 0;
		}
	}
	return 0;
}