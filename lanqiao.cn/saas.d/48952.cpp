#include<iostream>
using std::cin, std::cout, std::endl;
#include<random>
#include<vector>
#include<array>
using uint = unsigned int;
using ull = unsigned long long;
using ll = long long;
using uch = unsigned char;
#define _ noexcept
uint inline rand(const uint n)_{
	static std::random_device dev;
	static std::mt19937 gen(dev());
	std::uniform_int_distribution<> dist(0, n-1);
	return dist(gen);
}

uint n,k;
#define N 100002
uint root;
std::vector<std::pair<uint,uint>> e[N]; // to, w (needn't ull)
std::pair<uint,uint> fas[N]; // to, w
uint depths[N], euler_seq[N], euler_seq_end, order[N];
ull ds_to_root[N]; // ds[root] = 0

void dfs1(const uint cur, const uint fa, uint depth)_{ // Make fas
	depths[cur]=depth; depth++;
// cout<<'@'<<cur<<endl;
	for(auto it=e[cur].begin(); it!=e[cur].end();){
		if(it->first == fa){
			fas[cur] = *it;
			it = e[cur].erase(it);
		}
		else{
			ds_to_root[it->first] = ds_to_root[cur] + it->second;
			dfs1(it->first, cur, depth);
			++it;
		}
	}
}

uint highbit(uint x)_{
	x |= x >> 1;
	x |= x >> 2;
	x |= x >> 4;
	x |= x >> 8;
	x |= x >> 16;
	return x - (x >> 1);
}
uint log2(uint n)_{
	uint result = 0;
	if(n&0xffff0000) {result += 16; n >>= 16; }
	if(n&0x0000ff00) {result += 8; n >>= 8; }
	if(n&0x000000f0) {result += 4; n >>= 4; }
	if(n&0x0000000c) {result += 2; n >>= 2; }
	if(n&0x00000002) {result += 1; n >>= 1; }
	return result;
}

class LCA {
public:
	/**
	 * 构造函数，预处理 LCA 所需数据结构。
	 * @param n     节点数（节点编号 0..n-1）
	 * @param root  根节点编号
	 */
	template<typename E, typename Fas>
	LCA(const uint n, const uint root, E &es, Fas &fas_o)_
		: n(n), root(root), m((n<<1)-1), e(es), fas(fas_o)
	{
		first.resize(n, -1);
		dfs(root, 0);			// 欧拉遍历，得到 euler 和 depth
		// m = euler.size();		// 欧拉序列长度 = 2n-1
		build_rmq();			// 构建 ±1 RMQ 结构
	}

	/** 查询节点 u 和 v 的最近公共祖先 */
	uint query(uint u, uint v) const _{
		uint l = first[u], r = first[v];
		if (l > r) std::swap(l, r);
		uint pos = query_rmq(l, r);		// 在深度数组上查询最小值位置
		return euler[pos];
	}

private:
	const uint n, root, m;
	const std::vector<std::pair<uint,uint>> (&e)[N];
	const std::pair<uint,uint> (&fas)[N];
	std::vector<uint> euler, depth, first;	// 欧拉序列、对应深度、首次出现位置

	// ---------- ±1 RMQ 相关成员 ----------
	static constexpr uint B = 16;			// 分块大小（2^(B-1) 种模式可接受）
	std::vector<uint> block_min_idx;		// 每个块内最小值的全局索引
	// std::vector<int> block_first_depth;		// 每个块第一个元素的深度（未使用，可留作调试）
	std::vector<unsigned short> block_mask;	// 每个块的模式掩码（B-1 位）
	std::vector<std::vector<uint>> st;		// 块间稀疏表，存储最小值全局索引
	// std::vector<uint> log2_blk;				// 块数的对数表
	// pattern[mask][l][r] = 区间 [l,r] 内最小值的相对索引（0..B-1）
	std::vector<std::vector<std::vector<short>>> pattern;

	void dfs(uint u, uint d)_{
		first[u] = euler.size();
		euler.push_back(u);
		depth.push_back(d);
		for (const auto &[v, w]:e[u]){ // Already removed parent
			dfs(v, d + 1);
			euler.push_back(u);
			depth.push_back(d);
		}
	}

