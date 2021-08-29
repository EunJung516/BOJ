#include <iostream>
#include <vector>
using namespace std;

int N, M, u, v, an, vis[1010];
vector<int> adj[1010];

void dfs(int a) {
	vis[a] = 1;
	for (int i : adj[a]) {
		if (!vis[i]) dfs(i);
	}
}

int main() {
	ios::sync_with_stdio(0), cin.tie(0);
	cin >> N >> M; while (M--) {
		cin >> u >> v; adj[u].push_back(v); adj[v].push_back(u);
	}
	for (int i = 1; i <= N; ++i) {
		if (!vis[i]) {
			dfs(i); ++an;
		}
	}
	cout << an;
}