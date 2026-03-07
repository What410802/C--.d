#include<iostream>
using std::cin, std::cout, std::endl;
#include<vector>
#include<algorithm>
using uint = unsigned int;
using ull = unsigned long long;
using ll = long long;
using uch = unsigned char;
#define _ noexcept

class Participant{
	public:
	uint n;
	uint t;
	// bool operator<(const Participant &p)const _{ // inferior to p
	// 	return n<p.n || (n==p.n && t>p.t);
	// }
	bool operator>(const Participant &p)const _{
		return n>p.n || (n==p.n && t<p.t);
	}
	friend std::ostream &operator<<(std::ostream &ostream, const Participant &p)_{
		ostream<<p.n<<' '<<p.t;
		return ostream;
	}
};

uint get_max_possible_t(const uint n)_{
	constexpr uint static max_basic_penalty_t_per_ac = 299;
	const uint max_additional_penalty_t_in_total_if_n_neq_0 = (300*30 - n)*20; // The worst case is that the last n submission is ac.
	return (n==0 ? 0 : max_additional_penalty_t_in_total_if_n_neq_0) + n * max_basic_penalty_t_per_ac;
}
Participant get_above(Participant p)_{
	if(p.t == 0){
		p.n++;
		p.t = get_max_possible_t(p.n);
	}
	else{
		p.t--;
	}
	return p;
}
void out_line(Participant last, Participant notin_first)_{
	cout<<last<<' '<<get_above(notin_first)<<endl;
}

int main()_{
	std::ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	uint g,s,b,h;
	cin>>g>>s>>b>>h;
	uint total = g+s+b+h;
	std::vector<Participant> participants(total);
	for(uint i=0;i<total;i++){
		cin>>participants[i].n>>participants[i].t;
	}
	std::sort(participants.begin(), participants.end(), std::greater<Participant>());
for(const auto &p:participants){
	cout<<'#'<<p<<endl;
}
	for(const auto line:{g,g+s,g+s+b}){
		out_line(participants[line-1], participants[line]);
	}
	return 0;
}