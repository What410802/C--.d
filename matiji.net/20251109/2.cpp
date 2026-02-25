#include<cstdio>
// #include<cmath>
typedef unsigned int uint;
typedef unsigned long long ull;
typedef long long ll;

uint o=0,q=0;
ull ans;

auto inline pow2(const ull a){
	return a*a;
}
auto inline pow4(ull a){
	a*=a;
	return a*a;
}

int main(){
	for(uint i=0;i<10;i++){
		switch(getchar()){
			case 'o':
			o++;
			break;
			case '?':
			q++;
			break;
		}
	}
	switch(o){
		case 4:{
			ans=24;
			break;
		}
		case 3:{
			ans=3*(12/*C_4^2*/) + q/*C_q^1*/ * 24/*4!*/;
			break;
		}
		case 2:{
			// ans=pow4(q+2) - 2*(pow4(q+1) - pow4(q)) - pow4(q);
			ans=pow4(q+2) - 2*pow4(q+1) + pow4(q);
			break;
		}
		case 1:{/*each o and ? can appear multiple times*/
			ans=pow4(q+1)-pow4(q);
			break;
		}
		case 0:{
			ans=pow4(q);
			break;
		}
		default:{
			ans=0;
			break;
		}
	}
	printf("%llu\n",ans);
	return 0;
}