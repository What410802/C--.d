#include<iostream>
using std::cin, std::cout, std::endl;

using uint = unsigned int;
using ull = unsigned long long;
using ll = long long;
using uch = unsigned char;
#define _ noexcept

uint n;
#define N 10002
uint a[N];
/*
uint tree[N]; // To query (0,i], just sum up each tree[i];i-=lowbit(i);.
uint inline lowbit(const uint n)_{
	return n&-n;
}
uint query(uint i)_{
	uint ret=0;
	for(;i;i-=lowbit(i)){
		ret+=tree[i];
	}
	return ret;
}
void update(uint i, const uint add)_{
	for(;i<=n;i+=lowbit(i)){
		tree[i]+=add;
	}
}
*/


int main()_{
	std::ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	cin>>n;
	for(uint i=1;i<=n;i++){
		cin>>a[i];
	}
	uint ans=0;
	/*for(uint i=n;i;i--){
		ans+=query(a[i]);
		update(a[i], 1);
	}*/
	for(uint i=1;i<=n;i++){
		while(a[i]!=i){ // Non-static point encountered.
			std::swap(a[i], a[a[i]]);
			ans++;
		}
	}
	cout<<ans<<endl;
	return 0;
}