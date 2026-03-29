#include<iostream>
using std::cin; using std::cout;
#include<iomanip>
#include<string>
#include<vector>

#include<numeric>
#include<functional>
using uch = unsigned char;
using ush = unsigned short;
using uint = unsigned int;
using ull = unsigned long long;
using ll = long long;
#include<cstdlib>
#include<cstdio>
#define _ noexcept

#define X 2001
uint cnt[X][2];

int main()_{
	std::ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	uint n,q; cin>>n>>q;
	uint in;
	for(uint i=0;i<n;i++){
		cin>>in;
		cnt[in][0]++;
	}
	bool curr=0;
	uint force,ans=1;
	for(uint qi=0;qi<q;qi++){
		cin>>force;
		if((force!=1 || qi==0)&&ans>0){
			if(force!=1){
				for(uint to=0;to<X;to++){
					cnt[to][!curr]=0;
				}
				for(uint to=0;;to++){
					const auto origind=to*force;
					if(origind>=X){
						break;
					}
					// auto &origin=cnt[origind][curr];
					// cnt[to][!curr]+=origin;
					for(uint add=0, end=std::min(force, X-origind);add<end;add++){
						cnt[to][!curr]+=cnt[origind+add][curr];
					}
				}
				curr=!curr;
			}
			ans=0;
			for(uint i=1;i<X;i++){
				ans+=cnt[i][curr]*i;
			}
		}
		cout<<ans<<'\n';
	}
	return 0;
}
/*
10 8
4 4 4 4 4
6 6 6 6 6
2 2 2 2
1 1 6 6

10 8
4 4 4 4 4
6 6 6 6 6
1 1 1 1
2 2 1 1

10 8
1024 1024 1 4 4
6 6 6 6 6
2 2 2 2
2 2 2 16

10 8
2000 2000 2000 2000 1001
1003 1005 1050 1555 1
2 3 5 7
8 8 10 10

*/