#include<cstdio>
#include<cmath>
typedef unsigned int uint;
typedef unsigned long long ull;
typedef long long ll;

#define N 200002
uint n,npref;
uint ni[N];
ull pref[N*2];
ull maxs[N*3][log2(N)+1];
ull query(uint a,uint b){
	if(b-a==1){
		return max(pref[a],pref[b]);
	}
	if(log2(a)!=log2(b)){
		
	}
	for(;)
}

ull ans=-1e9;

int main(){
	scanf("%u",&n);
	npref=n<<1;
	for(uint i=0;i<n;i++){
		scanf("%u",ni+i);
	}
	maxs[i][0]=pref[0]=ni[0];
	for(uint i=1;i<n;i++){
		pref[i]=pref[i-1]+ni[i]; // ull by default
		maxs[i][0]=pref[i];
	}
	for(uint i=0;i<n;i++){
		pref[n+i]=pref[n+i-1]+ni[i];
		maxs[i][0]=pref[i];
	}

	uint bits=log2(npref);
	for(uint i=1;i<bits;i++){
		uint step=1<<bits;
		for(uint j=0;j<npref;j+=step){
			maxs[j][i]=max(maxs[j][i-1], maxs[j+(step>>1)][i-1]);
		}
	}
	for(uint i=0;i<n-1;i++){
		ans=max(ans,query(i+1,i+n)-pref[i]);
	}
	printf("%llu\n",ans);
	return 0;
}