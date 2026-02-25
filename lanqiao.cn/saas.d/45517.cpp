#include<iostream>
using std::cin, std::cout, std::endl;
#include<set>
#include<map>
#include<utility>
// #include<limits>
using uint = unsigned int;
using ull = unsigned long long;
using ll = long long;
using uch = unsigned char;
#define _ noexcept

uint n,target;
#define N 2002 // 0 stands for not viable
uint t[N];
std::set<std::pair<uint,uint>> q; // t, id
std::map<uint,uint> map; // id, t
uint alg[N][N];

int main()_{
	// std::ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	uint m,k;
	cin>>n>>m>>k>>target;
	for(uint i=1;i<=n;i++){
		cin>>t[i];
	}
	for(uint i=0,ti;i<m;i++){
		cin>>ti;
		q.emplace(0,ti); // in following codes, only when plugging in do we update mint.
		map.emplace(ti,0);
	}
	for(uint i=0,a,b,c;i<k;i++){
		cin>>a>>b>>c;
		alg[a][b]=alg[b][a]=c;
// cout<<'@'<<i<<'/'<<k<<endl;
	}

	while(!q.empty()){
		// cout<<'#'<<q.size()<<endl;
		// const auto [t_t,t_id]=*q.begin(); q.erase(q.begin());
		const auto &&[t_t, t_id] = std::move(*q.begin()); q.erase(q.begin());
		// cout<<'h'<<endl;
		for(const auto &[tt_id, tt_t]:map){
			// cout<<'j'<<endl;
			if(const auto new_id = alg[t_id][tt_id]; new_id){
				// cout<<"##"<<new_id<<endl;
				const auto new_t = std::max(t_t, tt_t) + std::max(t[t_id], t[tt_id]);
				const auto old_at = map.find(new_id);
				if(old_at == map.end()){
					q.emplace(new_t, new_id);
					map.emplace(new_id, new_t);
				}
				else if(new_t < old_at->second){
					q.erase(q.find({old_at->second, new_id}));
					q.emplace(new_t, new_id);
					old_at->second = new_t;
				}
			}
		}
	}
	cout<<map[target]<<endl;
	return 0;
}