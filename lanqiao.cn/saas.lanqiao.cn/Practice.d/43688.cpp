#include<iostream>
using std::cin, std::cout, std::endl;
#include<string>
#include<array>
#include<algorithm>
#include<type_traits>
#include<cmath>
// #include<cstdint>

using uint = unsigned int;
using ull = unsigned long long;
using ll = long long;
using uch = unsigned char;

/*
template<typename T, typename = std::enable_if_t<std::is_integral_v<T>>>
std::string to_base_custom(T value, const std::string& digit_set = "0123456789ABCDEF"){
	const auto base = digit_set.size();
	using uT = std::make_unsigned_t<T>;
	const bool is_negative = value < 0;
	uT uv = static_cast<uT>(is_negative ? -value : value);
	
	std::string result;
	do{
		result.push_back(digit_set[uv%base]);
		uv /= base;
	}while(uv > 0);
	if(is_negative) {
		result.push_back('-');
	}
	
	std::reverse(result.begin(), result.end());
	return result.empty() ? "0" : result;
}
*/


// Observe per digit (in Excel's format), we can notice that (if have) the 0-th place str[0] = 'A' + (v - 1)%26; str[1] = 'A' + (v - 27)/26%26; ...

template<typename T, std::size_t N>
constexpr std::array<T, N + 1> generate_powers(T base){
	std::array<T, N + 1> arr{};
	T val = 1;
	for(std::size_t i = 0; i <= N; ++i, val *= base){
		arr[i] = val;
	}
	return arr;
}
constexpr auto pow26n = generate_powers<ull, 9>(26);
constexpr ull prefixpow(const std::size_t i){ // [0,i)-th
	return (pow26n[i] - 1)/(25);
}

// constexpr char preA = 'A' - 1;
template<typename uT>
std::string to_Excel_y(uT uv){
	const uint len = static_cast<uint>(std::logl((ull)uv*25 + 1)/std::logl(26) +1e-6L); // floor
cout<<len<<"#"<<endl;
	// uv -= pow26n[len-1]; // Brought by the length. After this, can directly from AA...A to ZZ...Z
	std::string result; result.resize(len);
	for(uint i=len-1;i<len;i--){
		result[i]='A' + (uv - prefixpow(i+1))/pow26n[i]%26;
		// uv%=pow26n[i];
	}
	std::reverse(result.begin(), result.end());
	return result;
}

int main(){
	cin.tie(nullptr);
	std::ios::sync_with_stdio(false);
	uint n;
	cin>>n;
	cout<<to_Excel_y(n)<<endl;
	return 0;
}