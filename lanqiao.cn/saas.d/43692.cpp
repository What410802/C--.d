#include<iostream>
using std::cin, std::cout, std::endl;
#include<string>
#include<queue>
#include<set>
using uint = unsigned int;
using ull = unsigned long long;
using ll = long long;
using uch = unsigned char;

std::string src, dst;

int main(){
	cin.tie(nullptr);
	std::ios::sync_with_stdio(false);
	cin>>src>>dst;
	std::queue<std::pair<std::string, uint>>q;
	std::set<std::string>mem;
	q.emplace(src, 0);
	mem.emplace(src);
	while(!q.empty()){
		auto [curr, curr_step] = q.front();
		if(curr == dst){
			cout<<curr_step<<endl;
			return 0;
		}
		q.pop();
		curr_step++;
		const auto is_frog = [l = curr.length(), curr](const uint i)->bool {return i < l && curr[i] != '*';};
		for(uint i=0; i<curr.length(); i++){
			if(curr[i] == '*'){
				for(const int dir: {1,-1}){ // in 2 directions
					for(const int step: {1,2,3}){ // in different steps
						if(const uint tgt = i + dir*step; is_frog(tgt)){
							std::string tmp = curr; std::swap(tmp[tgt], tmp[i]);
							if(mem.find(tmp)==mem.end()){
								q.emplace(tmp, curr_step);
								mem.emplace(tmp);
							}
						}
						else{
							break; // Hole encountered or boundaries touched, so could not jump (in this direction)
						}
					}
				}
			}
		}
	}
	// return 0;
}