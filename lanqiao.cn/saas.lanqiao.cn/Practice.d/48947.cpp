#include<iostream>
using std::cin, std::cout, std::endl;
#include<vector>
#include<algorithm>
// #include<utility>
#include<numeric>
using uint = unsigned int;
using ull = unsigned long long;
using ll = long long;
using uch = unsigned char;
#define _ noexcept

uint n;
#define N 11
uint tb[N], te[N], tl[N];
using Order = std::vector<uch>;
bool viable(const Order &order)_{
	uint curr_t = 0;
	for(const auto no:order){
		if(curr_t > te[no]){
			return false;
		}
		curr_t = (curr_t < tb[no] ? tb[no] : curr_t) + tl[no];
	}
	return true;
}

int main()_{
	std::ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	uint t;
	cin>>t;
	while(t--){
		cin>>n;
		for(uint i=0;i<n;i++){
			cin>>tb[i]>>te[i]>>tl[i]; te[i]+=tb[i];
		}
		Order order(n);
		std::iota(order.begin(), order.end(), static_cast<uch>(0));
		do{
			if(viable(order)){
				cout<<"YES"<<endl;
				goto _next_cycle;
			}
		}while(std::next_permutation(order.begin(), order.end()));
		cout<<"NO"<<endl;
		_next_cycle:;
	}
	return 0;
}