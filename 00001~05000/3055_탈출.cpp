#include <iostream>
#include <queue>
using namespace std;
typedef pair<int, int> PI;
typedef pair<int, PI> PII;

int R, C, vis[55][55], dir[2][4]{ {1,-1,0,0},{0,0,1,-1} };
char mp[55][55];
PI S;
queue<PII> q;

int main() {
	ios::sync_with_stdio(0), cin.tie(0);
	cin >> R >> C;
	for (int i = 1; i <= R; ++i) {
		for (int j = 1; j <= C; ++j) {
			cin >> mp[i][j];
			if (mp[i][j] == '*') q.push({0,{ i, j } });  // 물이 차있는 경우
			else if (mp[i][j] == 'S') {  // 고슴도치 위치인 경우
				S = { i,j }; vis[i][j] = 1;
			}
		}
	}
	q.push({ 1,S }); while (q.size()) {
		int z = q.front().first, y = q.front().second.first, x = q.front().second.second; q.pop();
		for (int i = 0; i < 4; ++i) {
			int ny = y + dir[0][i], nx = x + dir[1][i];
			if (ny<1 || ny>R || nx<1 || nx>C) continue;
			if (z) {  // 고슴도치 이동인 경우
				if (mp[ny][nx] == 'D') {  // 비버의 굴인 경우
					cout << vis[y][x]; return 0;
				}
				if (mp[ny][nx] == '.') {  // 비어있는 곳인 경우
					vis[ny][nx] = vis[y][x] + 1; mp[ny][nx] = 'S'; q.push({ 1,{ny,nx} });
				}
			}
			else {  // 물 이동인 경우
				if (mp[ny][nx] == '.' || mp[ny][nx] == 'S') {  // 물이 이동 가능한 경우
					mp[ny][nx] = '*'; q.push({ 0,{ny,nx} });
				}
			}
		}
	}
	cout << "KAKTUS";
}