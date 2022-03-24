#include <iostream>
#include <queue>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;
typedef pair<int, int> PI;

int tc, n, m, t, s, g, h, a, b, d, x, cur, nxt, ndst, sum, cnt;
int dst[3][2001], vis[2001], an[2001];
vector<PI> nd[2001];
priority_queue<PI, vector<PI>, greater<PI>> q;

void sol(int u, int v) {
	memset(vis, 0, sizeof(vis)); fill(dst[v], dst[v] + n + 1, 2e9); q = {};
	dst[v][u] = 0; q.push({ 0,u }); while (q.size()) {
		do {
			cur = q.top().second; q.pop();
		} while (q.size() && vis[cur]);
		if (vis[cur]) break;
		vis[cur] = 1;

		for (auto& i : nd[cur]) {
			nxt = i.first; ndst = i.second;
			if (dst[v][nxt] > dst[v][cur] + ndst) {
				dst[v][nxt] = dst[v][cur] + ndst;
				q.push({ dst[v][nxt],nxt });
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(0), cin.tie(0);
	cin >> tc; while (tc--) {
		cin >> n >> m >> t >> s >> g >> h; cnt = 0;
		for (int i = 0; i <= n; ++i) nd[i] = {};
		while (m--) {
			cin >> a >> b >> d; if ((a == g && b == h) || (a == h && b == g)) sum = d;
			nd[a].push_back({ b,d }); nd[b].push_back({ a,d });
		}
		sol(s, 0); sol(g, 1); sol(h, 2);
		while (t--) {
			cin >> x;
			if ((dst[0][x] == dst[0][g] + sum + dst[2][x]) ||
				(dst[0][x] == dst[0][h] + sum + dst[1][x])) an[cnt++] = x;
		}
		sort(an, an + cnt); for (int i = 0; i < cnt; ++i) cout << an[i] << ' ';
		cout << '\n';
	}
}