#include<iostream>
using std::cin; using std::cout;
#include<iomanip>
#include<string>
#include<vector>

#include<numeric>
#include<functional>
using uch = unsigned char;
using ush = unsigned short;
using uint = unsigned int;
using ull = unsigned long long;
using ll = long long;
#define _ noexcept

uint m,n;
void out_two(uint r,uint c, bool hori)_{
	cout<<r<<' '<<c<< ' ';
	if(hori){
		cout<<r<<' '<<c+1;
	}
	else{
		cout<<r+1<<' '<<c;
	}
}
void out_four(uint r,uint c, bool hori, bool flip)_{
	if(!flip){
		out_two(r,c,hori);
		cout<<' ';
		out_two(r+1,c+1,hori);
	}
	else{
		/*		  v
			 #	 ##
			##	##
		>	#
		*/
		if(hori){
			out_two(r,c-1,hori);
			cout<<' ';
			out_two(r+1,c-2,hori);
		}
		else{
			out_two(r-1,c,hori);
			cout<<' ';
			out_two(r-2,c+1,hori);
		}
	}
	cout<<'\n';
}

int main()_{
	std::ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	cin>>m>>n;
	if((m&3 && n&3)){
		cout<<"Impossible!"<<'\n';
		return 0;
	}
	if(!(n&3)){ // col number is 4x, tiling with horizontal 'z' that compose a 2*4 block
		cout<<(m*(n/4)*2)<<'\n';
		for(uint c=0;c<n;c+=4){
			out_four(0,c,true,false);
			out_four(0,c+3,true,true);
		}
		for(uint r=0;r+1<m;r++){
			for(uint c=0;c<n;c+=4){
				out_four(r,c+1,true,false);
				out_four(r,c+2,true,true);
			}
		}
	}
	else{
		cout<<(n*(m/4)*2)<<'\n';
		for(uint r=0;r<m;r+=4){
			out_four(r,0,false,false);
			out_four(r+3,0,false,true);
		}
		for(uint c=0;c+1<n;c++){
			for(uint r=0;r<m;r+=4){
				out_four(r+1,c,false,false);
				out_four(r+2,c,false,true);
			}
		}
	}
	return 0;
}