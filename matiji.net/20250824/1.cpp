typedef unsigned char ubyte;
typedef unsigned int uint;
typedef unsigned long long ull;
typedef long long ll;

#include<cstdio>

#define N 500002
int d[N];

int main(){
	uint n,q;
	scanf("%u%u",&n,&q);
	for(uint i=1;i<=n;i++){
		scanf("%u",&d[i]);
	}
	uint opt,i,v;
	while (q--)
	{
		scanf("%u%u%u",&opt,&i,&v);
		if(opt==1){
			d[i]+=v;
		}
		else{
			d[i]-=v;
		}
	}
	for(uint i=1;i<=n;i++){
		printf("%d ",d[i]);
	}
	return 0;
}