#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int MAXN = 2000000;               // 预处理 pi 的上界
vector<int> primes;
int pi_small[MAXN + 1];                 // pi_small[x] = 小于等于 x 的质数个数

// 线性筛，同时计算 pi_small
void sieve(int n) {
    vector<bool> is_prime(n + 1, true);
    is_prime[0] = is_prime[1] = false;
    pi_small[0] = pi_small[1] = 0;
    for (int i = 2; i <= n; ++i) {
        if (is_prime[i]) {
            primes.push_back(i);
            pi_small[i] = pi_small[i - 1] + 1;
        } else {
            pi_small[i] = pi_small[i - 1];
        }
        for (int p : primes) {
            if ((ll)i * p > n) break;
            is_prime[i * p] = false;
            if (i % p == 0) break;
        }
    }
}

// 记忆化 phi 函数
map<pair<ll, int>, ll> phi_cache;

ll phi(ll x, int a) {
    if (a == 0) return x;
    if (a == 1) return x - x / 2;
    if (x < (ll)primes[a - 1]) return 1;
    auto key = make_pair(x, a);
    if (phi_cache.find(key) != phi_cache.end())
        return phi_cache[key];
    return phi_cache[key] = phi(x, a - 1) - phi(x / primes[a - 1], a - 1);
}

// 整数平方根、立方根、四次方根（避免浮点误差）
int int_sqrt(ll n) {
    int r = (int)sqrt(n);
    while ((ll)r * r <= n) ++r;
    while ((ll)r * r > n) --r;
    return r;
}
int int_cbrt(ll n) {
    int r = (int)cbrt(n);
    while ((ll)r * r * r <= n) ++r;
    while ((ll)r * r * r > n) --r;
    return r;
}
int int_fourth_root(ll n) {
    int r = (int)pow(n, 0.25);
    while ((ll)r * r * r * r <= n) ++r;
    while ((ll)r * r * r * r > n) --r;
    return r;
}

// Lehmer 算法计算 pi(x)
ll pi(ll x) {
    if (x <= MAXN) return pi_small[x];
    int a = pi(int_fourth_root(x));
    int b = pi(int_sqrt(x));
    int c = pi(int_cbrt(x));
    ll res = phi(x, a) + (ll)(b + a - 2) * (b - a + 1) / 2;
    for (int i = a + 1; i <= b; ++i) {
        ll w = x / primes[i - 1];
        res -= pi(w);
        if (i <= c) {
            int bi = pi(int_sqrt(w));
            for (int j = i; j <= bi; ++j) {
                res -= pi(w / primes[j - 1]) - (j - 1);
            }
        }
    }
    return res;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    sieve(MAXN);

    ll a, c;
    cin >> a >> c;

    ll target = pi(a - 1) + c;      // 目标质数总数
    ll lo = a;
    ll hi = a + c * 30;              // 粗略上界
    if (hi < a) hi = a;             // 防止溢出

    // 倍增找到足够大的上界
    while (pi(hi) < target) {
        hi *= 2;
    }

    // 二分查找最小的 b
    while (lo < hi) {
        ll mid = lo + (hi - lo) / 2;
        if (pi(mid) >= target) {
            hi = mid;
        } else {
            lo = mid + 1;
        }
    }

    cout << lo << '\n';
    return 0;
}