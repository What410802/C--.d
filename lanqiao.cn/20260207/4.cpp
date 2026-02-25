#include<iostream>
using std::cin, std::cout, std::endl;
#include<vector>
#include<utility>
#include<algorithm>
//#include<cstdio>
typedef unsigned int uint;
typedef unsigned long long ull;
typedef long long ll;
typedef unsigned char uchar;

uint x;

std::vector<uint> primes;
void inline sieve(){
	#define N 40000 //sqrt(1e9)
	std::vector<bool> is_prime(N+1,true);
	for(uint i=2;i*i<=N;++i)
		if(is_prime[i])
			for(uint j=i*i;j<=N;j+=i)
				is_prime[j]=false;
	for(uint i=2;i<=N;++i)
		if(is_prime[i])
			primes.push_back(i);
}

std::vector<std::pair<uint,uint>> inline factorize(uint x){
	std::vector<std::pair<uint,uint>> factors;
	for(const auto p:primes){
		if(p*p>x)
			break;
		if(x%p==0){
			uint cnt=0;
			while(x%p==0)
				x/=p,++cnt;
			factors.emplace_back(p,cnt);
		}
	}
	if(x>1)
		factors.emplace_back(x,1);
	return factors;
}

std::vector<uint> inline get_divisors(const std::vector<std::pair<uint,uint>>&factors){
	std::vector<uint> divisors={1};
	for(const auto [p,exp]:factors){
		std::vector<uint> new_divs;
		for(uint d:divisors){
			uint cur=d;
			for(uint i=0;i<=exp;++i){
				new_divs.push_back(cur);
				cur*=p;
			}
		}
		std::swap(divisors, new_divs);
	}
	return divisors;
}

int main(){
	cin.tie(0);
	std::ios::sync_with_stdio(false);
	sieve();
	uint T,X;
	cin>>T;
	while(T--){
		cin>>X;
		const auto factors=factorize(X);
		std::vector<uint> divs=get_divisors(factors);
		std::sort(divs.begin(),divs.end());
		const uint n=divs.size();
		ull ans=9223372036854775807ull;//LLONG_MAX;
		uint j=n-1;
		// Two-pointer to find min product>X
		for(uint i=0;i<n;++i){
			while(j<n && (ull)divs[i]*divs[j]>X)
				--j;
			if(j+1<n){
				ull prod=(ull)divs[i]*divs[j+1];
				if(prod<ans){
					ans=prod;
				}
			}
		}
		cout<<ans-X<<endl;
	}
	return 0;
}
/*
2
2
3
*/