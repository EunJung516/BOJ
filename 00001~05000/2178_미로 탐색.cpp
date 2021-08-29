#include <iostream>
#include <queue>
using namespace std;

int N, M, vis[110][110], dir[2][4]{ {1,-1,0,0},{0,0,1,-1} };
char mp[110][110];
queue<pair<int,pair<int,int>>> q;

int main() {
	ios::sync_with_stdio(0), cin.tie(0);
	cin >> N >> M;
	for (int i = 1; i <= N; ++i) {
		for (int j = 1; j <= M; ++j) cin >> mp[i][j];
	}
	q.push({ 1,{1,1} }); vis[1][1] = 1; while (q.size()) {
		int z = q.front().first, y = q.front().second.first, x = q.front().second.second; q.pop();
		if (y == N && x == M) {  // 도착한 경우
			cout << z; return 0;
		}
		for (int i = 0; i < 4; ++i) {
			int ny = y + dir[0][i], nx = x + dir[1][i];
			if (ny<1 || ny>N || nx<1 || nx>M) continue;
			if (mp[ny][nx] == '1' && !vis[ny][nx]) {  // 아직 방문하지 않고 이동 가능한 칸인 경우
				vis[ny][nx] = 1; q.push({ z + 1,{ny,nx} });
			}
		}
	}
}