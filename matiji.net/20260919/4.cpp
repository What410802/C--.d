#include<iostream>
using std::cin, std::cout; constexpr auto LF='\n';

#include<vector>
#define vec std::vector
#include<string>
// #include<list>
// #include<iterator>
#include<numeric>
#include<unordered_set>

#define MOD
#define N 200009

using uint=unsigned int;
using ull=unsigned long long; using ll=long long;
uint n,k;
uint c[N],w[N];
uint mini[N],maxi[N]; // beg rbegin page. c[i]->i
struct Arxv{
	uint beg, rbeg;
	ull pages=0;
	std::unordered_set<uint> cs; // c[i]
};
vec<Arxv> arxvs;

bool minvolscan(ull maxpagen){ // ordered arxv is required.
	ull currpagen=0;
	uint vols=1;
	for(const auto& arxv:arxvs){
		currpagen+=arxv.pages;
		if(currpagen>maxpagen){
			if(arxv.pages>maxpagen){ // !
				return false;
			}
			vols++; currpagen=arxv.pages; // move to the new vol
		}
	}
// cout<<"#Tested: "<<maxpagen<<", "<<vols<<(vols<=k?"<=":">")<<k<<LF;
	return vols<=k;
}

int main(){
	std::ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	cin>>n>>k;
	ull totpages=0;
	for(uint i=1;i<=n;i++){
		cin>>c[i]>>w[i];
		if(mini[c[i]]==0){
			mini[c[i]]=i;
		}
		maxi[c[i]]=i;
		totpages+=w[i];
	}
// for(uint i=1;i<=n;i++){
// 	if(c[i])
// 	cout<<"$"<<mini[c[i]]<<' '<<maxi[c[i]]<<LF;
// }
	arxvs.push_back({1,maxi[c[1]],w[1],{c[1]}}); // mini[c[1]]=1.
	for(uint i=2;i<=n;){
		auto& last=arxvs.back();
		// auto& lastcs=last.cs;
		for(;i<=last.rbeg;i++){ // fast forwarding
			last.cs.insert(c[i]);
			last.rbeg=std::max(last.rbeg, maxi[c[i]]); // extension
			last.pages+=w[i];
		}
		if(i>n){
			break;
		}
		arxvs.push_back({i, maxi[c[i]], w[i], {c[i]}});
		i++;
	}
	if(arxvs.size()<k){
		cout<<"-1"<<LF;
	}
	else{
		// middling
		ull l=0,r=totpages,midd; // l always in noway; r always in can
		while(l+1<r){
			midd=(l+r)>>1;
			if(!minvolscan(midd)){ // should lift pagemaxlimit
				l=midd;
			}
			else{
				r=midd;
			}
// cout<<"#"<<"minvolscan(midd="<<midd<<")="<<(minvolscan(midd)?".T":".F")<<LF;
		} // l cannot; r can; l+1==r
		cout<<r<<LF;
	}
// for(const auto& arxv:arxvs){
// 	cout<<"$"<<arxv.beg<<' '<<arxv.rbeg<<' '<<arxv.cs.size()<<' '<<arxv.pages<<LF;
// }
	return 0;
}
/*
8 3
1 2
2 1
1 3
3 4
4 2
4 5
5 1
6 6

5 3
1 1
2 1
1 1
2 1
3 1
*/
/*

*/