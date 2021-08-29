#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, M, K, a, b, c, d, cn;
int vis[110][110], mp[110][110], dir4[2][4]{ {1,-1,0,0},{0,0,-1,1} };
vector<int> adj[110], cnt;

void dfs(int u, int v) {
	vis[u][v] = 1; ++cn;
	for (int i = 0; i < 4; ++i) {
		int ny = u + dir4[0][i], nx = v + dir4[1][i];
		if (ny<0 || ny>=N || nx<0 || nx>=M) continue;
		if (!mp[ny][nx] && !vis[ny][nx]) dfs(ny, nx);
	}
}

int main() {
	ios::sync_with_stdio(0), cin.tie(0);
	cin >> M >> N >> K; while (K--) {
		cin >> a >> b >> c >> d;
		for (int i = a; i < c; ++i) {
			for (int j = b; j < d; ++j) mp[i][j] = 1;  // 그려진 영역 저장
		}
	}
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < M; ++j) {
			if (!mp[i][j] && !vis[i][j]) {  // 그려지지 않고 방문하지 않은 경우
				cn = 0; dfs(i, j); cnt.push_back(cn);
			}
		}
	}
	sort(cnt.begin(), cnt.end());
	cout << cnt.size() << '\n';
	for (int i : cnt) cout << i << ' ';
}