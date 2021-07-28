#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, S, D, x, y, ans, d[100010];
vector<int> adj[100010];

void dfs(int idx, int par) {
	if (idx != S && adj[idx].size() == 1) d[idx] = 1;    // S가 아니며 리프 노드인 경우
	else {
		for (int i : adj[idx]) {
			if (i == par) continue;
			dfs(i, idx);
			d[idx] = max(d[idx], d[i] + 1);
		}
	}
	
	if (idx != S && d[idx] > D) ans += 2;    // 이동해야 하는 경우, ans 2만큼 증가
}

int main() {
	ios::sync_with_stdio(0), cin.tie(0);
	cin >> N >> S >> D;
	for (int i = 1; i < N; ++i) {
		cin >> x >> y;
		adj[x].push_back(y); adj[y].push_back(x);
	}
	dfs(S, 0); cout << ans;
}