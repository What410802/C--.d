#include<iostream>
using std::cin, std::cout, std::endl;
#include<cmath>
using uint = unsigned int;
using ull = unsigned long long;
using ll = long long;
using uch = unsigned char;

uint w;
class P{
	public:
	uint x,y;
	P(uint n){
		y = n/w;
		x = y&1 ? n%w : w - (1 + n%w);
	}
};
uint abs_minus(const uint a, const uint b){
	return a<b?b-a:a-b;
}

int main(){
	cin.tie(nullptr);
	std::ios::sync_with_stdio(false);
	uint m,n;
	cin>>w>>m>>n; m--; n--;
	P p1(m), p2(n);
cout<<"x"<<p1.x<<"y"<<p1.y<<endl;
cout<<"x"<<p2.x<<"y"<<p2.y<<endl;
	cout<<abs_minus(p1.x, p2.x) + abs_minus(p1.y, p2.y)<<endl;
	return 0;
}