/*#include<iostream>
#include<vector>
#include<random>
#include<array>
using std::cin, std::cout, std::endl;
// #include<cstdio>
typedef unsigned int uint;
typedef unsigned long long ull;
typedef long long ll;
typedef unsigned char uchar;

#define N 1001
#define K 102
#define MOD 1000000007u
bool a[N];
std::vector<uint> nx[N];
uint fa[N];
uint n,k,root;
void inline make_fa(const uint curr, const uint prev){
	for(const uint nx:nx[curr]){
		if(nx==prev){
			continue;
		}
		fa[nx]=curr;
		make_fa(nx, curr);
	}
}

uint dead_ans=0;
std::array<uint,K> inline collect_sub(const uint curr){
	std::array<uint,K> ret; ret.fill(0);
	for(const uint nx:nx[curr]){
		if(nx==fa[curr]){
			continue;
		}
		const auto subret=collect_sub(nx);
		(dead_ans+=subret[k])%=MOD; // Not selecting curr.
// printf("subret @(curr=%u) =",curr);
// for(uint i=0;i<=k;i++){
// 	printf("%u,",subret[i]);
// }
// printf("\n");
		if(a[curr]){
			for(uint ik=0;ik<k;ik++){
				for(uint jk=0;ik+jk<k;jk++){
					(ret[ik+jk+1]=ret[jk]+subret[ik])%=MOD;
				}
			}
		}
		else{
			for(uint ik=0;ik<=k;ik++){
				for(uint jk=0;ik+jk<=k;jk++){
					(ret[ik+jk]=ret[jk]+subret[ik])%=MOD;
				}
			}
		}
	}
	(++ret[a[curr]])%=MOD;
// printf("ret @(curr=%u) =",curr);
// for(uint i=0;i<=k;i++){
// 	printf("%u,",ret[i]);
// }
// printf("\n");
	return ret;
}

int main(){
	cin.tie(0);
	std::ios::sync_with_stdio(false);
	cin>>n>>k;
	for(uint i=0;i<n;i++){
		cin>>a[i];
	}
	uint u,v;
	for(uint i=1;i<n;i++){
		cin>>u>>v; --u;--v;
		nx[u].push_back(v);
		nx[v].push_back(u);
	}
	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_int_distribution<uint> dist(0, n-1);
	root=dist(gen);
	fa[root]=n;
	make_fa(root, n);
// printf("root: %u\n",root);
// for(uint i=0;i<n;i++){
// 	printf("fa[%u]:%u\n",i,fa[i]);
// }

	const auto ans = collect_sub(root);
	cout<<(ans[k]+dead_ans)%MOD<<endl;
	return 0;
}*/
/*
3 1
1 0 1 
1 2
1 3
*/
#include<iostream>
#include<vector>
#include<cstring>
using namespace std;

const int MOD = 1e9+7;
const int N=1005;
const int K=105;

int n,k;
int a[N];
vector<int> adj[N];
int dp[N][K];
int ans[K];
int tmp[K];

void dfs(int u, int parent){
	dp[u][a[u]]=1;
	
	for(int v: adj[u]) {
		if(v==parent)
			continue;
		
		dfs(v,u);
		memset(tmp,0,sizeof(tmp));
		
		for(int i=0;i<=k;i++){
			if(dp[u][i]==0)continue;
			for(int j=0;j<=k-i;j++){
				if(dp[v][j]==0)continue;
				tmp[i+j]=(tmp[i+j]+1LL*dp[u][i]*dp[v][j])%MOD;
			}
		}
		
		for(int i=0;i<=k;i++){
			dp[u][i]=(dp[u][i]+tmp[i])%MOD;
		}
	}
	ans[k]=(ans[k]+dp[u][k])%MOD;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	
	for(int i=1;i<n;i++){
		int u,v;
		cin>>u>>v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	dfs(1,0);
	
	cout<<ans[k]<<endl;
	return 0;
}