#include<iostream>
using std::cin, std::cout, std::endl;
#include<map>
#include<vector>
#include<tuple>
#include<functional>
#include<algorithm>
using uint = unsigned int;
using ull = unsigned long long;
using ll = long long;
using uch = unsigned char;
#define _ noexcept

// partial orders: [weight, cut]: weight1==weight2 && cut1<cut2
uint n,m;
#define N 31
uint in[N]; // should indirectly multiply every input by 2
std::map<uint,uint> map; // remain_weight->#cut. should only contain those with total weight<m

template<typename Func>
void inline update_map(const uint k, const uint v, const Func &&update /*= [](const decltype(map)::iterator &dst, const uint src)_{dst->second = src;}*/)_{
	if(const auto find=map.find(k); find!=map.end()){
		update(find, v);
	}
	else{
		map.emplace_hint(find, k, v);
	}
}

uint ans=N;

uint thresh;
void inline dfs1(uint i, uint remain_weight, uint cut)_{ // Going to consider item i+1; already considered item i, rem_w,cut cover items <=i
// cout<<"1: "<<i<<"; rem_w="<<remain_weight<<"; cut="<<cut<<endl;
	if(i==thresh || remain_weight==0){
		update_map(remain_weight, cut, [](const decltype(map)::iterator &dst, const uint src){
			if(dst->second > src){
				dst->second = src;
			}
		});
		return;
	}
	i++;
	if(in[i] <= remain_weight){
		dfs1(i, remain_weight - in[i], cut+1);
		if(in[i]<<1 <= remain_weight){
			dfs1(i, remain_weight - (in[i]<<1), cut);
		}
	}
	dfs1(i, remain_weight, cut);
}

void inline dfs2(uint i, uint remain_weight, uint cut)_{
// cout<<"2: "<<i<<"; rem_w="<<remain_weight<<"; cut="<<cut<<endl;
	if(cut>=ans){
		return;
	}
	if(i==n || remain_weight==0){ // Finished
// cout<<"Finding remain_weight="<<remain_weight<<"..."<<endl;
		if(const auto find = map.find(m - remain_weight); find!=map.end()){
// cout<<"Minimizing ans "<<ans;
			if(const auto tmp_cut=cut+find->second; ans>tmp_cut){ // minimizing ans
// cout<<" to "<<tmp_cut;
				ans = tmp_cut;
			}
// cout<<endl;
		}
		return;
	}
	i++;
	if(in[i] <= remain_weight){
		dfs2(i, remain_weight - in[i], cut+1);
		if(in[i]<<1 <= remain_weight){
			dfs2(i, remain_weight - (in[i]<<1), cut);
		}
	}
	dfs2(i, remain_weight, cut);
}

int main()_{
	std::ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	cin>>n>>m; m<<=1;
	thresh = n>4 ? (n>>1)-2 : 0;
	for(uint i=0;i<n;i++){
		cin>>in[i];
	}
	std::sort(in, in+n);

	dfs1(-1, m, 0);
// for(const auto &[k,v]:map){
// 	cout<<k<<": "<<v<<endl;
// }
	dfs2(thresh, m, 0);
	if(ans==N){
		cout<<"-1"<<endl;
	}
	else{
		cout<<ans<<endl;
	}
	return 0;
}