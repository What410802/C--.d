typedef unsigned char ubyte;
typedef unsigned int uint;
typedef unsigned long long ull;
typedef long long ll;

#include<cstdio>
#include<map>
#include<utility>

#define N 1000002
#define MOD 998244353u
uint n;
struct node{
	uint nstr, npass;
	std::map<char,node *> children;
}root;

inline uint tri_in(){
	char c;
	node *cur=&root;
	uint ret=0;
	while ((c=getchar())!='\n'&&c!=EOF)
	{
		cur->npass++;
		if(cur->children.find(c)==cur->children.end()){
// printf("#new %c\n",c);
			cur=cur->children.insert(std::pair<char,node *>(c,new node({0,0,std::map<char,node *>()}))).first->second;
		}
		else{
// printf("#++ %c\n",c);
			cur=cur->children[c];
		}
		ret++;
	}
	cur->nstr++;
	return ret;
}

inline ull Cx2(const ull x){
	return x*(x-1)>>1;
}
inline ull get_publen(node *elem=&root, uint depth=0){
	ull ret=elem->nstr?depth*(Cx2(elem->nstr)%MOD+elem->npass*elem->nstr%MOD)%MOD:0;
// printf("#%u %u %u\n",elem->npass,elem->nstr,ret);
	for(auto &childp:elem->children){
		ret+=get_publen(childp.second, depth+1);
		ret%=MOD;
	}
// printf("#%u\n",ret);
	return ret;
}

int main(){
	scanf("%u",&n);
	getchar();
	uint totlen=0;
	for(uint i=0;i<n;i++){
		totlen+=tri_in();
	}
	ull publen=get_publen();
	printf("%llu",(totlen+(publen<<1))%MOD);
	return 0;
}