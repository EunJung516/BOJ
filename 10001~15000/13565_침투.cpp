#include <iostream>
#include <vector>
#include <queue>
using namespace std;

char ch;
int n, m;
int mp[1001][1001], visited[1001][1001];
int dx[] = { 0,0,-1,1 }, dy[] = { 1,-1,0,0 };
queue<pair<int, int>> q;

int main() {
	ios::sync_with_stdio(0), cin.tie(0);
	cin >> n >> m;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			cin >> ch;
			mp[i][j] = ch - '0';
		}
	}
	for (int i = 0; i < m; ++i) {    // bfs 활용
		if (mp[0][i] == 0 && visited[0][i] == 0) {
			q.push({ 0,i });
			visited[0][i] = true;
			while (!q.empty()) {
				int y = q.front().first;
				int x = q.front().second;
				if (y == n - 1) {    // 전류가 안쪽까지 침투될 수 있는 경우
					cout << "YES";
					return 0;
				}

				q.pop();
				for (int j = 0; j < 4; ++j) {
					int ny = y + dy[j];
					int nx = x + dx[j];
					if (ny < 0 || ny > n - 1 || nx < 0 || nx > m - 1) continue;
					if (mp[ny][nx] == 0 && visited[ny][nx] == 0) {
						q.push({ ny,nx });
						visited[ny][nx] = true;
					}
				}
			}
		}
	}
	cout << "NO";    // 전류가 안쪽까지 침투될 수 없는 경우
}