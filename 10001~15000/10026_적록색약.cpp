#include <iostream>
#include <cstring>
#include <queue>
using namespace std;

int N, cnt, y, x, ny, nx;
int visited[110][110], dir4[2][4]{ {1,-1,0,0},{0,0,-1,1} };
char color, mp[110][110];
queue<pair<int, int>> q;

int main() {
	ios::sync_with_stdio(0), cin.tie(0);
	cin >> N;
	for (int i = 1; i <= N; ++i) {
		for (int j = 1; j <= N; ++j) cin >> mp[i][j];
	}
    
	for (int i = 1; i <= N; ++i) {    // 적록색약이 아닌 사람이 봤을 때
		for (int j = 1; j <= N; ++j) {
			if (!visited[i][j]) {
				color = mp[i][j]; ++cnt; q.push({ i,j }); visited[i][j] = 1;
				while (!q.empty()) {
					y = q.front().first; x = q.front().second;
					q.pop();
					for (int k = 0; k < 4; ++k) {
						ny = y + dir4[0][k]; nx = x + dir4[1][k];
						if (ny<1 || ny>N || nx<1 || nx>N) continue;
						if (mp[ny][nx] == color && !visited[ny][nx]) {    // 같은 구역이고, 방문하지 않은 경우
							visited[ny][nx] = 1; q.push({ ny,nx });
						}
					}
				}
			}
		}
	}
	cout << cnt << ' ';

	memset(visited, 0, sizeof visited); cnt = 0;
	for (int i = 1; i <= N; ++i) {    // 적록색약인 사람이 봤을 때
		for (int j = 1; j <= N; ++j) {
			if (!visited[i][j]) {
				color = mp[i][j]; ++cnt; q.push({ i,j }); visited[i][j] = 1;
				while (!q.empty()) {
					y = q.front().first; x = q.front().second;
					q.pop();
					for (int k = 0; k < 4; ++k) {
						ny = y + dir4[0][k]; nx = x + dir4[1][k];
						if (ny<1 || ny>N || nx<1 || nx>N) continue;
						if (!((color == 'B') ^ (mp[ny][nx] == 'B')) && !visited[ny][nx]) {    // 같은 구역이고, 방문하지 않은 경우
							visited[ny][nx] = 1; q.push({ ny,nx });
						}
					}
				}
			}
		}
	}
	cout << cnt;
}