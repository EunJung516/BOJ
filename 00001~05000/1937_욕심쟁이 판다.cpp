#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

int n, ans;
int mp[505][505], visited[505][505], d[505][505], dir4[2][4]{ {1,-1,0,0},{0,0,-1,1} };

void dp(int y, int x) {
	d[y][x] = 1;
	for (int i = 0; i < 4; ++i) {
		int ny = y + dir4[0][i], nx = x + dir4[1][i];
		if (ny<1 || ny>n || nx<1 || nx>n) continue;
		if (mp[ny][nx] > mp[y][x]) {    // 판다가 이동할 수 있는 경우
			if (d[ny][nx] == -1) dp(ny, nx);    // 경우를 확인하지 않은 경우
			d[y][x] = max(d[y][x], d[ny][nx] + 1);
		}
		else d[y][x] = max(d[y][x], 1);    // 판다가 이동할 수 없는 경우
	}
	if (ans < d[y][x]) ans = d[y][x];    // 더 많은 칸을 이동할 수 있는 경우, ans 갱신
}

int main() {
	ios::sync_with_stdio(0), cin.tie(0);
	cin >> n; memset(d, -1, sizeof d);
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= n; ++j) cin >> mp[i][j];
	}

	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= n; ++j) {
			if (d[i][j] == -1) dp(i, j);    // 경우를 확인하지 않은 경우
		}
	}
	cout << ans;
}