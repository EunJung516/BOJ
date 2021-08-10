#include <iostream>
#include <vector>
using namespace std;

int N, M, A, B, vis[32010];
vector<vector<int>> v(32010);
vector<int> ans;

void dfs(int u) {
	vis[u] = 1;
	for (int i : v[u]) {
		if (!vis[i]) dfs(i);
	}
	ans.push_back(u);    // 작은 순서대로 ans에 저장
}

int main() {
	ios::sync_with_stdio(0), cin.tie(0);
	cin >> N >> M; while (M--) {
		cin >> A >> B; v[A].push_back(B);
	}
	for (int i = 1; i <= N; ++i) {
		if (!vis[i]) dfs(i);
	}
	for (int i = N - 1; i >= 0; --i) cout << ans[i] << ' ';    // 키 순서대로 줄 세운 결과 출력
}