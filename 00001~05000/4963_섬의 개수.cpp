#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

int w, h, cnt, y, x, ny, nx;
int visited[55][55], mp[55][55], dir4[2][8]{ {1,1,0,-1,-1,-1,0,1},{0,1,1,1,0,-1,-1,-1} };
queue<pair<int, int>> q;

int main() {
	ios::sync_with_stdio(0), cin.tie(0);
	while (cin >> w >> h) {
		if (w == 0 && h == 0) break;
		memset(visited, 0, sizeof visited); cnt = 0;
		for (int i = 1; i <= h; ++i) {
			for (int j = 1; j <= w; ++j)
				cin >> mp[i][j];
		}
		for (int i = 1; i <= h; ++i) {
			for (int j = 1; j <= w; ++j) {
				if (!visited[i][j] && mp[i][j]) {
					q.push({ i,j }); visited[i][j] = 1;
                    ++cnt;    // 섬의 개수 증가
					while (!q.empty()) {
						y = q.front().first; x = q.front().second;
						q.pop();
						for (int k = 0; k < 8; ++k) {
							ny = y + dir4[0][k]; nx = x + dir4[1][k];
							if (ny<1 || ny>h || nx<1 || nx>w) continue;
							if (mp[ny][nx] && !visited[ny][nx]) {    // 방문하지 않은 인접한 섬인 경우
								visited[ny][nx] = 1; q.push({ ny,nx });
							}
						}
					}
				}
			}
		}
		cout << cnt << '\n';
	}
}