	void build_rmq()_{
		uint len = depth.size();
		uint num_blocks = (len + B - 1) / B;

		block_min_idx.resize(num_blocks);
		// block_first_depth.resize(num_blocks);
		block_mask.resize(num_blocks, 0);

		// 1. 扫描每个块，记录最小值位置和掩码
		for (uint b = 0; b < num_blocks; ++b) {
			uint start = b * B;
			uint end = std::min(start + B, len);
			uint min_pos = start;
			// block_first_depth[b] = depth[start];

			unsigned short mask = 0;
			for (uint i = start + 1; i < end; ++i) {
				if (depth[i] - depth[i-1] == 1)		// 上升 1
					mask |= (1u << (i - start - 1));
				// 下降时位保持 0
				if (depth[i] < depth[min_pos])
					min_pos = i;
			}
			block_min_idx[b] = min_pos;
			block_mask[b] = mask;
		}

		// 2. 构建块间稀疏表（存储全局索引，便于直接比较深度）
		// uint k = 0;
		// while ((1u << k) <= num_blocks) ++k;
		auto k = 1 + log2(num_blocks);
		st.assign(k, std::vector<uint>(num_blocks));
		for (uint b = 0; b < num_blocks; ++b) st[0][b] = block_min_idx[b];
		for (uint j = 1; j < k; ++j) {
			uint step = 1u << (j-1);
			for (uint b = 0; b + step < num_blocks; ++b) {
				uint left = st[j-1][b];
				uint right = st[j-1][b + step];
				st[j][b] = (depth[left] < depth[right]) ? left : right;
			}
		}

		// // 3. 块数的对数表
		// log2_blk.resize(num_blocks + 1);
		// for (uint i = 2; i <= num_blocks; ++i)
		// 	log2_blk[i] = log2_blk[i / 2] + 1;

		// 4. 预计算所有可能的块内模式（长度为 B 的 ±1 序列）
		precompute_patterns();
	}

	// 预计算所有可能的 ±1 序列的区间最小值位置
	void precompute_patterns()_{
		uint pattern_cnt = 1u << (B-1);		// 2^(B-1) 种形状
		pattern.assign(pattern_cnt, std::vector<std::vector<short>>(B, std::vector<short>(B, 0)));
		for (uint mask = 0; mask < pattern_cnt; ++mask) {
			// 根据掩码生成相对深度（第一个为 0）
			std::array<short, B> rel_depth;
			rel_depth[0] = 0;
			for (uint i = 1; i < B; ++i) {
				rel_depth[i] = rel_depth[i-1] + ((mask >> (i-1)) & 1 ? 1 : -1);
			}
			// 对每个左端点 l，向右扫描记录最小值位置（保留最左的相同最小值）
			for (uint l = 0; l < B; ++l) {
				short min_val = rel_depth[l];
				short min_pos = l;
				for (uint r = l; r < B; ++r) {
					if (rel_depth[r] < min_val) {
						min_val = rel_depth[r];
						min_pos = r;
					}
					pattern[mask][l][r] = min_pos;
				}
			}
		}
	}

	// 在深度数组上查询区间 [l, r] 的最小值位置（全局索引）
	uint query_rmq(uint l, uint r) const _{
		uint bl = l / B, br = r / B;
		uint start_l = bl * B, start_r = br * B;

		// 情况1：区间在同一块内
		if (bl == br) {
			auto mask = block_mask[bl];
			uint rel_l = l - start_l;
			uint rel_r = r - start_l;		// r must< start_l + B
			return start_l + pattern[mask][rel_l][rel_r];
		}

		// 情况2：跨越多个块
		// 左块部分 [l, 块尾]
		uint end_l = std::min(start_l + B - 1, m - 1);
		auto mask_l = block_mask[bl];
		uint rel_l = l - start_l;
		uint rel_r_l = end_l - start_l;
		uint pos_left = start_l + pattern[mask_l][rel_l][rel_r_l];

		// 右块部分 [块首, r]
		auto mask_r = block_mask[br];
		uint rel_l_r = 0;
		uint rel_r_r = r - start_r;
		uint pos_right = start_r + pattern[mask_r][rel_l_r][rel_r_r];

		// 中间完整块（如果存在）
		int pos_mid = -1;
		if (int L = bl + 1, R = br - 1; L <= R) {
			uint len = R - L + 1;
			// auto j = log2_blk[len];
			auto j = log2(len);
			auto left_idx = st[j][L];
			auto right_idx = st[j][R - (1 << j) + 1];
			pos_mid = (depth[left_idx] < depth[right_idx]) ? left_idx : right_idx;
		}

		// 取3者中深度最小的位置
		auto best = pos_left;
		if (depth[pos_right] < depth[best]) best = pos_right;
		if (pos_mid != -1 && depth[pos_mid] < depth[best]) best = pos_mid;
		return best;
	}
};

ull dis(uint a, uint b, LCA &lca)_{
// cout<<"Dis ("<<a<<","<<b<<")="<<ds_to_root[lca.query(a, b)]<<endl;
	return ds_to_root[a] + ds_to_root[b] - (ds_to_root[lca.query(a, b)]<<1);
}
ull diss[N];

int main()_{
	std::ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	cin>>n>>k;
	root = rand(n);
	for(uint i=1;i<n;i++){
		uint u,v,t; cin>>u>>v>>t; --u; --v;
		e[u].emplace_back(v,t);
		e[v].emplace_back(u,t);
	}
	dfs1(root, n, 0);
// cout<<'h'<<endl;
	LCA lca(n, root, e, fas);
	
	for(uint i=0;i<k;i++){
		cin>>order[i]; --order[i];
	}
	ull total=0;
	for(uint i=1;i<k;i++){
		total+=(diss[i]=dis(order[i-1], order[i], lca));
	}
	cout<<(total - diss[1]);
	for(uint i=1;i<k-1;i++){
		cout<<' '<<(total - (diss[i]+diss[i+1]) + dis(order[i-1], order[i+1], lca));
	}
	cout<<' '<<(total - diss[k-1])<<endl;
	return 0;
}