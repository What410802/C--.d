#include<iostream>
using std::cin; using std::cout; constexpr auto LF='\n';
#include<iomanip>
#include<string>
#include<vector>
#define vec std::vector

// #include<random>
// std::random_device rd;
// std::mt19937_64 gen(rd());

#include<numeric>
using std::min, std::max;
using uch = unsigned char; using ch = char;
using ush = unsigned short;
using uint = unsigned int;
using ull = unsigned long long; using ll = long long;

// #define MOD 998244353u
#define N 1000009
uint n;
vec<uint>nx[N];
typedef std::pair<uint,uint> Edge;
vec<Edge>uedges;
uint onedegneighbor[N];
// uint dis[N];
// // uint vdis[N]; // value domain count. max at N
// uint disisodd[2];
// void mkdis(uint at,uint fa){
// 	for(const auto child:nx[at]){
// 		if(child==fa){
// 			continue;
// 		}
// 		dis[child]=dis[at]+1;
// 		// vdis[dis[child]]++;
// 		disisodd[dis[child]&1]++;
// 		mkdis(child,at);
// 	}
// }
ull Cn2(uint n){
	return (ull)n*(n-1)>>1;
}

int main(){
	std::ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	uint t; cin>>t;
	while(t--){
		cin>>n;
		uint u,v;
		for(uint i=1;i<n;i++){
			cin>>u>>v;
			nx[u].push_back(v);
			nx[v].push_back(u);
			uedges.emplace_back(u,v);
		}
		// dis[1]=0; disisodd[0]++;
		// mkdis(1,0);
		// // disisodd is ready
		// // now we need to get those dis-to-root diff is even
		// cout<<Cn2(disisodd[0])+Cn2(disisodd[1])<<LF;

		// Actually, only dis==1 and dis==3(some of) point pairs are not qualified.
		ull nans=0;
		// for(uint at=1;at<=n;at++){
		// 	for(const auto atanx:nx[at]){
		// 		if(atanx>=at){ // routine
		// 			continue;
		// 		}
		// 		if(nx[atanx].size()>1){ // after excluding 'at', it still has a root point. This should guarantee that there aren't any extension point on atnx side, so atnx < at.
		// 			goto _out_cont;
		// 		}
		// 	}

		// 	for(const auto atnx:nx[at]){
		// 		if(atnx>=at){ // routine
		// 			continue;
		// 		}
		// 		nans+=ull(nx[at].size()-1)*(nx[atnx].size()-1); // dis==3 pairs
		// 	}
		// 	_out_cont:;
		// }
		// // Fail2: TLE
		// for(const Edge& uedge:uedges){
		// 	uint bad3_can1=0, bad3_can2=0;
		// 	for(const auto at1nx:nx[uedge.first]){
		// 		if(at1nx==uedge.first)continue;
		// 		if(nx[at1nx].size()<=1){
		// 			bad3_can1++;
		// 		}
		// 	}
		// 	for(const auto at2nx:nx[uedge.second]){
		// 		if(at2nx==uedge.second)continue;
		// 		if(nx[at2nx].size()<=1){
		// 			bad3_can2++;
		// 		}
		// 	}
		// 	nans+=(ull)bad3_can1*bad3_can2;
		// }
		// nans>>=1; // swappable
		// 3:
		for(uint i=1;i<=n;i++){
			if(nx[i].size()==1){
				onedegneighbor[nx[i][0]]++;
			}
		}
		for(const Edge& uedge:uedges){
			nans+=(ull)onedegneighbor[uedge.first]*onedegneighbor[uedge.second];
		}
		nans+=n-1;
		cout<<Cn2(n)-nans<<LF;

		for(uint i=1;i<=n;i++){
			nx[i].clear();
			// vdis[i]=0;
			onedegneighbor[i]=0;
		}
		uedges.clear();
		// disisodd[0]=0; disisodd[1]=0;
	}
	return 0;
}
/*
6
3
2 1
3 2
4
1 2
3 2
2 4
7
7 3
6 5
3 1
1 2
1 5
5 4
9
4 5
5 9
2 8
5 1
3 8
8 9
8 6
6 7
10
3 8
3 2
9 7
4 3
6 1
5 2
3 6
3 7
6 10
10
4 6
3 7
10 8
3 5
2 8
6 10
1 2
5 9
8 9

1
3
12
26
28
36
*/