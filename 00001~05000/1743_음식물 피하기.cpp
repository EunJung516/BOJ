#include <iostream>
#include <vector>
using namespace std;

int N, M, K, r, c, cn, an;
int vis[110][110], mp[110][110], dir4[2][4]{ {1,-1,0,0},{0,0,-1,1} };
vector<int> adj[110];

void dfs(int u, int v) {
	vis[u][v] = 1; ++cn;
	for (int i = 0; i < 4; ++i) {
		int ny = u + dir4[0][i], nx = v + dir4[1][i];
		if (ny<1 || ny>N || nx<1 || nx>M) continue;
		if (mp[ny][nx] && !vis[ny][nx]) dfs(ny, nx);
	}
}

int main() {
	ios::sync_with_stdio(0), cin.tie(0);
	cin >> N >> M >> K; while (K--) {
		cin >> r >> c; mp[r][c] = 1;
	}
	for (int i = 1; i <= N; ++i) {
		for (int j = 1; j <= M; ++j) {
			if (mp[i][j] && !vis[i][j]) {  // 음식물이 있고 방문하지 않은 경우
				cn = 0; dfs(i, j);
				if (an < cn) an = cn;  // 가장 큰 음식물의 크기 갱신
			}
		}
	}
	cout << an;
}