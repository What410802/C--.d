#include<cstdio>
typedef unsigned int uint;
typedef unsigned long long ull;
typedef long long ll;

#define N 2002
uint n,m;
bool f[N][N];
uint ans=0;

int main(){
	scanf("%u%u", &n, &m);
	for(uint i=0;i<n;i++){
		f[i][i]=true;
	}
	for(uint i=0,a,b;i<m;i++){
		scanf("%u%u",&a,&b); a--;b--;
		f[a][b]=true;
		for(uint pre=0;pre<n;pre++){
			if(f[pre][a]){
				// if(!f[pre][b]){
				// 	printf("#Updated f[%u][%u] using f[][%u]\n",pre,b,a);
				// }
				for(uint post=0;post<n;post++){ // find after
					if(f[b][post]){
						f[pre][post]=true;
					}
				}
			}
		}
	}
	// for(uint i=0;i<n;i++){
	// 	for(int k=0;k<n;k++){
	// 		if(k==i){
	// 			continue;
	// 		}
	// 		for(int j=n-1;j>=0;j--){
	// 			if(j==k || j==i){
	// 				continue;
	// 			}
	// 			f[i][j]=f[i][j]||(f[i][k]&&f[k][j]);
	// 			printf("#Using f[%u][%u]==%u&&f[%u][%u]==%u to update f[%u][%u]=%u\n",i,k,f[i][k], k,j,f[k][j], i,j,f[i][j]);
	// 		}
	// 	}
	// }
	for(uint i=0;i<n;i++){
		for(uint j=0;j<n;j++){
			if(f[i][j]){
				// printf("#Connect: f[%u][%u]\n",i,j);
				ans++;
			}
		}
	}
	printf("%u\n",ans);
	return 0;
}