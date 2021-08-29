#include <iostream>
#include <cstring>
using namespace std;

int T, n, c, an, chk, adj[100010];
pair<int, int> vis[100010];

void dfs(int u, int v) {
	vis[u].first = v; vis[u].second = ++c;
	if (!vis[adj[u]].first) dfs(adj[u], v);
	else if (vis[adj[u]].first == v) an += vis[u].second - vis[adj[u]].second + 1;  // 사이클인 경우
}

int main() {
	ios::sync_with_stdio(0), cin.tie(0);
	cin >> T; while (T--) {
		cin >> n; c = an = 0; 
		for (int i = 1; i <= n; ++i) vis[i].first = vis[i].second = 0;

		for (int i = 1; i <= n; ++i) cin >> adj[i];
		for (int i = 1; i <= n; ++i) {
			if (!vis[i].first) dfs(i, c + 1);
		}
		cout << n - an << '\n';  // 속하지 못한 학생 수 출력
	}
}