#include<iostream>
using std::cin, std::cout, std::endl;
// #include<cstdio>
typedef unsigned int uint;
typedef unsigned long long ull;
typedef long long ll;
typedef unsigned char uchar;

uint cnt[26];

int main(){
	cin.tie(0);
	std::ios::sync_with_stdio(false);
	uint n;
	cin>>n;
	char c;
	for(uint i=0;i<n;i++){
		cin>>c;
		cnt[c-'a']++;
	}
	uint ans=0;
	for(uchar cid=0;cid<26;cid++){
		if(cnt[cid]&1){
			ans++;
		}
	}
	if(ans==0){
		ans=1;
	}
	cout<<ans<<endl;
	return 0;
}