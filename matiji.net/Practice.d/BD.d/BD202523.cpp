#include<iostream>
#include<iomanip>
using std::cin, std::cout; constexpr auto LF='\n';
#include<string>
using str=std::string;
#include<vector>
#define vec std::vector
#include<numeric>
#include<algorithm>
#include<unordered_set>
#include<unordered_map>
#include<set>
#include<queue>

using uint=unsigned int;
using ll=long long; using ull=unsigned long long;

template<typename T>
void mize(T &a, const T b){
	if(a>b){
		a=b;
	}
}
template<typename T>
void maxe(T &a, const T b){
	if(a<b){
		a=b;
	}
}

#define MOD
#define N 100009
uint n;
struct Pos{
	int x,y;
	Pos operator+(const Pos &oth)const{
		return {x+oth.x, y+oth.y};
	}
	Pos &operator-=(const Pos &oth){
		x-=oth.x; y-=oth.y;
		return *this;
	}
	bool operator==(const Pos &oth)const{
		return x==oth.x && y==oth.y;
	}
	bool operator!=(const Pos &oth)const{
		return x!=oth.x || y!=oth.y;
	}
};
template<class T_stream>
T_stream &operator<<(T_stream &s, const Pos &oth){
	return s<<'('<<oth.x<<", "<<oth.y<<')';
}
template<>
struct std::hash<Pos> {
	size_t operator()(const Pos& p) const noexcept{
		return static_cast<size_t>(static_cast<uint>(p.x)) << 32 | static_cast<uint>(p.y);
	}
};


Pos pts[N];
std::unordered_set<Pos> ptsin;
std::unordered_map<int,std::set<int>> x2, y2; // x to y, y to x
// struct BumpPt{
// 	int x,y;
// 	bool dfree[4]; // dcan[dx<<1|dy]
// };
std::unordered_map<Pos, std::pair<bool,Pos>[4]> nx; // this should only store bump points that can be touched from (0,0)
//								  ^can ^nxat^dirid

const Pos i2dv[4]{{1,0},{0,1},{-1,0},{0,-1}};
const std::unordered_map<Pos,uint> dv2i{
	{{1,0},0},
	{{0,1},1},
	{{-1,0},2},
	{{0,-1},3},
};

std::unordered_set<Pos> vis;
void build(Pos at/*bump point*/){ // guaranteed that we won't go inside bump points
// cout<<"Working on "<<at<<LF;
	if(vis.count(at))
		return;
	vis.insert(at);
	// at 不可能在输入的点里面找到，因为始终保持在碰撞体外部。
	for(uint idir=0;idir<4;idir++){ const auto &dv=i2dv[idir];
		if(ptsin.count(at+dv))
			continue; // the next step is an input point, i.e. this point is two bump points covering each other
			// now there must be no point ahead directly
		if(dv.x){
			const auto &set=y2[at.y]; // must!=ub; @lb-1 - at.x - @lb
			if(dv.x>0){
				const auto r=set.upper_bound(at.x);
				if(r==set.end()) // in sea
					continue;
				nx[at] [idir] = {true,{*r, at.y}}; // can move~
			}
			else{
				const auto l=std::make_reverse_iterator(set.lower_bound(at.x));
				if(l==set.rend())
					continue;
				nx[at] [idir] = {true,{*l, at.y}};
			}
		}
		else{
			const auto &set=x2[at.x];
			if(dv.y>0){
				const auto u=set.upper_bound(at.y);
				if(u==set.end())
					continue;
				nx[at] [idir] = {true,{at.x, *u}};
			}
			else{
				const auto d=std::make_reverse_iterator(set.lower_bound(at.y));
				if(d==set.rend())
					continue;
				nx[at] [idir] = {true,{at.x, *d}};
			}
		}
// cout<<"Got nx["<<at<<"]["<<idir<<"]="<<nx[at] [idir].second<<LF;
		// const auto nxpt=nx[at] [idir].second;
		build(nx[at] [idir].second-=dv);
	}
}

