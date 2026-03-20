#include<iostream>
using std::cin, std::cout, std::endl;

using uch = unsigned char;
using ush = unsigned short;
using uint = unsigned int;
using ull = unsigned long long;
using ll = long long;
#define _ noexcept

uint n,m;
/*
	// {n,m}=={2, 1}: A
	// {n,m}=={>=3, 1}: B
	{n,m}==A/B{2,2}: A
	{n,m}==A{2,3}: ->B{2,2}: A
	{n,m}==A{2,>=4}: ->B{2,>=3}: B
	{n,m}==A{3,3}: ->B{2,3}: B
	{n,m}==A{3,4}: ->B{3,3}: ->A{2,3}: ... A
	{n,m}==A{3,5}: ->B{3,4}: ->A{2,4}: ... B
	{n,m}==A{4,4}: ->B{3,4}: ... B
	{n,m}==A{4,5}: ->B{4,4}: ->A{3,4}: ... A
	{n,m}==A{4,6}: ->B{4,5}: ->A{3,5}: ... B
*/

bool get_ans(uint n,uint m)_{
	if(n==2 && m==2){
		return true; // Alice
	}
	if(n==m){
		return false;
	}
	return (n<m?(m-n):(n-m))==1;
}

int main()_{
	std::ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	uint t; cin>>t;
	while(t--){
		cin>>n>>m;
		cout<<(get_ans(n,m) ? "Alice":"Bob")<<'\n';
	}
	return 0;
}