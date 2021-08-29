#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;
typedef pair<int, pair<int, int>> PII;

char mp[35][35][35];
int L, R, C;
int vis[35][35][35], dir[3][6]{ {0,0,0,0,1,-1},{1,-1,0,0,0,0},{0,0,1,-1,0,0} };
PII st, en;
queue<PII> q;

int main() {
	ios::sync_with_stdio(0), cin.tie(0);
	while (1) {
		cin >> L >> R >> C;
		if (!L && !R && !C) break;
		for (int i = 1; i <= L; ++i) {
			for (int j = 1; j <= R; ++j) fill(vis[i][j], vis[i][j] + C + 1, 0);
		}

		for (int i = 1; i <= L; ++i) {
			for (int j = 1; j <= R; ++j) {
				for (int k = 1; k <= C; ++k) {
					cin >> mp[i][j][k];
					if (mp[i][j][k] == 'S') {  // 시작 지점인 경우
						st = { i,{j,k} }; vis[i][j][k] = 1;
					}
					if (mp[i][j][k] == 'E') en = { i,{j,k} };  // 출구인 경우
				}
			}
		}
		q.push(st); while (q.size()) {
			int z = q.front().first, y = q.front().second.first, x = q.front().second.second; q.pop();
			for (int i = 0; i < 6; ++i) {  // 여섯방향으로 이동
				int nz = z + dir[0][i], ny = y + dir[1][i], nx = x + dir[2][i];
				if (nz<1 || nz>L || ny<1 || ny>R || nx<1 || nx>C) continue;
				if (mp[nz][ny][nx] != '#' && !vis[nz][ny][nx]) {  // 이동가능한 경우
					vis[nz][ny][nx] = vis[z][y][x] + 1; q.push({ nz, { ny,nx } });
				}
			}
		}
		int an = vis[en.first][en.second.first][en.second.second];
		if (an) cout << "Escaped in " << an - 1 << " minute(s).\n";
		else cout << "Trapped!\n";
	}
}