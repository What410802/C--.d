#include<iostream>
using std::cin, std::cout, std::endl;
#include<vector>
using uch = unsigned char;
using ush = unsigned short;
using uint = unsigned int;
using ull = unsigned long long;
using ll = long long;
#define _ noexcept

constexpr uint MOD=1e9+7;
ull n,k;

int main()_{
    cin >> n >> k;
    ull m = n / k;

    // 预处理阶乘和逆元到 2m
    std::vector<ull> fac(2 * m + 1), invfac(2 * m + 1), inv(m + 1);
    fac[0] = 1;
    for (int i = 1; i <= 2 * m; i++) {
        fac[i] = fac[i - 1] * i % MOD;
    }

    auto qpow = [&](long long a, int b) {
        long long res = 1;
        while (b) {
            if (b & 1) res = res * a % MOD;
            a = a * a % MOD;
            b >>= 1;
        }
        return res;
    };

    invfac[2 * m] = qpow(fac[2 * m], MOD - 2);
    for (int i = 2 * m - 1; i >= 0; i--) {
        invfac[i] = invfac[i + 1] * (i + 1) % MOD;
    }
    for (int i = 1; i <= m; i++) {
        inv[i] = qpow(i, MOD - 2);
    }

    // 预计算 k 的幂
    vector<long long> powk(m + 1);
    powk[0] = 1;
    for (int i = 1; i <= m; i++) {
        powk[i] = powk[i - 1] * k % MOD;
    }

    long long ans = 0;
    for (int t = 1; t <= m; t++) {
        int up = m + t - 1;
        int down1 = m - t;
        int down2 = 2 * t - 1;
        long long c = fac[up] * invfac[down1] % MOD * invfac[down2] % MOD;
        long long term = powk[t] * m % MOD * inv[t] % MOD * c % MOD;
        ans = (ans + term) % MOD;
    }

    cout << ans << endl;
    return 0;
}