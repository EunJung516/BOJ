#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;
typedef pair<int, int> PI;
typedef pair<int, PI> PII;

int t, w, h, chk;
int vis[1010][1010], dir[2][4]{ {1,-1,0,0},{0,0,1,-1} };
char mp[1010][1010];
queue<PII> q;
pair<int, int> st;

int main() {
	ios::sync_with_stdio(0), cin.tie(0);
	cin >> t; while (t--) {
		cin >> w >> h; chk = 1;
		for (int i = 1; i <= h; ++i) fill(vis[i], vis[i] + w + 1, 0);

		for (int i = 1; i <= h; ++i) {
			for (int j = 1; j <= w; ++j) {
				cin >> mp[i][j];
				if (mp[i][j] == '*') q.push({ 0,{ i, j } });  // 불인 경우
				if (mp[i][j] == '@') {  // 상근이인 경우
					st = { i,j }; vis[i][j] = 1;
				}
			}
		}
		q.push({ 1,st }); while (q.size()) {
			int z = q.front().first, y = q.front().second.first, x = q.front().second.second; q.pop();
			for (int i = 0; i < 4; ++i) {
				int ny = y + dir[0][i], nx = x + dir[1][i];
				if (z) {  // 상근이 이동인 경우
					if (ny<1 || ny>h || nx<1 || nx>w) {  // 탈출한 경우
						chk = 0; cout << vis[y][x] << '\n';
						while (q.size()) q.pop();
						break;
					}
					if (mp[ny][nx] == '.') {  // 빈 공간인 경우
						mp[ny][nx] = '@'; vis[ny][nx] = vis[y][x] + 1; q.push({ 1,{ny,nx} });
					}
				}
				else {  // 불 이동인 경우
					if (ny<1 || ny>h || nx<1 || nx>w) continue;
					if (mp[ny][nx] == '.' || mp[ny][nx] == '@') {  // 불이 이동 가능한 경우
						q.push({ 0,{ny,nx} }); mp[ny][nx] = '*';
					}
				}
			}
		}
		if (chk) cout << "IMPOSSIBLE\n";
	}
}