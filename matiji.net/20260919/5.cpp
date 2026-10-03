#include<iostream>
using std::cin, std::cout; constexpr auto LF='\n';

#include<vector>
#define vec std::vector
#include<string>
// #include<list>
// #include<iterator>
#include<numeric>

#define MOD 1000000007u
#define N 5009
#define K 5009

using uint=unsigned int;
using ull=unsigned long long; using ll=long long;
uint n,k;
vec<uint> nx[N];
// uint cld[2][N];

// ull dfs(uint at, uint remk, bool contself){ // remk contains self
// 	ull ret=0;
// 	if(contself){
// 		for(uint lk=0;lk<remk;lk++){
// 			// choose root itself
// 			(ret+=dfs(cld[0][at], lk, true)*dfs(cld[1][at], remk-1-lk, true)%MOD)%=MOD;
// 		}
// 		return ret;
// 	}
// 	else{
// 		for(uint child=)
// 	}
// }
ull solsk[N][K][2]; // bottom-up. which, consumes, contself
ull solsN[N][K][2];
ull mk_sols(uint at, uint fa){
	for(const auto& child:nx[at]){
		if(child==fa)continue;
		mk_sols(child, at);
		for(uint atk=1;atk<=k;atk++){
			solsN[at][atk][1]*=solsN[child][atk][1];
		}
	}
}

int main(){
	std::ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	cin>>n>>k;
	uint u,v;
	for(uint i=1;i<n;i++){
		cin>>u>>v;
		nx[u].push_back(v);
		nx[v].push_back(u);
	}
	uint root=1;
	ull ans=dfs()+dfs();
	cout<<dfs()<<LF;
	return 0;
}
/*

*/
/*

*/