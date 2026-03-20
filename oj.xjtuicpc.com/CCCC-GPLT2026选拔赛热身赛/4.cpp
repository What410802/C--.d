#include<iostream>
using std::cin, std::cout, std::endl;
#include<sstream>
#include<string>
#include<vector>
#include<algorithm>
#include<queue>
#include<set>
using uch = unsigned char;
using ush = unsigned short;
using uint = unsigned int;
using ull = unsigned long long;
using ll = long long;
#define _ noexcept

uint m,n;
struct exam{
	std::string name;
	uint beg, end, req;
	bool static precede(const exam &self, const exam &oth)_{
		return self.beg < oth.beg;
	}
	bool static more_emerg(const exam &self, const exam &oth)_{
		return self.end < oth.end || (self.end == oth.end && self.name < oth.name); // unique
	}
};
// bool sub_more_emerg(const exam *a, const exam *b)_{
// 	return a->more_emerg(*b);
// }

std::vector<exam> in;

bool sub_more_emerg(const decltype(in)::iterator a, const decltype(in)::iterator b)_{
	return exam::more_emerg(*a, *b);
}

std::set<decltype(in)::iterator, decltype(&sub_more_emerg)> q(sub_more_emerg), finished(sub_more_emerg); // ptr
std::vector<uint> prepared;

int main()_{
	std::ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	cin>>m>>n;
	in.resize(n); prepared.resize(n);
	for(uint i=0;i<n;i++){
		auto &ini = in[i];
		cin>>ini.name>>ini.beg>>ini.end>>ini.req;
	}
	std::sort(in.begin(), in.end(), exam::precede); // `prepared` according to this.
	decltype(in)::iterator nx=in.begin();

	std::ostringstream myout;
	for(uint today=1;today<=m;today++){ // every day
		/*
		a1	2	5	3
		a2	3	5	1
		a3	3	4	1
		*/
		for(;nx->beg == today; ++nx){
			q.insert(nx);
		}
		if(!q.empty() && (*q.begin())->end == today){ // not finished
// cout<<myout.str()<<'\n';
			cout<<"DIE"<<'\n';
			return 0;
		}
		if(!finished.empty() && (*finished.begin())->end == today){ // ensured end_i is diff from each other.
			myout<<"EXAM"<<'\n';
			finished.erase(finished.begin());
			continue;
		}
		if(q.empty()){
			myout<<"REST"<<'\n';
			continue;
		}
		// no exam and not empty
		const auto curr = *q.begin() - in.begin();
		myout<<(*q.begin())->name<<'\n';
		prepared[curr]++;
		if(prepared[curr] == (*q.begin())->req){
			finished.insert(q.extract(q.begin()));
		}
	}
	cout<<myout.str();
	return 0;
}