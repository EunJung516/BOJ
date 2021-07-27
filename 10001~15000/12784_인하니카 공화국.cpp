#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int T, N, M, u, v, d;
int dp[1010][2], D[1010][1010];
vector<int> adj[1010];

void dfs(int idx, int par) {
	if (idx != 1 && adj[idx].size() == 1) {    // 1번섬을 제외한, 다리가 하나밖에 없는 섬인 경우
		dp[idx][0] = D[idx][par];
		dp[idx][1] = 2e9;
		return;
	}

	dp[idx][0] = D[idx][par];    // 부모와 자신의 다리를 끊는 경우
	dp[idx][1] = 0;    // 부모를 제외한, 연결된 다리 중 일부를 끊는 경우
	for (int i : adj[idx]) {
		if (i == par) continue;
		dfs(i, idx);
		dp[idx][1] += min(dp[i][0], dp[i][1]);
	}
}

int main() {
	ios::sync_with_stdio(0), cin.tie(0);
	cin >> T; while (T--) {
		cin >> N >> M; 
		for (int i = 1; i <= N; ++i) adj[i].clear();
		
		while (M--) {
			 cin >> u >> v >> d;
			 adj[u].push_back(v); adj[v].push_back(u);
			 D[u][v] = D[v][u] = d;
		}
		dfs(1, 0);
		cout << dp[1][1] << '\n';    // 최소 다이너마이트의 개수 출력
	}
}