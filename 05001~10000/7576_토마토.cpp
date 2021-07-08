#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

int M, N, ans, x, y, nx, ny;
int mp[1010][1010], visited[1010][1010];
int dx[] = { 0,0,-1,1 }, dy[] = { 1,-1,0,0 };
queue<pair<int, int>> q;

int main() {
	cin >> M >> N;
	memset(visited, -1, sizeof visited);
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < M; ++j) {
			cin >> mp[i][j];
			if (mp[i][j] == 1) {    // 익은 토마토인 경우
				q.push({ i,j });
				visited[i][j] = 0;
			}
		}
	}

	while (!q.empty()) {
		x = q.front().second; y = q.front().first;
		for (int i = 0; i < 4; ++i) {
			nx = x + dx[i]; ny = y + dy[i];
			if (nx < 0 || nx >= M || ny < 0 || ny >= N) continue;    // 범위를 벗어난 경우
			if (mp[ny][nx] == -1) continue;    // 토마토가 들어있지 않은 칸
			if (visited[ny][nx] == -1) {    // 아직 익지 않은 토마토가 들어있는 칸
				visited[ny][nx] = visited[y][x] + 1;
				q.push({ ny,nx });
			}
		}
		q.pop();
	}

	ans = 0;
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < M; ++j) {
			if (mp[i][j] != -1 && visited[i][j] == -1) {    // 익지 않은 토마토가 있는 경우
				cout << -1; return 0;
			}
			if (visited[i][j] > ans) ans = visited[i][j];
		}
	}
	cout << ans;
}