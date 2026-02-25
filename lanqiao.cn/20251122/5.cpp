#include<iostream>
#include<set>
using std::cin, std::cout, std::endl;
// #include<cstdio>
typedef unsigned int uint;
typedef unsigned long long ull;
typedef long long ll;
typedef unsigned char uchar;

class prefix_timepiece{
	public:
	int n; // how many people changed
	uint t;

	bool inline operator<(const prefix_timepiece &oth) const {
		return t<oth.t;
	}
	bool inline operator==(const prefix_timepiece &oth) const {
		return t==oth.t;
	}
};
std::set<prefix_timepiece> timeline;
void inline ins_timeline(const prefix_timepiece &in){
	const auto fnd=timeline.lower_bound(in);
	if(fnd == timeline.end() || fnd->t != in.t){
		timeline.insert(in);
	}
	else{
		const prefix_timepiece ins={fnd->n+in.n, fnd->t};
		timeline.erase(fnd);
		if(ins.n){
			timeline.insert(ins);
		}
	}
}

#define N 100001
uint ans[N];

int main(){
	cin.tie(0);
	std::ios::sync_with_stdio(false);
	uint n;
	cin>>n;
	uint l,r;
	for(uint i=0;i<n;i++){
		cin>>l>>r;
		ins_timeline({1, l}); // So, when using, first calc sum, then do oth
		ins_timeline({-1, r+1});
	}
	uint people=0;
	for(const auto &timepoint:timeline){
		people+=timepoint.n;
		if(!ans[people]){
			ans[people]=timepoint.t;
		}
	}
	for(uint i=1;i<=n;i++){
		if(ans[i]){
			cout<<ans[i]<<endl;
		}
		else{
			cout<<"-1"<<endl;
		}
	}
	return 0;
}