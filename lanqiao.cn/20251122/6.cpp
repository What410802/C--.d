#include<iostream>
using std::cin, std::cout, std::endl;
// #include<cstdio>
typedef unsigned int uint;
typedef unsigned long long ull;
typedef long long ll;
typedef unsigned char uchar;

#define MOD 1000000007
#define N 100002

ull inline calc_multiplier(uint l){
	return l+2; /*not plug-in a pin plus vice versa: 1 + l+1*/
}

char s[N];

int main(){
	cin.tie(0);
	std::ios::sync_with_stdio(false);
	uint n;
	cin>>n>>s;
	uint beg=0, rbeg=n-1;
	for(;;beg++){
		if(beg>=n){
			cout<<"0"<<endl;
			return 0;
		}
		if(s[beg]=='L'){
			break;
		}
	}
	for(;;rbeg--){
		// if(rbeg>=n){ // <0 /// Not possible
		// 	cout<<"0"<<endl;
		// 	return 0;
		// }
		if(s[rbeg]=='L'){
			break;
		}
	}
	ull ans=1;
	uint subl=0;
	for(uint i=beg+1;i<=rbeg;i++){
		if(s[i]=='L'){
			ans=(ans*calc_multiplier(subl))%MOD;
			subl=0;
		}
		else{
			subl++;
		}
	}
	cout<<ans<<endl;
	return 0;
}