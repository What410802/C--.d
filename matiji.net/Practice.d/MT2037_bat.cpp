#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 7;

int n, m;
struct POSITION {
	int x, y;
};
vector<POSITION> v[N];
int ans;

int main() {
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++) {
			int num;
			cin >> num;
			v[num].push_back({i, j});
			int len = v[num].size();
			for (int k = 0; k < len; k++)
				ans += abs(v[num] [k].x - i) + abs(v[num] [k].y - j);
		}
	cout << ans << endl;
	return 0;
}