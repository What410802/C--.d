#include<cstdio>
typedef unsigned int uint;
typedef unsigned long long ull;
typedef long long ll;

#define N 300002
// uint l;
char s[N];

// All non-empty!

ull inline cntall(uint beg, uint end){ // Even for 0~0
	// printf("#%u~%u\n", beg,end);
	return ((ull)(end-beg)*(end-beg+1))>>1;
}
/*
e.g.:
"abc"(end-beg==3): a~abc(3), b,bc(2), c(1)
*/

ull inline cntn1(uint beg, uint end, char c){
	ull ret=0;
	uint subbeg=beg;
	for(uint i=beg;i<end;i++){
		if(s[i]==c){
			ret+=cntall(subbeg, i);
			subbeg=i+1;
		}
	}
	ret+=cntall(subbeg, end);
	// printf("n1:%u~%u, %c: %llu\n", beg, end,c, ret);
	return ret;
}

ull inline cntn2(uint beg, uint end, char c1, char c2){
	ull ret=0;
	uint subbeg=beg;
	for(uint i=beg;i<end;i++){
		if(s[i]==c1 || s[i]==c2){
			ret+=cntall(subbeg, i);
			subbeg=i+1;
		}
	}
	ret+=cntall(subbeg, end);
	// printf("n2:%u~%u, %c %c: %llu\n", beg, end,c1,c2,ret);
	return ret;
}

ull inline cnt2(uint beg, uint end, char c1, char c2){
	// printf("2:%u~%u, %c %c: %llu\n", beg, end,c1,c2,cntall(beg, end) - cntn1(beg, end, c1) - cntn1(beg, end, c2) + cntn2(beg, end, c1, c2));
	return cntall(beg, end) - cntn1(beg, end, c1) - cntn1(beg, end, c2) + cntn2(beg, end, c1, c2);
}

int main(){
	fgets(s, N, stdin);
	ull ans=0;
	for(uint i=0, beg=0;;i++){ // cnt_n1&2
		if(s[i]=='d'){
			ans+=cnt2(beg, i, 'r', 'e');
			beg=i+1;
		}
		else if(s[i]=='\n'||s[i]=='\0'||s[i]==EOF){
			ans+=cnt2(beg, i, 'r', 'e');
			break;
		}
	}
	printf("%llu\n", ans);
	return 0;
}
/*
a,b in sub: all - a not in - b not in + a,b not in
a not in: split
// a in: 
*/