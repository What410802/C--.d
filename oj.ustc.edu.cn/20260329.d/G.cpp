#include<iostream>
using std::cin; using std::cout;
#include<iomanip>
#include<string>
#include<vector>

#include<climits>
#include<numeric>
#include<functional>
using uch = unsigned char;
using ush = unsigned short;
using sh = short;
using uint = unsigned int;
using ull = unsigned long long;
using ll = long long;
#define _ noexcept

uint n,m,r,c;
std::vector<std::vector<sh>>in;
std::vector<std::vector<std::pair<sh,sh>>>d;
std::vector<std::vector<bool>>eq_min;
sh min;

template<typename T1,typename T2>
auto mize(T1 &a1, const T2 a2)_{
	if(a1>a2){
		a1=a2;
	}
}
template<typename T1,typename T2>
auto maxe(T1 &a1, const T2 a2)_{
	if(a1<a2){
		a1=a2;
	}
}

int main()_{
	std::ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	uint T; cin>>T;
	while(T--){
		cin>>n>>m>>r>>c;
		in.assign(1+n, std::vector<sh>(1+m, 0));
		d.assign(1+n, std::vector<std::pair<sh,sh>>(1+m, {0,0}));
		eq_min.assign(1+n, std::vector<bool>(1+m, 0));
		min=SHRT_MAX;

		for(uint i=1;i<=n;i++){
			for(uint j=1;j<=m;j++){
				cin>>in[i][j];
				mize(min,in[i][j]);
			}
		}
		for(uint i=1;i<=n;i++){
			for(uint j=1;j<=m;j++){
				if(in[i][j]==min){
					eq_min[i][j]=true;
				}

				if(i==1){
					d[i][j].first = (in[2][j]-in[1][j])<<1;
				}
				else if(i==n){
					d[i][j].first = (in[n][j]-in[n-1][j])<<1;
				}
				else{
					d[i][j].first = (in[i+1][j]-in[i-1][j]);
				}
				if(j==1){
					d[i][j].second = (in[i][2]-in[i][1])<<1;
				}
				else if(j==m){
					d[i][j].second = (in[i][m]-in[i][m-1])<<1;
				}
				else{
					d[i][j].second = (in[i][j+1]-in[i][j-1]);
				}
			}
		}
		const auto &orig = d[r][c];
		if(orig.first==0 && orig.second==0){
			cout<<"Impossible\n";
			continue;
		}
		int firstmax = INT_MAX; // Note, not shrt_min
		if(orig.first>0){
			mize(firstmax, int(r-1)/orig.first);
		}
		else if(orig.first<0){
			mize(firstmax, int(n-r) / -orig.first);
		}
		if(orig.second>0){
			mize(firstmax, int(c-1)/orig.second);
		}
		else if(orig.second<0){
			mize(firstmax, int(m-c) / -orig.second);
		}
		if(firstmax<=0){
			cout<<"Impossible\n";
			continue;
		}
		std::vector<uint> vis(1+n*m, 0);
		uint ans; bool got_ans=false;
		for(uint k=firstmax,tm=1,i,j;k;k--,tm++){
			bool found=false;
			i=r; j=c; for(;;){
				if(const uint ij=(i-1)*m+j; vis[ij]==tm){
					break; // cycle
				}
				else{
					vis[ij]=tm;
				}

				if(eq_min[i][j]){
					found=true;
					break;
				}
				
				const int nxi=i-k*d[i][j].first, nxj=j-k*d[i][j].second;
				if(nxi<1||nxi>n||nxj<1||nxj>m){
					break;
				}
				i=nxi; j=nxj;
			}
			if(found){
				ans=k<<1;
				got_ans=true;
				break;
			}
		}
		if(got_ans){
			cout<<ans<<'\n';
		}
		else{
			cout<<"Impossible\n";
		}
	}
	return 0;
}