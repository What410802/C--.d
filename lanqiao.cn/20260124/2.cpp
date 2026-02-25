#include<iostream>
using std::cin, std::cout, std::endl;
// #include<cstdio>
typedef unsigned int uint;
typedef unsigned long long ull;
typedef long long ll;
typedef unsigned char uchar;

int main(){
	cin.tie(0);
	std::ios::sync_with_stdio(false);
	uint n,k;
	cin>>n>>k;
	uint l=1,r=n,m;
	uint ans=0;
	for(;;){
		m=(l+r)>>1;
		ans++;
		if(m<k){
			l=m+1;
		}
		else if(m>k){
			r=m-1;
		}
		else{
			break;
		}
	}
	cout<<ans<<endl;
	return 0;
}