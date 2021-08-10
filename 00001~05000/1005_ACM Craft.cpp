#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

int T, N, K, X, Y, W;
int D[1010], vis[1010];
vector<vector<int>> v;

void dfs(int u) {
	if (vis[u]) return;
	int maxV = 0; vis[u] = 1;
	for (int i : v[u]) {
		dfs(i); 
		if (maxV < D[i]) maxV = D[i];    // 이전에 건설해야 할 건물들에 대한 최대 시간 갱신
	}
	D[u] += maxV;    // 본래 시간에, 이전에 건설해야 할 건물들의 시간 추가
}

int main() {
	ios::sync_with_stdio(0), cin.tie(0);
	cin >> T; while (T--) {
		cin >> N >> K; 
		v.clear(); v.resize(N + 1); memset(vis, 0, sizeof vis);    // 초기화
		for (int i = 1; i <= N; ++i) cin >> D[i];
		while (K--) {
			cin >> X >> Y; v[Y].push_back(X);
		}
		cin >> W; dfs(W);
		cout << D[W] << '\n';    // 건설완료 하는데 드는 최소 시간 출력
	}
}