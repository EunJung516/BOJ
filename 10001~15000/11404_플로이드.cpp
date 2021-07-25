#include <iostream>
#include <algorithm>
using namespace std;
typedef pair<int, int> PI;
const long long INF = 1e18;

long long n, m, a, b, c, cur, nxt, ndist, visited[110];
long long dist[110][110];

int main() {
	ios::sync_with_stdio(0), cin.tie(0);
	cin >> n >> m; 
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= n; ++j) dist[i][j] = i == j ? 0 : INF;
	}

	while (m--) {
		cin >> a >> b >> c; dist[a][b] = min(dist[a][b], c);
	}

	for (int k = 1; k <= n; ++k) {    // 플로이드 와샬 활용
		for (int i = 1; i <= n; ++i)
			for (int j = 1; j <= n; ++j)
				dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
	}

	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= n; ++j) {
			if (dist[i][j] == INF) cout << "0 ";
			else cout << dist[i][j] << ' ';
		}
		cout << '\n';
	}
}