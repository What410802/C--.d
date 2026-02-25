#include<iostream>
#include<set>
#include<algorithm>
using std::cin, std::cout, std::endl;
typedef unsigned int uint;
typedef unsigned long long ull;
typedef long long ll;

class drug{ // The worse, the fronter
	public:
	uint a,b;
	bool inline operator<(const drug &oth) const {
		return a>oth.a || (a==oth.a && b<oth.b); // b won't be used
	}
	bool inline operator==(const drug &oth) const {
		return a==oth.a && b==oth.b;
	}
	bool inline abs_no_better_than(const drug &oth) const {
		return a>=oth.a && b<=oth.b;
	}
};
#define N 100002
drug in[N];
std::set<drug> ds;

int main(){
	cin.tie(0);
	std::ios::sync_with_stdio(false);
	uint n;
	cin>>n;
	for(uint i=0;i<n;i++){
		cin>>in[i].a>>in[i].b;
	}
	std::sort(in, in+n);
	ds.insert(in[n-1]);
	for(int i=n-2, lastgood=n-1;i>=0;i--){
		if(in[i].abs_no_better_than(in[lastgood])){
			continue;
		}
		lastgood=i;
		ds.insert(in[i]);
	}
	uint q;
	cin>>q;
	uint x;
	while(q--){
		cin>>x;
		const auto loc=ds.lower_bound(drug{x, 0});
		if(loc == ds.end()){
			cout<<"-1"<<endl;
		}
		else{
			cout<<loc->b<<endl;
		}
	}
for(const auto i: ds){
	cout<<"#"<<i.a<<' '<<i.b<<endl;
}
	return 0;
}