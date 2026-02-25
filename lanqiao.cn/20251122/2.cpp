#include<iostream>
#include<algorithm>
using std::cin, std::cout, std::endl;
// #include<cstdio>
typedef unsigned int uint;
typedef unsigned long long ull;
typedef long long ll;

#define N 100001
uint n;
uint id[N];

int main(){
	cin.tie(0);
	std::ios::sync_with_stdio(false);
	cin>>n;
	for(uint i=0;i<n;i++){
		cin>>id[i];
	}
	std::sort(id, id+n);
	for(uint i=0;i<n;i++){
		if(id[i]<i+1){
			cout<<"NO"<<endl;
			return 0;
		}
	}
	cout<<"YES"<<endl;
	return 0;
}