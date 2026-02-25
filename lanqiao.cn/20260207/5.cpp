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
	uint t;
	uint a,b;
	cin>>t;
	while(t--){
		cin>>a>>b;
		cout<<((a>b+1 || a==b || a==1 || b==1)?'L':'Q')<<endl;
	}
	return 0;
}