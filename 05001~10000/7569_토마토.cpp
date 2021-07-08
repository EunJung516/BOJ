#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

int M, N, H, ans, x, y, z, nx, ny, nz;
int mp[110][110][110], visited[110][110][110];
int dx[] = { 0,0,-1,1,0,0 }, dy[] = { 1,-1,0,0,0,0 }, dz[] = { 0,0,0,0,1,-1 };
queue<pair<pair<int, int>, int>> q;

int main() {
	ios::sync_with_stdio(0), cin.tie(0);
	memset(visited, -1, sizeof visited);
	cin >> M >> N >> H;
	for (int k = 0; k < H; ++k) {
		for (int i = 0; i < N; ++i) {
			for (int j = 0; j < M; ++j) {
				cin >> mp[i][j][k];
				if (mp[i][j][k] == 1) {    // 익은 토마토인 경우
					q.push({ {i,j},k });
					visited[i][j][k] = 0;
				}
			}
		}
	}

	while (!q.empty()) {
		x = q.front().first.first; 
		y = q.front().first.second; 
		z = q.front().second;
		for (int i = 0; i < 6; ++i) {
			nx = x + dx[i]; ny = y + dy[i]; nz = z + dz[i];
			if (nx < 0 || nx >= N || ny < 0 || ny >= M || nz < 0 || nz >= H) continue;    // 범위를 벗어난 경우
			if (mp[nx][ny][nz] == -1) continue;    // 토마토가 들어있지 않은 칸
			if (visited[nx][ny][nz] == -1 || visited[nx][ny][nz] > visited[x][y][z] + 1) {    // 아직 익지 않은 토마토가 들어있는 칸
				visited[nx][ny][nz] = visited[x][y][z] + 1;
				q.push({ {nx,ny},nz });
			}
		}
		q.pop();
	}

	ans = 0;
	for (int k = 0; k < H; ++k) {
		for (int i = 0; i < N; ++i) {
			for (int j = 0; j < M; ++j) {
				if (mp[i][j][k] != -1 && visited[i][j][k] == -1) {    // 익지 않은 토마토가 있는 경우
					cout << -1; return 0;
				}
				if (visited[i][j][k] > ans) ans = visited[i][j][k];
			}
		}
	}
	cout << ans;
}