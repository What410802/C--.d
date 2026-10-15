#include<iostream>
using std::cin; using std::cout; constexpr auto LF='\n';
#include<iomanip>
#include<string>
#include<vector>
#define vec std::vector

// #include<random>
// std::random_device rd;
// std::mt19937_64 gen(rd());
#include<bitset>

#include<numeric>
using std::min, std::max;
using uch = unsigned char; using ch = char;
using ush = unsigned short;
using uint = unsigned int;
using ull = unsigned long long; using ll = long long;

#define MOD 998244353u
#define NC 16
#define M 5009
uint n,m,k;
uint price[NC][M];
ull dist[NC+1][NC+1]; // dist >=1
ull tsp[1<<NC][NC]; // travel through mask, stay at i
// uint cheapest[M][1<<NC];
ull purchase[1<<NC];

template<typename T>
bool mize(T &a, const T &b){
	if(a>b){
		a=b;
		return true;
	}
	return false;
}

int main(){
	std::ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	{
		cin>>n>>m>>k;
		for(uint i=0;i<n;i++){
			for(uint j=0;j<m;j++){
				cin>>price[i][j];
			}
		}
		uint u,v,w;
		for(uint i=0;i<k;i++){
			cin>>u>>v>>w; --u; --v;
			dist[u][v]=dist[v][u]=w;
		}
	}
	// make shortest path:
	for(uint k=0;k<=n;k++){
		for(uint i=0;i<=n;i++){
			if(i!=k&&dist[i][k]==0){
				continue;
			}
			for(uint j=0;j<=n;j++){
				if(k!=j&&dist[k][j]==0){
					continue;
				}
				if(i==j) continue; // stay 0
				if(const auto shrt=dist[i][k]+dist[k][j]; dist[i][j]==0 || dist[i][j]>shrt){
					dist[i][j] = shrt;
				}
			}
		}
	}
// for(uint i=0;i<=n;i++){
// 	for(uint j=0;j<=n;j++){
// 		cout<<"dist["<<i<<"]["<<j<<"]="<<dist[i][j]<<'\t';
// 	}
// 	cout<<LF;
// }
	// tsp
	const uint Tttn=1u<<n;
	for(uint ipos=0;ipos<n;ipos++){
		tsp[1u<<ipos][ipos] = dist[n][ipos]; // ~include zero~ <- impossible here
	}
	for(uint imask=1;imask<Tttn;imask++){
		for(uint ipos=0;ipos<n;ipos++){
			if(!(1u<<ipos & imask)) continue; // ipos will be the end
			if(tsp[imask][ipos]==0) continue;
			for(uint jpos=0;jpos<n;jpos++){
				if(1u<<jpos & imask) continue;
				// if(dist[ipos][jpos]==0) continue; // not possible here, unless ipos==jpos
				if(auto shrt=tsp[imask][ipos]+dist[ipos][jpos], &targ=tsp[imask|1u<<jpos][jpos]; targ==0||targ>shrt){
					targ=shrt;
				}
			}
		}
	}
	// make smallest purchase cost
	{
		purchase[0x0]=~0ull;
		uint purchj_mask[1u<<NC];
		for(uint j=0;j<m;j++){
			purchj_mask[0x0]=~0u;
			for(uint ipos=0;ipos<n;ipos++){
				purchj_mask[1u<<ipos] = price[ipos][j];
			}

			for(uint imask=1;imask<Tttn;imask++){
				const uint ipos=__builtin_ctz(imask);
				purchj_mask[imask] = std::min(purchj_mask[imask^(1u<<ipos)], price[ipos][j]);

				purchase[imask]+=purchj_mask[imask];
			}
		}
	}
	// synthesize
	ull ans=~0ull;
	for(uint imask=1;imask<Tttn;imask++){
		for(uint ipos=0;ipos<n;ipos++){
			if(!(imask&(1u<<ipos))) continue;
			ull maskans=tsp[imask][ipos]+dist[n][ipos]+purchase[imask];
			mize(ans, maskans);
// cout<<"tsp["<<std::bitset<17>(imask)<<"]["<<ipos<<"]="<<tsp[imask][ipos]<<LF;
// // cout<<"cheapest["<<j<<"]["<<std::bitset<17>(imask)<<
// cout<<"maskans="<<maskans<<LF;
		}
	}
	cout<<ans<<LF;
	return 0;
}
/*
2 2 3
5 22
6 15
1 2 1
1 3 103
2 3 102

2 5 3
5 22 155 5 21
6 15 167 10 24
1 2 3
1 3 103
2 3 102
*/
/*
225

409
*/