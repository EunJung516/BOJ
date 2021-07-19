#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;

int T, l, y, x, ny, nx, cnt;
int board[303][303], visited[303][303], dir8[2][8]{ {2,1,-1,-2,-2,-1,1,2},{1,2,2,1,-1,-2,-2,-1} };
pair<int, int> st, en;

int main() {
	ios::sync_with_stdio(0), cin.tie(0);
	cin >> T; while (T--) {
		memset(visited, 0, sizeof visited);
		queue<pair<pair<int, int>, int>> q;

		cin >> l >> st.first >> st.second >> en.first >> en.second;
		q.push({ { st.first,st.second }, 0});
		while (!q.empty()) {
			y = q.front().first.first, x = q.front().first.second, cnt = q.front().second;
			if (y == en.first && x == en.second) {    // 나이트가 도착한 경우
				cout << cnt << '\n'; break;
			}
			for (int i = 0; i < 8; ++i) {    // 8가지의 이동 가능 경로
				ny = y + dir8[0][i], nx = x + dir8[1][i];
				if (ny >= l || ny < 0 || nx >= l || nx < 0) continue;
				if (!visited[ny][nx]) {
					visited[ny][nx] = 1;
					q.push({ { ny,nx }, cnt + 1 });
				}
			}
			q.pop();
		}
	}
}