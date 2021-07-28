#include <iostream>
#include <vector>
using namespace std;

int n, m, idx, w, cnt[100010];
vector<int> adj[100010];

void dfs(int v, int par) {
	if (v != 1) cnt[v] += cnt[par];    // 직속 상사의 칭찬 정도만큼 증가
	for (int i : adj[v]) {
		if (i == par) continue;
		dfs(i, v);
	}
}

int main() {
	ios::sync_with_stdio(0), cin.tie(0);
	cin >> n >> m;
	for (int i = 1; i <= n; ++i) {
		cin >> idx;
		adj[i].push_back(idx); adj[idx].push_back(i);
	}
	while (m--) {
		cin >> idx >> w; cnt[idx] += w;
	}
	dfs(1, -1);
	for (int i = 1; i <= n; ++i) cout << cnt[i] << ' ';
}