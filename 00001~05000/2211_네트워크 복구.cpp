#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;
typedef pair<int, int> PI;

int N, M, A, B, C, cur, nxt, ndist;
int visited[1010], dist[1010];
priority_queue<PI, vector<PI>, greater<PI>> q;
map<int, int> ans;

int main() {
	ios::sync_with_stdio(0), cin.tie(0);
	cin >> N >> M; vector<vector<PI>> nodes(N + 1); fill(dist, dist + N + 1, 2e9);
	while (M--) {
		cin >> A >> B >> C;
		nodes[A].push_back({ B,C }); nodes[B].push_back({ A,C });
	}

	dist[1] = 0; q.push({ 0,1 });
	while (!q.empty()) {
		do {
			cur = q.top().second;
			q.pop();
		} while (!q.empty() && visited[cur]);
		if (visited[cur]) break;
		visited[cur] = true;
		for (auto& i : nodes[cur]) {
			nxt = i.first; ndist = i.second;
			if (dist[nxt] > dist[cur] + ndist) {
				dist[nxt] = dist[cur] + ndist;
				q.push({ dist[nxt],nxt });
				ans[nxt] = cur;    // 최소 시간을 걸리게 하는 경로 저장
			}
		}
	}

	cout << ans.size() << '\n';    // 복구할 회선의 최소 개수 출력
	for (auto& i : ans) cout << i.first << ' ' << i.second << '\n';
}