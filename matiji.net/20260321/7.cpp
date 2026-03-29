#include<iostream>
using std::cin; using std::cout;
#include<iomanip>
#include<string>
#include<vector>
#include<set>

#include<algorithm>
#include<numeric>
#include<functional>
using uch = unsigned char;
using ush = unsigned short;
using uint = unsigned int;
using ull = unsigned long long;
using ll = long long;
#define _ noexcept

#define N 100002
uint in[3][N];

int main()_{
	std::ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	uint t; cin>>t;
	while(t--){
		uint n,m; cin>>n>>m;
		for(uint abc=0;abc<3;abc++){
			for(uint i=0;i<n;i++){
				cin>>in[abc][i];
			}
			std::sort(in[abc],in[abc]+n);
		}
		ull curr=(ull)in[0][0]*in[1][0]*in[2][0];
		if(n==1){
			cout<<curr<<'\n';
			continue;
		}
		struct place{
			ull result;
			uint ends[3];
			bool operator<(const place &p)const _{
				if(result<p.result){
					return true;
				}
				else if(result==p.result){
					for(auto i:{0,1,2}){
						if(ends[i]<p.ends[i]){
							return true;
						}
						else if(ends[i]>p.ends[i]){
							return false;
						}
					}
				}
				return false;
			}
		};
		std::set<place>q;
		std::vector<ull>res;
		q.insert(place{curr, {1,1,1}});
		while(res.size()<=m){
			// if(q.empty()){}
			const auto min_front=*q.begin(); q.erase(q.begin());
			for(uint abc:{0,1,2}){
				auto front=min_front;
				if(front.ends[abc]>=n){ // already the last item. Not suitable for extension.
					continue;
				}
				front.result/=in[abc][front.ends[abc]-1];
				front.ends[abc]++;
				front.result*=in[abc][front.ends[abc]-1];
				q.insert(front);
			}
			res.push_back(min_front.result);
		}
		for(uint i=0;i<m;i++){
			cout<<res[i]<<(i==m-1?'\n':' ');
		}
	}
	return 0;
}