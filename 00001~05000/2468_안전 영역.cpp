#include <iostream>
#include <cstring>
using namespace std;

int N, ans = 1, cnt, limit;
int chk[110], mp[110][110], vis[110][110], dir4[2][4]{ {1,-1,0,0},{0,0,-1,1} };

void dfs(int y, int x) {
	vis[y][x] = 1;
	for (int i = 0; i < 4; ++i) {
		int ny = y + dir4[0][i], nx = x + dir4[1][i];
		if (ny<1 || ny>N || nx<1 || nx>N) continue;
		if (!vis[ny][nx] && mp[ny][nx] > limit) dfs(ny, nx);
	}
}

int main() {
	ios::sync_with_stdio(0), cin.tie(0);
	cin >> N;
	for (int i = 1; i <= N; ++i) {
		for (int j = 1; j <= N; ++j) {
			cin >> mp[i][j]; chk[mp[i][j]] = 1;
		}
	}

	for (int i = 1; i <= 100; ++i) {
		if (!chk[i]) continue;  // 강수량에 해당되지 않는 경우
		limit = i; memset(vis, 0, sizeof vis); cnt = 0;
		for (int j = 1; j <= N; ++j) {
			for (int k = 1; k <= N; ++k) {
				if (mp[j][k] > limit && !vis[j][k]) {  // 물에 잠기지 않고, 아직 방문하지 않은 경우
					dfs(j, k); ++cnt;
				}
			}
		}
		if (cnt > ans) ans = cnt;  // 정답 갱신
	}
	cout << ans;  //  안전한 영역 최대 개수 출력
}