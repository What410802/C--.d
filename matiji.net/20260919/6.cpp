#include<iostream>
using std::cin, std::cout; constexpr auto LF='\n';

#include<vector>
#define vec std::vector
#include<string>
// #include<list>
// #include<iterator>
#include<numeric>

#define MOD
#define N 200009

using uint=unsigned int;
using ull=unsigned long long; using ll=long long;
uint n;
// std::list<int>a;
vec<int>a;
ll get6m1(decltype(a)::iterator at){
	int minis=2147483647;
	ll sum=0;
	for(auto it=at;it<at+6;++it){
		if(*it<minis){
			minis=*it;
		}
		sum+=*it;
	}
	return sum-minis;
}
template<typename Tit>
ll get4(Tit at){
	ll ret=0;
	for(auto it=at;it<at+4;++it){
		ret+=*it;
	}
	return ret;
}

int main(){
	std::ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	uint t; cin>>t;
	int in;
	while(t--){
		cin>>n;
		for(uint i=0;i<n;i++){
			cin>>in;
			a.push_back(in);
		}
		// throw out. This does not manage n==5.
		ll max6m1=1ll<<63;
		for(auto it=a.begin();it+5<a.end();++it){
			if(const auto it6m1=get6m1(it); it6m1>max6m1){
				max6m1=it6m1;
			}
		}
		// insert hist max left
		ll maxlhist=1ll<<63;
		int lmax=a[0];
		for(auto it=a.begin()+1;it+3<a.end();){
			if(const auto itlhist=lmax+get4(it); itlhist>maxlhist){
				maxlhist=itlhist;
			}
			lmax=std::max(lmax, *it);
			it++;
		}
		// insert hist max right
		ll maxrhist=1ll<<63;
		int rmax=a[n-1];
		for(auto it=a.rbegin()+1;it+3<a.rend();){
			if(const auto itrhist=rmax+get4(it); itrhist>maxrhist){
				maxrhist=itrhist;
			}
			rmax=std::max(rmax, *it);
			it++;
		}
		cout<<std::max(max6m1, std::max(maxlhist, maxrhist))<<LF;
// cout<<"$"<<max6m1<<" "<<maxlhist<<' '<<maxrhist<<LF;
		a.clear();
	}
	return 0;
}
/*
3
5
3 -4 6 1 2
6
100 100 -100 100 100 100
10
50 -100 -100 4 4 4 4 -100 -100 -100

1
8
100 0 0 0 25 25 25 24
-> 125 x; 199 v
9
100 0 0 0 25 25 25 24 100
-> 299-25=274
2
5
1 2 4 8 16
5
-1 -2 -4 -8 -16
*/
/*
8
500
66
*/