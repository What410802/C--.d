#include<cstdio>
typedef unsigned int uint;
typedef unsigned long long ull;
typedef long long ll;

bool inline isin(){
	static char c;
	c=getchar();
	return c!='\n' && c!=EOF;
}
#define MOD 10007

int main(){
	bool sgn; char dgt;
	getchar(); getchar(); sgn=getchar()=='-'; dgt=getchar()-'0'; getchar();
	int t0=sgn?-dgt:dgt, t1=1;
	while(isin()){
		getchar(); sgn=getchar()=='-'; dgt=getchar()-'0'; getchar();
		if(sgn){
			dgt=-dgt;
		}
		t1=(t1*dgt%MOD+t0)%MOD;
		t0=t0*dgt%MOD;
	}
	printf("%d\n",t1/*(t1+MOD)%MOD*/);
	return 0;
}