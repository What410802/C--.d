#include<iostream>
#include<cmath>
using std::cin, std::cout, std::endl;
// #include<cstdio>
typedef unsigned int uint;
typedef unsigned long long ull;
typedef long long ll;
typedef unsigned char uchar;

#define N 100001
uint h[N];
ull ans[N];
uint inline abs_minus(const uint a,const uint b){
	return a<b?b-a:a-b;
}

int main(){
	cin.tie(0);
	std::ios::sync_with_stdio(false);
	uint n;
	cin>>n;
	for(uint i=0;i<n;i++){
		cin>>h[i];
	}
	// ans[0]=0; // 1-st
	ans[1]=abs_minus(h[1],h[0]);
	for(uint i=2;i<n;i++){
		ans[i]=std::min(ans[i-1]+abs_minus(h[i],h[i-1]), ans[i-2]+3ull*abs_minus(h[i],h[i-2]));
	}
	cout<<ans[n-1]<<endl;
	return 0;
}