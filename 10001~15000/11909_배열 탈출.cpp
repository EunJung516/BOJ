#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
typedef pair<int, pair<int, int>> PII;

int n, y, x, ny, nx, ndist;
int dist[2225][2225], visited[2225][2225], mp[2225][2225], dir2[2][2]{ {0,1},{1,0} };
priority_queue<PII, vector<PII>, greater<PII>> q;

int main() {
	ios::sync_with_stdio(0), cin.tie(0);
	cin >> n;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			cin >> mp[i][j]; dist[i][j] = 2e9;
		}
	}
	dist[0][0] = 0;
	q.push({ 0,{0,0} });
	while (!q.empty()) {
		do {
			y = q.top().second.first; x = q.top().second.second;
			q.pop();
		} while (!q.empty() && visited[y][x]);
		if (visited[y][x]) break;
		visited[y][x] = true;
		for (int i = 0; i < 2; ++i) {
			ny = y + dir2[0][i]; nx = x + dir2[1][i];
			if (ny < 0 || ny >= n || nx < 0 || nx >= n) continue;
			ndist = 0;
			if (mp[ny][nx] >= mp[y][x]) ndist = mp[ny][nx] - mp[y][x] + 1;    // 버튼을 눌러야 하는 경우
			if (dist[ny][nx] > dist[y][x] + ndist) {    // 비용을 갱신해야 하는 경우
				dist[ny][nx] = dist[y][x] + ndist;
				q.push({ dist[ny][nx],{ny,nx} });
			}
		}
	}
	cout << dist[n - 1][n - 1];
}