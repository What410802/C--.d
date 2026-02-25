#include<iostream>
using std::cin, std::cout, std::endl;
#include<map>
#include<functional>
using uint = unsigned int;
using ull = unsigned long long;
using ll = long long;
using uch = unsigned char;
#define _ noexcept

std::map<uint, uint> map; // turn a prime into its first appearance in the 0~n seq.
void update_map(const uint k, const uint v, const std::function<void(uint &, const uint)> &update = [](uint &dst, const uint src){dst = src;}, const std::function<void(uint, uint)> &callback1 = [](...){})_{
	const auto fnd=map.find(k);
	if(fnd==map.end()){
		map.emplace(k,v);
		callback1(k,v);
	}
	else{
		update(fnd->second, v);
	}
}

int main()_{
	std::ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	uint n; cin>>n;
	uint p1=n,p2=n;
	for(uint i=0,d;i<n;i++){
		cin>>d;
		if(d==1){
			continue;
		}
		const std::function<void(uint &, const uint)> update = [&p1, &p2](uint &oldv, const uint newv){ // This is the time when a fac is being updated the second time or more.
			if(oldv < p1 || (oldv == p1 && newv < p2)){ // minimizing p's, according to the problem.
				p1 = oldv; p2 = newv;
			}
		};
		const std::function<void(const uint, const uint)> cb1 = [](...){}; // The first time for factor fac
		if(!(d&1)){
			update_map(2, i, update, cb1); // Should not update if the k,v already exist
			do{
				d>>=1;
			}while(!(d&1));
		}
		for(uint fac=3;fac*fac<=d;fac+=2){
			if(d%fac==0){
				update_map(fac, i, update, cb1);
				do{
					d/=fac;
				}while(d%fac==0);
			}
		}
		if(d>1){
			update_map(d, i, update, cb1);
		}
	}
	++p1; ++p2; cout<<p1<<' '<<p2<<endl;
	return 0;
}