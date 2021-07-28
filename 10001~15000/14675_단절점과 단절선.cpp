#include <iostream>
#include <vector>
#include <map>
using namespace std;

int N, a, b, q;
vector<int> adj[100010];
map<int, int> cut;

void dfs(int idx, int par) {
	if (adj[idx].size() == 1) cut[idx] = 1;    // 리프 노드 확인
	for (int i : adj[idx]) {
		if (i == par) continue;
		dfs(i, idx);
	}
}

int main() {
	ios::sync_with_stdio(0), cin.tie(0);
	cin >> N;
	for (int i = 1; i < N; ++i) {
		cin >> a >> b;
		adj[a].push_back(b); adj[b].push_back(a);
	}
	dfs(1, 0);

	cin >> q; while (q--) {
		cin >> a >> b;
		if (a == 1 && cut[b]) cout << "no\n";    // 리프 노드는 단절점이 아님
		else cout << "yes\n";    // 그 외의 모든 경우는 참
	}
}