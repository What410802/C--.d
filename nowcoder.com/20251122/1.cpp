#include<iostream>
using std::cin, std::cout, std::endl;
typedef unsigned int uint;
typedef unsigned long long ull;
typedef long long ll;

uint a,A;
uint ans;

int main(){
	cin.tie(0);
	std::ios::sync_with_stdio(false);
	uint n,k;
	char c;
	cin>>n>>k;
	for(uint i=0;i<n;i++){
		cin>>c;
		if('A'<=c && c<='Z'){
			A++;
		}
		else{
			a++;
		}
	}
	if(k<=a){
		ans=A+k;
	}
	else{
		ans=(k-a)&1?n-1:n;
	}
	cout<<ans<<endl;
	return 0;
}