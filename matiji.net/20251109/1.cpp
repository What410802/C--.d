#include<cstdio>
typedef unsigned int uint;
typedef unsigned long long ull;
typedef long long ll;

uint a,b,l;
bool o[60]; // From low to high!
void fill_after(const uint i){
	for(uint j=0;j<i;j++){
		o[j]=true;
	}
}
void out(){
	for(int i=l-1;i>=0;i--){
		putchar(o[i]?'b':'a');
	}
}

int main(){
    ull k;
    scanf("%u%u%llu", &a, &b, &k); l=a+b; k--;
	uint last_bit_to=l+1;
    for(int i=b-1;i>=0;i--){
		if(k==0){
			o[i]=true;
			fill_after(i);
			out();
			return 0;
		}
		ull test=1ull, test_hist; // to=i+1
		if(k==test){
			o[i+1]=true;
			fill_after(i);
			out();
			return 0;
		} /// k!=0 here
        for(uint to=i+2;;to++){
			if(k==(test_hist=test, test=test*(to)/(to-(i+1)/*+1*/))){ // i is order here
				o[to]=true; /// last_bit_to
				fill_after(i);
				out();
				return 0;
			}
			else if(k<test){
				k-=test_hist;
				o[last_bit_to=to-1]=true;
				// printf("#filled: %u; k-=%llu\n",last_bit_to,test_hist);
				break;
			}
			// printf("#i=%u,to=%u: test=%llu\t=...+%llu\n",i,to,test,test_hist*to%(to-(i+1)));
			if(to+1==last_bit_to){
				k-=test;
				o[last_bit_to=to]=true;
				// printf("#Warn: to==last_bit_to-1==%u\n",to);
				break;
			}
		}
		// printf("#Bit %u summary: test=%llu, test_hist=%llu\n",i,test,test_hist);
    }
	out();
    return 0;
}

/*
// 第i+1位非b：第i位b向左移动一格：加1<<i
// 第i位b向左移动一格后，其右侧b可全归右

// 故获取某排列序数的方法：从右向左依次将b归右，累加1<<(Delta i)
将右侧连续i个b的最左侧的b向左移至o[h]所经过(+=)的排列数（左闭右开）：C_{h}^{i} == h!/(i!(h-i)!); 
C_{h+1}^{i} == (h+1)!/(i!(h-i+1)!) == C_{h}^{i}*(h+1)/(h-i+1).
Used above: C_{h}^{i} == prev*(h)/(h-bi)
*/