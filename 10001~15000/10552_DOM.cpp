#include <iostream>
#include <vector>
using namespace std;

int N, M, P, c, chk, vis[100010];
vector<int> adj[100010];

void dfs(int u) {
	vis[u] = 1; ++c;
	for (int i : adj[u]) {
		if (vis[i]) {  // 사이클인 경우 (무한정 바꿔야 하는 경우)
			chk = 1; return;
		}
		else dfs(i);

		if (chk) return;
	}
}

int main() {
	ios::sync_with_stdio(0), cin.tie(0);
	cin >> N >> M >> P; while (N--) {
		int a, b; cin >> a >> b; if(adj[b].empty()) adj[b].push_back(a);  // 비어있는 경우에만 저장
	}
	dfs(P);
	cout << (chk ? -1 : (c - 1));
}