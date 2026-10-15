#include<iostream>
#include<vector>
using namespace std;
using ull = unsigned long long;

// ============ 距离类型：带 +inf 语义 ============
// 说明：不能写成 struct D : ull —— 基础类型不能做基类（编译不过）。只能组合。
class Dist {
	static constexpr ull INFBIT = 1ull << 63;   // 最高位为 inf 标志位
	ull v;
public:
	Dist() : v(INFBIT) {}                       // 默认构造 = inf（关键：数组/vector 默认全不可达）
	explicit Dist(ull x) : v(x) {}              // explicit：禁止隐式混算
	bool isinf() const { return (v & INFBIT) != 0; }
	ull  val()  const { return v; }

	friend Dist operator+(const Dist& a, const Dist& b){
		// 必须显式处理 inf+inf：单纯靠标志位会回绕成 0
		return (a.isinf() || b.isinf()) ? Dist(INFBIT) : Dist(a.v + b.v);
	}
	friend bool operator>(const Dist& a, const Dist& b){
		if (a.isinf() != b.isinf()) return a.isinf();   // inf 大于任何有限值
		if (a.isinf()) return false;                    // inf 不大于 inf
		return a.v > b.v;
	}
	friend bool operator<(const Dist& a, const Dist& b){ return b > a; }
	friend bool operator==(const Dist& a, const Dist& b){
		if (a.isinf() || b.isinf()) return a.isinf() && b.isinf();
		return a.v == b.v;
	}
};

static uint32_t pm[1 << 16];   // 静态区，避免 256KB 栈数组

int main(){
	ios::sync_with_stdio(false); cin.tie(nullptr);
	int n, m, k;
	if(!(cin >> n >> m >> k)) return 0;

	// 按实际规模开数组，不再依赖 NC=16 / M=5009 的硬编码
	vector<vector<uint32_t>> price(n, vector<uint32_t>(m));
	for(int i = 0; i < n; i++) for(int j = 0; j < m; j++) cin >> price[i][j];

	const int V = n + 1, SCH = n;          // 学校编号 = n
	vector<Dist> dist(V * V);              // 默认全 inf
	for(int i = 0; i < V; i++) dist[i * V + i] = Dist(0);
	for(int e = 0; e < k; e++){
		int u, v; ull w; cin >> u >> v >> w; --u; --v;
		if(Dist(w) < dist[u * V + v]) dist[u * V + v] = dist[v * V + u] = Dist(w);  // 重边取小
	}
	for(int kk = 0; kk < V; kk++)
		for(int i = 0; i < V; i++)
			for(int j = 0; j < V; j++){
				Dist s = dist[i * V + kk] + dist[kk * V + j];
				if(dist[i * V + j] > s) dist[i * V + j] = s;
			}

	const int T = 1 << n;
	vector<Dist> tsp(T * n);               // 默认全 inf
	for(int i = 0; i < n; i++) tsp[(1 << i) * n + i] = dist[SCH * V + i];
	for(int mask = 1; mask < T; mask++)
		for(int i = 0; i < n; i++){
			if(!(mask >> i & 1)) continue;
			Dist cur = tsp[mask * n + i];
			// if (cur.isinf()) continue;   // 可选剪枝；不写也正确（inf+有限=inf）
			for(int j = 0; j < n; j++){
				if(mask >> j & 1) continue;
				Dist& t = tsp[(mask | (1 << j)) * n + j];
				Dist s = cur + dist[i * V + j];
				if(t > s) t = s;
			}
		}

	vector<ull> purchase(T, 0);            // 购买费用是普通整数，默认 0，别用 Dist
	for(int j = 0; j < m; j++){
		pm[0] = 0xFFFFFFFFu;
		for(int i = 0; i < n; i++) pm[1 << i] = price[i][j];
		for(int mask = 1; mask < T; mask++){
			int i = __builtin_ctz((unsigned)mask);
			pm[mask] = min(pm[mask ^ (1 << i)], price[i][j]);
			purchase[mask] += pm[mask];
		}
	}

	Dist best;                             // 默认 inf
	for(int mask = 1; mask < T; mask++)
		for(int i = 0; i < n; i++){
			if(!(mask >> i & 1)) continue;
			Dist s = tsp[mask * n + i] + dist[SCH * V + i] + Dist(purchase[mask]);
			if(best > s) best = s;
		}
	cout << best.val() << '\n';
	return 0;
}
