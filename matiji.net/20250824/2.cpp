typedef unsigned char ubyte;
typedef unsigned int uint;
typedef unsigned long long ull;
typedef long long ll;

#include<cstdio>
#include<set>

// #define N 
uint n,k;
std::set<uint>s;

int main(){
	scanf("%u%u",&n,&k);
	uint a;
	while (n--)
	{
		scanf("%u",&a);
		s.insert(a);
	}
	if(s.size()<k){
		puts("-1");
	}
	else{
		uint cnt=0;
		for(auto ele:s){
			cnt++;
			if(cnt==k){
				printf("%u",ele);
				break;
			}
		}
	}
	return 0;
}