#include<iostream>
#include<set>
using std::cin, std::cout, std::endl;
typedef unsigned int uint;
typedef unsigned long long ull;
typedef long long ll;

std::set<uint>on;

int main(){
	cin.tie(0);
	std::ios::sync_with_stdio(false);
	uint T, n, m, x, y, p, rsize;
	uint l,r;
	std::set<uint>::iterator fnd;
	cin>>T;
	while(T--){
		l=r=0; on.clear();
		cin>>n>>m>>x>>y;
		rsize=n-y+1;
		while(m--){
			cin>>p;
			if(p<=x || p>=y){
				if((fnd=on.find(p))!=on.end()){
					if(p<=x){
						l--;
					}
					if(p>=y){
						r--;
					}
					on.erase(fnd);
				}
				else{
					if(p<=x){
						l++;
					}
					if(p>=y){
						r++;
					}
					on.insert(p);
				}
			}
			cout<<x-l<<' '<<rsize-r<<endl;
		}
	}
	// cout.flush();
	return 0;
}