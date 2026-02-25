typedef unsigned char ubt;
typedef unsigned int uint;
typedef unsigned long long ull;

#include<cstdio>
#include<cmath>

bool in[26*2502];
uint inl=0,ini;
inline void by_n_iter(const uint n){
	uint nwin=0,ntot=0;
	for(ini=0;;ini++,ntot++){
		// Ending condition per round:
		if(ini>=inl){
			printf("%u:%u\n",nwin,ntot-nwin);
			nwin=0;ntot=0;
			break;
		}
		if((nwin>=n||ntot-nwin>=n)&&abs(ntot-nwin-nwin)>1){
			printf("%u:%u\n",nwin,ntot-nwin);
			nwin=0;ntot=0;
		}
		if(in[ini]){
			nwin++;
		}
	}
}

int main(){
	while(true){
		switch (getchar())
		{
		case 'W':
			in[inl++]=true;
			break;
		case 'L':
			in[inl++]=false;
			break;
		case '\n':
			continue;
		default:
			goto _end_input;
		}
	}
	_end_input:;

	by_n_iter(11);
	putchar('\n');
	by_n_iter(21);
	return 0;
}