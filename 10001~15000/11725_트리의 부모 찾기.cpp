#include <iostream>
#include <vector>
using namespace std;

int N;
int res[100010];
vector<int> adj[100010];

void dfs(int v, int par) {
	for (int i : adj[v]) {
		if (i == par) continue;
		res[i] = v;    // 노드의 부모 저장
		dfs(i, v);
	}
}

int main() {
	ios::sync_with_stdio(0), cin.tie(0);
	cin >> N;
	for (int i = 0; i < N - 1; ++i) {
		int u, v; cin >> u >> v;
		adj[u].push_back(v); adj[v].push_back(u);
	}
	dfs(1, -1);
	for (int i = 2; i <= N; ++i) {
		cout << res[i] << '\n';
	}
}