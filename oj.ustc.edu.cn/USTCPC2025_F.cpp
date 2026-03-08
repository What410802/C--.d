#include<iostream>
using std::cin, std::cout, std::endl;
#include<vector>
#include<list>
#include<set>
using uch = unsigned char;
using ush = unsigned short;
using uint = unsigned int;
using ull = unsigned long long;
using ll = long long;
#define _ noexcept

using INode = uint;
INode n;
uint m;
std::vector<std::list<INode>>nxs;
std::vector<uint>deg; // INode->degree of it
const auto compare=[](const INode a, const INode b)_{return deg[a]<deg[b] || (deg[a]==deg[b] && a<b);}; // Important error: set judges equal by neither < nor >, so the things after || is needed.
std::set<INode, decltype(compare)>q(compare); // sorts the id's of nodes

int main()_{
	std::ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	cin>>n>>m;
	nxs.resize(n); deg.resize(n);
	for(uint i=0;i<m;i++){
		INode u,v; cin>>u>>v; --u; --v;
		nxs[u].emplace_back(v);
		nxs[v].emplace_back(u);
		deg[u]++;
		deg[v]++;
	}
	for(INode i=0;i<n;i++){
		q.emplace(i);
	}
// for(const INode i:q){
// 	cout<<"#"<<i;
// }
// cout<<endl;
	// core idea: a path to death is not worth it, so can be removed from actual degrees. And the node with smallest degree cannot be improved anymore because according to game theory we must trap our enemy instantly.
	while(!q.empty()){
		const auto smallest_node = *q.begin(); q.erase(q.begin()); // Once extracted, never put back, and at the same time deg[i]'s meaning turns from the original degree to the "steps from lose (plus the degree of its corresponding death point)".
		for(const auto &nx:nxs[smallest_node]){
			if(deg[nx]>deg[smallest_node]){ // // else, deg[nx]==deg[smallest_node]
				auto affected = q.extract(nx); // At this time, deg[nx] must >0
				--deg[nx];
				q.insert(std::move(affected));
			}
		}
	}
	for(INode i=0;i<n;i++){ // Needn't add 1.
		cout<<deg[i];
		if(i+1==n){
			cout<<endl;
		}
		else{
			cout<<' ';
		}
	}
	return 0;
}