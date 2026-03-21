#include<iostream>
using std::cin, std::cout, std::endl;
#include<list>
#include<map>
#include<utility>
#include<iterator>
// #include<functional>
// #include<limits>
using uint = unsigned int;
using ull = unsigned long long;
using ll = long long;
using uch = unsigned char;
#define _ noexcept

// using ListRecord = std::pair<ull, std::map<std::pair<ull,uint>,std::list<ListRecord>::iterator> >;
struct ListRecord{
	ull v;
	std::map<std::pair<ull, uint>, std::list<ListRecord>::iterator>::iterator map_it;
	inline ListRecord(const ull v)_: v(v){}
	inline ListRecord(const ull v, const decltype(map_it) map_it)_: v(v), map_it(map_it){}
};
std::list<ListRecord>seq; // (iterator to) value
std::map<std::pair<ull,uint>,std::list<ListRecord>::iterator>map; // {value,insert_time} to iterator

template<typename Map, typename Iterator, typename KeyModifier>
auto inline modify_key(Map& map, Iterator it, KeyModifier modify)_{
	auto node = map.extract(it);
	modify(node.key());
	return map.insert(std::move(node)).position;
}

template<typename ContainerIt, typename ProcessingF>
void inline out(ContainerIt begin, const ContainerIt &end, const ProcessingF &&f = [](const ContainerIt &it)_{return *it;})_{
	cout<<f(begin);
	for(++begin; begin != end; ++begin){
		cout<<' '<<f(begin);
	}
	cout<<endl;
}

int main()_{
	std::ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	uint n,k; cin>>n>>k;
	for(uint i=0;i<n;i++){
		ull in;
		cin>>in;
		seq.emplace_back(in);
		const auto list_in = std::prev(seq.end());
		const auto map_in = map.emplace(std::piecewise_construct, std::forward_as_tuple(in,1+i), std::forward_as_tuple(std::prev(seq.end()))).first; // +1 avoids 0-1 below
		list_in->map_it = map_in;
	}
	while(k--){
// out(seq.begin(), seq.end());
// for(auto it=map.begin(); it!=map.end(); ++it){
// 	cout<<it->first.first<<','<<it->first.second<<"->"<<*it->second<<endl;
// }
		// map.begin() points to the elem to be deleted. find -> mod -> del
		const auto &deleting = map.begin()->second; // in list
		if(deleting != seq.begin()){
			const auto deleting_prev = std::prev(deleting);
			// const auto map_prev = std::prev(map.upper_bound({*deleting_prev, map.begin()->first.second - 1}));
// cout<<'#'<<*deleting_prev<<'#'<<*deleting<<'#'<<endl;
// cout<<'$'<<map_prev->first.second<<'$'<<endl;
			deleting_prev->map_it = modify_key(map, deleting_prev->map_it, [deleting](auto &k){k.first += deleting->v;});
			deleting_prev->v += deleting->v;
		}
		if(std::next(deleting) != seq.end()){
			const auto deleting_next = std::next(deleting);
			// const auto map_next = map.lower_bound({*deleting_next, map.begin()->first.second + 1});
// cout<<*deleting_next<<endl;
// cout<<map_next->first.second<<endl;
			deleting_next->map_it = modify_key(map, deleting_next->map_it, [deleting](auto &k){k.first += deleting->v;}); // next; must found, but not exactly +/-1 (For example, when there are holes caused by deletion.)
			deleting_next->v += deleting->v;
		}
		seq.erase(deleting);
		map.erase(map.begin());
	}
	out(seq.begin(), seq.end(), [](const std::list<ListRecord>::iterator &it)_{return it->v;});
	return 0;
}