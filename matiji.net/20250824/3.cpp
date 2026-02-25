typedef unsigned char ubyte;
typedef unsigned int uint;
typedef unsigned long long ull;
typedef long long ll;

#include<cstdio>

#define N 500002
uint n;
ull m;
uint a[N];

inline ull get_sum_a(ull deno){
	ull sum=0;
	for(uint i=0;i<n;i++){
		sum+=a[i]/deno;
	}
	return sum;
}

inline ull get_ans(ull l,ull r){
	// printf("#%llu %llu\n",l,r);
	ull mid=(l+r)>>1;
	ull perf;
	while (l+1<r)
	{
		perf=get_sum_a(mid);
		if(perf<=m){
			r=mid;
			// printf("#1: %llu\n",r);
		}
		else{
			l=mid+1;
			// printf("#2: %llu\n",l);
		}
		mid=(l+r)>>1;
	}
	return l+1==r&&get_sum_a(l)<=m?l:r;
}

int main(){
	uint t,i;
	ull sum;
	scanf("%u",&t);
	while(t--){
		scanf("%u%llu",&n,&m);
		for(i=0,sum=0;i<n;i++){
			scanf("%u",&a[i]);
			sum+=a[i];
		}
		printf("%llu\n",get_ans(1,sum/m+1));
	}
	return 0;
}