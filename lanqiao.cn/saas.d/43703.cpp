#include<iostream>
using std::cin, std::cout, std::endl;

using uint = unsigned int;
using ull = unsigned long long;
using ll = long long;
using uch = unsigned char;

ull bbp(ull n){
	return n&1ull ? n*3+1 : n>>1; ///
}
ull get_M(ull n){
	ull M=n;
	while((n=bbp(n))>1){
		if(n>M){
			M=n;
// cout<<M<<"#"<<endl;
		}
	}
	return M;
}

int main(){
	cin.tie(nullptr);
	std::ios::sync_with_stdio(false);
	ull n;
	cin>>n;
	ull M=4,tmp;
	for(uint i=1;i<=n;i++){
		if((tmp=get_M(i))>M){
			M=tmp;
		}
	}
	cout<<M<<endl;
	return 0;
}