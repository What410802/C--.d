typedef unsigned char ubyte;
typedef unsigned int uint;
typedef unsigned long long ull;
typedef long long ll;

#include<cstdio>

#define N 1001
#define M 101
uint n,m,q;
bool stamp[M][M];
uint ans[N][N];

inline bool access_stamp(ubyte dir,uint x,uint y){
	switch (dir)
	{
	case 0:
		return stamp[x][y];
	case 1:
		return stamp[m-1-y][x];
	case 2:
		return stamp[m-1-x][m-1-y];
	case 3:
		return stamp[y][m-1-x];
	}
}

inline void gai(ubyte dir,uint x,uint y){
	uint i,j;
	for(i=0;i<m;i++){
		for(j=0;j<m;j++){
			if(access_stamp(dir,i,j)){
				ans[x+i][y+j]++;
			}
		}
	}
}

int main(){
	scanf("%u%u%u",&n,&m,&q);
	uint i,j;
	for(i=0;i<m;i++){
		getchar();
		for(j=0;j<m;j++){
			stamp[i][j]=getchar()=='#';
		}
	}
	uint qr,x,y;
	ubyte dir=0;
	for(i=0;i<q;i++){
		scanf("%u",&qr);
		if(qr==1){
			dir++;
			dir&=3;
		}
		else{
			scanf("%u%u",&x,&y);
			gai(dir,x-1,y-1);
		}
	}
	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			printf(j==n-1?"%u\n":"%u ",ans[i][j]);
		}
	}
	return 0;
}