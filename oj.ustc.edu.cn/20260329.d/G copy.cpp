#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    while (T--) {
        int n, m, r, c;
        cin >> n >> m >> r >> c;
        vector<vector<int>> f(n + 1, vector<int>(m + 1));
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= m; ++j) {
                cin >> f[i][j];
            }
        }

        // 计算每个点的整数步长 (dx, dy)
        vector<vector<int>> dx(n + 1, vector<int>(m + 1, 0));
        vector<vector<int>> dy(n + 1, vector<int>(m + 1, 0));
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= m; ++j) {
                if (i == 1) {
                    dx[i][j] = 2 * (f[2][j] - f[1][j]);
                } else if (i == n) {
                    dx[i][j] = 2 * (f[n][j] - f[n - 1][j]);
                } else {
                    dx[i][j] = f[i + 1][j] - f[i - 1][j];
                }
                if (j == 1) {
                    dy[i][j] = 2 * (f[i][2] - f[i][1]);
                } else if (j == m) {
                    dy[i][j] = 2 * (f[i][m] - f[i][m - 1]);
                } else {
                    dy[i][j] = f[i][j + 1] - f[i][j - 1];
                }
            }
        }

        // 找出全局最小值
        int min_val = INT_MAX;
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= m; ++j) {
                if (f[i][j] < min_val) {
                    min_val = f[i][j];
                }
            }
        }
        vector<vector<bool>> is_min(n + 1, vector<bool>(m + 1, false));
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= m; ++j) {
                if (f[i][j] == min_val) {
                    is_min[i][j] = true;
                }
            }
        }

        // 起点梯度
        int dx0 = dx[r][c], dy0 = dy[r][c];
        if (dx0 == 0 && dy0 == 0) {
            cout << "Impossible\n";
            continue;
        }

        // 计算最大的 k 使得第一步不越界
        int Kmax = INT_MAX;
        if (dx0 > 0) {
            Kmax = min(Kmax, (r - 1) / dx0);
        } else if (dx0 < 0) {
            Kmax = min(Kmax, (n - r) / (-dx0));
        }
        if (dy0 > 0) {
            Kmax = min(Kmax, (c - 1) / dy0);
        } else if (dy0 < 0) {
            Kmax = min(Kmax, (m - c) / (-dy0));
        }
        if (Kmax <= 0) {
            cout << "Impossible\n";
            continue;
        }

        // 准备时间戳数组
        int total = n * m;
        vector<int> vis(total + 1, 0); // 1-indexed
        int cur_time = 0;
        int ans = -1;

        // 从大到小枚举 k
        for (int k = Kmax; k >= 1; --k) {
            ++cur_time;
            int i = r, j = c;
            bool found = false;
            while (true) {
                int idx = (i - 1) * m + j;
                if (vis[idx] == cur_time) {
                    // 循环
                    break;
                }
                vis[idx] = cur_time;
                if (is_min[i][j]) {
                    found = true;
                    break;
                }
                int ni = i - k * dx[i][j];
                int nj = j - k * dy[i][j];
                if (ni < 1 || ni > n || nj < 1 || nj > m) {
                    break;
                }
                i = ni;
                j = nj;
            }
            if (found) {
                ans = 2 * k;
                break;
            }
        }

        if (ans == -1) {
            cout << "Impossible\n";
        } else {
            cout << ans << '\n';
        }
    }
    return 0;
}