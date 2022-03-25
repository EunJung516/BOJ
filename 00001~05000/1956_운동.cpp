#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
typedef pair<int, int> PI;

int v, e, a, b, c, cur, nxt, ndst, an = 2e9, vis[401], dst[401];
vector<PI> nd[401];
priority_queue<PI, vector<PI>, greater<PI>> q;

int main() {
	ios::sync_with_stdio(0), cin.tie(0);
	cin >> v >> e; while (e--) {
		cin >> a >> b >> c; nd[a].push_back({ b,c });
	}
	for (int i = 1; i <= v; ++i) {
		fill(vis, vis + v + 1, 0); fill(dst, dst + v + 1, 2e9); q = {};
		for (auto& j : nd[i]) {
			dst[j.first] = j.second; q.push({ j.second, j.first });
		}
		while (q.size()) {
			do {
				cur = q.top().second; q.pop();
			} while (q.size() && vis[cur]);
			if (vis[cur]) break;
			if (cur == i) {
				an = min(an, dst[cur]); break;
			}
			vis[cur] = 1;
			for (auto& j : nd[cur]) {
				nxt = j.first; ndst = j.second;
				if (dst[nxt] > dst[cur] + ndst) {
					dst[nxt] = dst[cur] + ndst; q.push({ dst[nxt], nxt });
				}
			}
		}
	}
	cout << (an == 2e9 ? -1 : an);
}