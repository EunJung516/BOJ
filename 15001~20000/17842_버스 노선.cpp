#include <iostream>
#include <vector>
using namespace std;

int N, p1, p2, ans;
vector<int> adj[200010];

void dfs(int v, int par) {
	if (adj[v].size() == 1) ++ans;    // 리프 노드 개수 증가
	for (int i : adj[v]) {
		if (i == par) continue;
		dfs(i, v);
	}
}

int main() {
	ios::sync_with_stdio(0), cin.tie(0);
	cin >> N;
	for (int i = 1; i < N; ++i) {
		cin >> p1 >> p2;
		adj[p1].push_back(p2); adj[p2].push_back(p1);
	}
	dfs(0, -1);
	if (ans % 2) cout << ans / 2 + 1;    // 리프 노드가 홀수 개인 경우
	else cout << ans / 2;    // 리프 노드가 짝수 개인 경우
}