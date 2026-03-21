#include<iostream>
using std::cin, std::cout, std::endl;
using uint = unsigned int;
using ull = unsigned long long;
using ll = long long;
using uch = unsigned char;

int main(){
	cin.tie(nullptr);
	std::ios::sync_with_stdio(false);
	uint n;
	cin>>n;
	uint ans=n;
	for(;;){
		if(n>=3){
			n-=2; ans++;
		}
		else{
			break;
		}
	}
	cout<<ans<<endl;
	return 0;
}