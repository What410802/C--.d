#include<iostream>
using std::cin, std::cout, std::endl;
#include<vector>
#include<array>
#include<algorithm>
using uint = unsigned int;
using ull = unsigned long long;
using ll = long long;
using uch = unsigned char;
#define _ noexcept

using M = std::array<std::array<uint, 3>, 3>;

constexpr M rotate(const M& m)_{
	M res{};
	for(uint i=0; i<3; i++)
		for(uint j=0; j<3; j++)
			res[i][j] = m[2-j][i];
	return res;
}
constexpr M flipH(const M& m)_{
	M res{};
	for(uint i=0; i<3; i++)
		for(uint j=0; j<3; j++)
			res[i][j] = m[i][2-j];
	return res;
}

constexpr bool Mmatch(const M& candidate, const M& input)_{ // ignoring 0
	for(uint i=0; i<3; i++)
		for(uint j=0; j<3; j++){
			if (input[i][j] && input[i][j] != candidate[i][j])
				return false;
		}
	return true;
}

void Mout(const M& m)_{
	for(uint i=0; i<3; i++){
		for(uint j=0; j<3; j++){
			cout<<m[i][j];
			if(j<2)
				cout<<' ';
		}
		cout<<endl;
	}
}

constexpr M BASE{{
	{4, 9, 2},
	{3, 5, 7},
	{8, 1, 6},
}};
constexpr std::array<M, 8> generate_8()_{
	std::array<M, 8> ret{BASE};
	ret[1] = rotate(ret[0]);
	ret[2] = rotate(ret[1]);
	ret[3] = rotate(ret[2]);
	ret[4] = flipH(ret[0]);
	ret[5] = flipH(ret[1]);
	ret[6] = flipH(ret[2]);
	ret[7] = flipH(ret[3]);
	return ret;
}

int main()_{
	std::ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	constexpr auto templates = generate_8();
	M input;
	for(auto& row:input)
		for(uint& x:row)
			cin>>x;

	std::vector<M> sol;
	sol.reserve(1);
	for(const auto& cand:templates){
		if(Mmatch(cand, input)){
			if(!sol.empty()){
				cout<<"Too Many"<<endl;
				return 0;
			}
			sol.push_back(cand);
		}
	}
	Mout(sol.front());
	return 0;
}