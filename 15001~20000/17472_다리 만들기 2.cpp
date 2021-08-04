#include <iostream>
#include <queue>
#include <tuple>
using namespace std;
using tup = tuple<int, int, int>;

int N, M, cnt = -1, ans;
int par[110], mp[15][15], visited[15][15], dir4[2][4]{ {1,-1,0,0},{0,0,-1,1} };
queue<pair<int, int>> q;
priority_queue<tup, vector<tup>, greater<tup>> edge;

int find(int a) {
	if (par[a] == a) return a;
	return par[a] = find(par[a]);
}
void merge(int a, int b) {
	int a_root = find(a), b_root = find(b);
	if (a_root != b_root) par[a_root] = b_root;
}

int main() {
	ios::sync_with_stdio(0), cin.tie(0);
	cin >> N >> M;
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < M; ++j) {
			cin >> mp[i][j];
			par[i * M + j] = i * M + j;
		}
	}
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < M; ++j) {
			if (mp[i][j] && !visited[i][j]) {    // 방문하지 않은 섬인 경우
				++cnt;    // 연결해야 할 섬의 개수 추가
				q.push({ i,j });
				while (!q.empty()) {
					int y = q.front().first, x = q.front().second;
					visited[y][x] = 1;
					q.pop();
					for (int k = 0; k < 4; ++k) {
						int ny = y + dir4[0][k], nx = x + dir4[1][k];
						if (ny<0 || ny>=N || nx<0 || nx>=M) continue;
						if (mp[ny][nx] && !visited[ny][nx]) {    // 인접하며 방문하지 않은 섬인 경우
							q.push({ ny,nx });
							merge(y * M + x, ny * M + nx);    // 인접한 섬 병합
						}
					}
				}
			}
		}
	}

	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < M; ++j) {
			if (mp[i][j]) {
				int add = 1;
				while (j + add < M && !mp[i][j + add]) ++add;    // 오른쪽 바다 칸의 수 세기
				if (j + add < M && add > 2) edge.push(make_tuple(add - 1, i * M + j, i * M + j + add));    // 바다 칸의 수가 2 이상이며, 섬에 도달하는 경우

				add = 1;
				while (i + add < N && !mp[i + add][j]) ++add;    // 아래 바다 칸의 수 세기
				if (i + add < N && add > 2) edge.push(make_tuple(add - 1, i * M + j, (i + add) * M + j));    // 바다 칸의 수가 2 이상이며, 섬에 도달하는 경우
			}
		}
	}
	
	while (!edge.empty() && cnt) {
		int len = get<0>(edge.top()), a = get<1>(edge.top()), b = get<2>(edge.top());
		edge.pop();
		if (find(a) == find(b)) continue;    // 두 섬끼리 연결된 경우
		merge(a, b);    // 두 섬 병합
		ans += len;    // 다리 길이 추가
		--cnt;    // 연결해야 할 섬의 개수 감소
	}
	cout << (cnt ? -1 : ans);    // 모든 섬을 연결하지 못할 경우 -1 출력, 아니면 다리 길이 최솟값 출력
}