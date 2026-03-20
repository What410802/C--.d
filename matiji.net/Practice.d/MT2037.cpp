#include<iostream>
using std::cin, std::cout;
#include<iomanip>
#include<string>
#include<map>

#include<numeric>
#include<functional>
using uch = unsigned char;
using ush = unsigned short;
using uint = unsigned int;
using ull = unsigned long long;
using ll = long long;
#define _ noexcept

// 128MB = 2^27; vs 1e15
#define X 100001
// #define NM 100001
uint n,m;
std::map<uint, uint> xs[X],ys[X]; // num->x/y->pos->cnt
uint total[X];

ull get_total_dist(decltype(xs) xs)_{ // num,pos -> cnt
	ull ret=0;
	for(uint num=0;num<X;num++){
		const auto &xsn = xs[num];
		if(xsn.size()<=1){
			continue;
		}
		uint prev_all_cnt=xsn.begin()->second, post_all_cnt=total[num]-prev_all_cnt;
		for(auto it0=xsn.begin(), it1=++xsn.begin();it1!=xsn.end();it0=it1, ++it1){
			ret+=static_cast<ull>(prev_all_cnt) * post_all_cnt * (it1->first - it0->first);
			prev_all_cnt+=it1->second;
			post_all_cnt-=it1->second;
// cout<<"# "<<ret<<" "<<"prev_all_cnt="<<prev_all_cnt<<"post_all_cnt="<<post_all_cnt<<'\n';
		}
// cout<<"P"<<'\n';
	}
	return ret;
}

int main()_{
	std::ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	cin>>n>>m;
	uint tmp;
	for(uint i=0;i<n;i++){
		for(uint j=0;j<m;j++){
			cin>>tmp;
			xs[tmp][i]++;
			ys[tmp][j]++;
			total[tmp]++;
		}
	}
	// cout<<get_total_dist(xs)<<' '<<get_total_dist(ys)<<'\n';
	cout<<get_total_dist(xs)+get_total_dist(ys)<<'\n';
	return 0;
}
/*
2 3
1 1 1
1 1 1
ans=7*1+6*2+2*3=25

3 4
1 1 1 1
1 1 1 1
1 1 1 1
// ans=(9+18+27)+(16+32)=102
*/