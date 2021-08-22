#include <iostream>
#include <queue>
#include <vector>
using namespace std;
typedef pair<int, int> PI;

int n, m, k, a, b, c, vis[1010];
vector<PI> adj[1010];
vector<int> dis[1010];
priority_queue<PI, vector<PI>, greater<PI>> q;

int main() {
	ios::sync_with_stdio(0), cin.tie(0);
	cin >> n >> m >> k; while (m--) {
		cin >> a >> b >> c; adj[a].push_back({ b,c });
	}

	q.push({ 0,1 });
	while (!q.empty()) {
		int cur, cdis;
		do {
			cdis = q.top().first;
			cur = q.top().second;
			q.pop();
		} while (!q.empty() && vis[cur]);
		if (vis[cur]) break;
		if (dis[cur].size() > k) continue;  // k 번째 방문한 경로가 계산된 경우
		dis[cur].push_back(cdis);

		for (auto& i : adj[cur]) {
			int nxt = i.first, ndis = i.second;
			q.push({ cdis + ndis,nxt });
		}
	}

	for (int i = 1; i <= n; ++i) {
		if (dis[i].size() >= k) cout << dis[i][k - 1] << '\n';  // k 번째 최단경로 출력
		else cout << "-1\n";  // k 번째 최단경로가 존재하지 않는 경우
	}
}