#include<iostream>
using std::cin, std::cout, std::endl;
#include<map>
#include<vector>
#include<tuple>
#include<functional>
using uint = unsigned int;
using ull = unsigned long long;
using ll = long long;
using uch = unsigned char;
#define _ noexcept

// partial orders: [weight, cut]: weight1==weight2 && cut1<cut2
uint n,m;
#define N 31
uint in[N]; // should indirectly multiply every input by 2
std::map<uint,uint> map; // weight->#cut. should only contain those with total weight<m

template<typename Func>
void inline update_map(const uint k, const uint v, const Func &update = [](const decltype(map)::iterator &dst, const uint src)_{dst->second = src;})_{
	const auto lb=map.lower_bound(k);
	if(lb!=map.end() && lb->first==k){
		update(lb, v);
	}
	else{
		map.emplace_hint(lb, k, v);
	}
}

uint ans=N;

void inline dfs2(){ // DFS1 is already done by binary compression.
}

int main()_{
	std::ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	map.emplace(0,0);
	cin>>n>>m; m<<=1;
	std::vector<std::pair<uint, uint>> news(n); uint l;
	for(uint i=0;i<n;i++){
// for(const auto &[k,v]:map){
// 	cout<<'#'<<k<<','<<v<<endl;
// }
		cin>>in[i];
		l=0;
		for(const auto &[weight, cut]: map){
			const auto max_add = m - weight;
			if(in[i] <= max_add){
				news[l++] = {weight+in[i], cut+1, };
				if(in[i]<<1 <= max_add){
					news[l++] = {weight+(in[i]<<1), cut, };
				}
			}
		}
		for(uint j=0;j<l;j++){
			update_map(news[j].first, news[j].second, [](const decltype(map)::iterator &dst, const uint src)_{
				if(dst->second > src){
					dst->second = src;
				}
			});
		}
	}
	const auto lb=map.lower_bound(m);
	if(lb!=map.end() && lb->first==m){
		cout<<lb->second<<endl;
	}
	else{
		cout<<"-1"<<endl;
	}
	return 0;
}