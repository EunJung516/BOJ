#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
typedef pair<int, int> PI;

int V, E, K, u, v, w;
int visited[20005], dist[20005];
vector<vector<PI>> nodes;
priority_queue<PI, vector<PI>, greater<PI>> q;

int main() {
	ios::sync_with_stdio(0), cin.tie(0);
	cin >> V >> E >> K; nodes.resize(V + 1); fill(dist, dist + V + 1, 2e9);
	while (E--) {    // 해당 정점에 간선 저장
		cin >> u >> v >> w; nodes[u].push_back({ v,w });
	}

    // 다익스트라 알고리즘
	dist[K] = 0;
	q.push({ 0,K });
	while (!q.empty()) {
		int cur;
		do {
			cur = q.top().second;
			q.pop();
		} while (!q.empty() && visited[cur]);
		if (visited[cur]) break;
		visited[cur] = true;
		for (auto& i : nodes[cur]) {
			int next = i.first;
			int ndist = i.second;
			if (dist[next] > dist[cur] + ndist) {    // 거리가 갱신될 경우
				dist[next] = dist[cur] + ndist;
				q.push({ dist[next],next });
			}
		}
	}
	for (int i = 1; i <= V; ++i) {
		if (dist[i] == 2e9) cout << "INF\n";    // 경로가 존재하지 않는 경우
		else cout << dist[i] << '\n';
	}
}