vec<Pos> stack; std::unordered_map<Pos, bool> instack;
std::unordered_map<Pos, uint> dfn, low, sccid; uint idx=0, sccidx=0;
std::unordered_map<uint,uint> sccsize; // sccid -> sccsize
uint zerozeroinsccid;
void tj(Pos at){
	dfn[at] = low[at] = idx++;
	stack.push_back(at); instack[at]=true;
	for(const auto &[nxcan, nxpos]:nx[at]){
		if(!nxcan) continue;
		if(!dfn[nxpos]){
			tj(nxpos);
			mize(low[at], low[nxpos]);
		}
		else if(instack[nxpos]){
			mize(low[at], dfn[nxpos]); // use dfn here instead of low, though both correct
		}
	}
	if(dfn[at]==low[at]){
		Pos cur;
		do{
			cur=stack.back();
			sccid[cur]=sccidx;
			sccsize[sccidx]++;
			instack[cur]=false; stack.pop_back();
		}while(cur != at);
		sccidx++;
	}
}

std::unordered_map<uint, std::pair<uint, vec<uint>>> sccprev; // sccid -> {indeg, nx}

int main(){
	std::ios::sync_with_stdio(false); cin.tie(nullptr);
	cin>>n;
	for(uint i=0;i<n;i++){
		cin>>pts[i].x>>pts[i].y;
		ptsin.insert(pts[i]);
		x2[pts[i].x].insert(pts[i].y);
		y2[pts[i].y].insert(pts[i].x);
	}
	build({0,0}); // -> nx is ready, a directed graph with loops
// for(const auto &at:vis){
// 	for(uint jdir=0;jdir<4;jdir++){
// 		const auto &curnx=nx[at][jdir];
// 		if(!curnx.first){
// 			continue;
// 		}
// 		cout<<"`nx` of "<<at<<" in dir #"<<jdir<<" is "<<curnx.second<<LF;
// 	}
// }
	// tarjan
	// for(const auto &[pos, _]:nx){
	// 	if(!dfn[pos]){
	// 		tj(pos);
	// 	}
	// }
	tj({0,0}); // we only care bump points that can be reached from (0,0)
	// make scc tree
	for(const auto &[pos, nxs]:nx){
		for(const auto &[nxcan, nxpos]:nxs){
			if(!nxcan) continue;
			if(sccid[pos] == sccid[nxpos]) continue;
			sccprev[sccid[nxpos]].second.push_back(sccid[pos]);
// cout<<pos<<"'s next scc has pos "<<nxpos<<LF;
			sccprev[sccid[pos]].first++; // next poses
		}
	}
// for(const auto &[pos, _]:nx){
// 	cout<<pos<<" is in scc "<<sccid[pos]<<LF;
// }
	// dp
	std::queue<uint>q;
	vec<uint>maxsub(sccidx);
	for(uint sccidi=0;sccidi<sccidx;sccidi++){
		if(sccprev[sccidi].first==0){
			q.push(sccidi); // leaf
			// maxtouch[sccidi]=sccsize[sccidi];
// cout<<"Got leaf scc "<<sccidi<<LF;
		}
	}
	while(!q.empty()){
		auto cur=q.front(); q.pop();
		for(const auto &prev:sccprev[cur].second){
			maxe(maxsub[prev], maxsub[cur]+sccsize[cur]);
			--sccprev[prev].first;
			if(sccprev[prev].first==0)
				q.push(prev);
		}
	}
	zerozeroinsccid = sccid[{0,0}];
	uint ans=maxsub[zerozeroinsccid]+sccsize[zerozeroinsccid];
	cout<<ans<<LF;
	return 0;
}
/*
5
1 0
0 -3
0 3
2 2
2 -2

4
1 1
1 -1
-1 1
-1 -1

4
0 1
0 -1
1 0
-1 0
*/
/*
5
1
1
*/