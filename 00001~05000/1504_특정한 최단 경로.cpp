#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <queue>
using namespace std;
typedef pair<long long, int> PI;

int n, e, a, b, c, cur, nxt, v1, v2, chk1[3], chk2[3], vis[801];
long long ndst, an = -1, dst1[3], dst2[3], dst[801];
vector<PI> nd[801];
priority_queue<PI, vector<PI>, greater<PI>> q;

void sol(int u, int v) {
	memset(vis, 0, sizeof(vis)); fill(dst, dst + n + 1, 2e9);
	dst[u] = 0; q.push({ 0,u }); while (q.size()) {
		if (chk1[v] && chk2[v]) break;
		do {
			cur = q.top().second; q.pop();
		} while (q.size() && vis[cur]);
		if (vis[cur]) break;
		vis[cur] = 1;

		if (cur == v1) {
			dst1[v] = dst[cur]; chk1[v] = 1;
		}
		if (cur == v2) {
			dst2[v] = dst[cur]; chk2[v] = 1;
		}

		for (auto& i : nd[cur]) {
			nxt = i.first; ndst = i.second;
			if (dst[nxt] > dst[cur] + ndst) {
				dst[nxt] = dst[cur] + ndst;
				q.push({ dst[nxt],nxt });
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(0), cin.tie(0);
	cin >> n >> e; while (e--) {
		cin >> a >> b >> c; nd[a].push_back({ b,c }); nd[b].push_back({ a,c });
	}
	cin >> v1 >> v2; for (int i = 0; i < 3; ++i) dst1[i] = dst2[i] = 2e9;
	sol(1, 0); sol(n, 1); sol(v1, 2);
	// 1 -> v1 -> v2 -> n
	if (dst1[0] != 2e9 && dst2[2] != 2e9 && dst2[1] != 2e9) an = dst1[0] + dst2[2] + dst2[1];
	// 1 -> v2 -> v1 -> n
	if (dst2[0] != 2e9 && dst2[2] != 2e9 && dst1[1] != 2e9) {
		if (an == -1) an = dst2[0] + dst2[2] + dst1[1];
		else an = min(an, dst2[0] + dst2[2] + dst1[1]);
	}
	cout << an;
}