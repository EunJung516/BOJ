#include <iostream>
using namespace std;

bool check, visited[55][55];
int N, M, dir4[2][4]{ {1,-1,0,0},{0,0,-1,1} };
char mp[55][55];

void dfs(int y, int x, int ly, int lx) {
	visited[y][x] = true;
	for (int i = 0; i < 4; ++i) {
		int ny = y + dir4[0][i], nx = x + dir4[1][i];
		if (ny<1 || ny>N || nx<1 || nx>M) continue;
		if (ny == ly && nx == lx) continue;    // 직전에 방문한 점인 경우
		if (mp[y][x] == mp[ny][nx]) {    // 같은 색인 경우
			if (!visited[ny][nx]) {    // 방문하지 않은 경우
				dfs(ny, nx, y, x);
			}
			else {    // 방문한 점에 도달했다면, 사이클이 존재함
				check = true; return;
			}
		}
		if (check) return;
	}
}

int main() {
	ios::sync_with_stdio(0), cin.tie(0);
	cin >> N >> M;
	for (int i = 1; i <= N; ++i) {
		for (int j = 1; j <= M; ++j) cin >> mp[i][j];
	}
	for (int i = 1; i <= N; ++i) {
		for (int j = 1; j <= M; ++j) {
			if (!visited[i][j]) {    // 방문하지 않은 경우
				dfs(i, j, i, j);
				if (check) {    // 사이클이 존재하는 경우
					cout << "Yes"; return 0;
				}
			}
		}
	}
	cout << "No";    // 사이클이 없는 경우
}