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
#define N 500009
uint n,k;
bool sneg[N];
uint dp[N][3]; // after i, which value has how many solutions

int main(){
	std::ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	uint t; cin>>t;
	int in;
	while(t--){
		cin>>n>>k;
		for(uint i=1;i<=n;i++){
			cin>>in;
			sneg[i]=in==-1;
		}
		/* i+1       i (after)
		//    pm1(pm k) k-1,k->pm1,0
		//    0         0,1->0,pm1
		   +1(+k)    if sneg, then k-1,k -> +1,0; else /
		   0         0,1 -> 0,if sneg, then -1; else +1
		   -1(-k)    if sneg, then /; else k-1,k -> -1,0
		*/
		dp[n+1][0]=1;
		dp[n+1][1]=0;
		dp[n+1][2]=0;
		for(uint i=n;i>=1;i--){
			#define _1 2 // -1: 2
			if(sneg[i]){
				dp[i][1]=dp[i+1][1];
				dp[i][0]=dp[i+1][1]+dp[i+1][0];
				dp[i][_1]=dp[i+1][0];
			}
			else{
				dp[i][1]=dp[i+1][0];
				dp[i][0]=dp[i+1][_1]+dp[i+1][0];
				dp[i][_1]=dp[i+1][_1];
			}
			dp[i][0]%=MOD;
			#undef _1
		}
		cout<<dp[1][0]<<LF;
	}
	return 0;
}
/*
2
5 2
-1 1 1 -1 -1
8 100
1 1 -1 -1 -1 -1 1 -1

5
16
*/