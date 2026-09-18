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

#define MOD 998244353u
#define N 100009
uint n;
vec<uint> nx[N];

uint fact[N], twos[N];
uint qpow(ull a, uint t){
	ull ret=1;
	while(t){
		if(t&1){
			(ret*=a)%=MOD;
		}
		(a*=a)%=MOD; t>>=1;
	}
	return ret;
}
uint get_rev(ull in){
	return qpow(in, MOD-2);
}

uint get_node_n(uint sz){
	ull ret=1;
	// 
	if(sz&1){
		ret=sz; sz--;
	}
	// sz even
	// ret*= C_sz^2 C_(sz-2)^2 ... C_2^2 / (sz/2)!
	//     = sz*(sz-1)/2 (sz-2)(sz-3)/2 ... 2/2 / (sz/2)!
	//     = sz! / 2^(sz/2) (sz/2)!
	(ret*= (ull)fact[sz] * get_rev((ull)twos[sz>>1] * fact[sz>>1] %MOD) %MOD)%=MOD;
	return ret;
}

int main(){
	std::ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	fact[0]=1; twos[0]=1;
	for(uint i=1;i<N;i++){
		fact[i]=(ull)fact[i-1]*i %MOD;
		twos[i]=((ull)twos[i-1]<<1)%MOD;
	}
	uint t; cin>>t;
	uint u,v;
	while(t--){
		cin>>n;
		for(uint e=1;e<n;e++){
			cin>>u>>v;
			nx[u].push_back(v);
			nx[v].push_back(u);
		}
		// std::uniform_int_distribution<> dist(1, n);
		// cout<<dist(rd)<<"#\n";
		ull ans=1;
		for(uint i=1;i<=n;i++){
			(ans*=get_node_n(nx[i].size()))%=MOD;
		}
		cout<<ans<<LF;
		for(uint i=1;i<=n;i++){
			nx[i].clear();
		}
	}
	return 0;
}
/*
3
3
1 2
2 3
7
1 4
5 3
2 4
1 6
4 3
3 7
10
1 5
5 2
2 10
5 8
1 4
5 6
4 3
2 7
9 5

1
9
45
*/