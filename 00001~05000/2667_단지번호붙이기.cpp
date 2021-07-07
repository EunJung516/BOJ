#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int N, curX, curY, nxtX, nxtY;
char ch;
int mp[30][30], visited[30][30];
int dx[] = { 0,0,-1,1 }, dy[] = { 1,-1,0,0 };
queue<pair<int, int>> q;
vector<int> ans;

int main() {
	cin >> N;
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			cin >> ch; mp[i][j] = ch - '0';
		}
	}

	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			if (!mp[i][j] || visited[i][j]) continue;
			ans.push_back(0);    // 새로운 단지를 발견
			q.push({ i,j }); visited[i][j] = 1;

			while (!q.empty()) {
				curY = q.front().first; curX = q.front().second;
				for (int k = 0; k < 4; ++k) {
					nxtY = curY + dy[k];
					nxtX = curX + dx[k];
					if (nxtY >= N || nxtY < 0 || nxtX >= N || nxtX < 0) continue;    // 범위를 벗어난 경우
					if (mp[nxtY][nxtX] && !visited[nxtY][nxtX]) {    // 해당 단지이며 방문하지 않은 경우
						visited[nxtY][nxtX] = 1;
						q.push({ nxtY, nxtX });
					}
				}
				++ans.back();    // 해당 단지 집의 수 증가
				q.pop();
			}
		}
	}
	cout << ans.size() << '\n';    // 단지 수 출력
	sort(ans.begin(), ans.end());
	for (auto& nxt : ans) cout << nxt << '\n';
}