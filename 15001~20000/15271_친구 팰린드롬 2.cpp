#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, M, u, v, ans, a[210], b[210], vis[210];
vector<int> adj[210];

int dfs(int i) {  // 이분 매칭 활용
	vis[i] = 1;
	for (int j : adj[i]) {
		if (!b[j] || !vis[b[j]] && dfs(b[j])) {
			a[i] = j; b[j] = i;
			a[j] = i; b[i] = j;
			return 1;
		}
	}
	return 0;
}

int main() {
	ios::sync_with_stdio(0), cin.tie(0);
	cin >> N >> M; while (M--) {
		cin >> u >> v;
		if (u % 2 != v % 2) {  // 이성이고 친한 친구인 경우
			adj[u].push_back(v); adj[v].push_back(u);
		}
	}

	for (int i = 1; i <= N; ++i) {
		if (!a[i]) {  // 함께 춤 출 친구가 아직 없는 경우
			fill(vis, vis + N + 1, 0);
			if (dfs(i)) ans += 2;  // 함께 춤 출 친구가 있는 경우
		}
	}
	if (N - ans) cout << ans + 1;  // 로봇 춤을 출 친구가 존재하는 경우
	else cout << ans;
}