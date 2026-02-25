#include<iostream>
using std::cin, std::cout, std::endl;
#include<cmath>
// #include<cstdio>
typedef unsigned int uint;
typedef unsigned long long ull;
typedef long long ll;
typedef unsigned char uchar;

uint n,a,b;

int main(){
	cin.tie(0);
	std::ios::sync_with_stdio(false);
	uint t;
	cin>>t;
	while(t--){
		cin>>n>>a>>b;
		if(n==1){
			cout<<"1"<<endl;
		}
		else{
			cout<<(b-a)/(n-1)<<endl;
		}
	}
	return 0;
}