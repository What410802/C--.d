#include<iostream>
#include<vector>
#include<algorithm>
#include<cstdint>
using std::cin,std::cout,std::endl;
// #include<cstdio>
typedef unsigned int uint;
typedef unsigned long long ull;
typedef long long ll;
typedef unsigned char uchar;

int main(){
	cin.tie(0);
	std::ios::sync_with_stdio(false);
	ll n,k;
	cin>>n>>k;
	std::vector<ll> a(n);
	for(ll i=0;i<n;++i){
		cin>>a[i];
	}
	
	ll pos=n-1,cnt=0;
	for(ll i=0;i<n;++i){
		if(i<n-1 && a[i]>a[i+1]){
			cnt+=1;
			if(cnt==k){
				pos=i;
				break;
			}
		}
		else if(i==n-1){
			cnt+=1;
			if(cnt==k){
				pos=n-1;
				break;
			}
		}
		else{
			ll j=i;
			while(j<n-1&&a[j]==a[j+1]){
				j++;
			}
			//
			if(j==n-1 || a[j]<a[j+1]){
				ll len=j-i+1;
				if(cnt+len >= k){
					pos=i + k-cnt-1;
					break;
				}
				cnt+=len;
				i=j;
			}
			else{
				// a[j]>a[j+1]
				ll len=j-i+1;
				cnt+=len;
				if(cnt >= k){
					pos=j-(cnt-k);
					break;
				}
				i=j;
			}
		}
	}
	for(ll i=0;i<=pos;++i){
		cout<<a[i]<<" ";
	}
	for(ll i=pos;i<n;++i){
		cout<<a[i];
		if(i<n-1)
			cout<<" ";
	}
	cout<<"\n";
	return 0;
}
/*
3 1
2 5 3
*/