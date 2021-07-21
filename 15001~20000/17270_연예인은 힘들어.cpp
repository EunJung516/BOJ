#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
typedef pair<int, int> PI;

int V, M, a, b, c, cur, nxt, ndist, sum = 2e9, tmp;
int location[2], visited[2][110], dist[2][110];
vector<vector<PI>> nodes;
vector<int> ansNode;
priority_queue<PI, vector<PI>, greater<PI>> q;
PI ans;

int main() {
	ios::sync_with_stdio(0), cin.tie(0);
	cin >> V >> M; nodes.resize(V + 1);
	fill(dist[0], dist[0] + V + 1, 2e9); fill(dist[1], dist[1] + V + 1, 2e9);
	while (M--) {
		cin >> a >> b >> c;
		nodes[a].push_back({ b,c });
		nodes[b].push_back({ a,c });
	}
	cin >> location[0] >> location[1];

	for (int i = 0; i < 2; ++i) {
		dist[i][location[i]] = 0;
		q.push({ 0,location[i] });
		while (!q.empty()) {
			do {
				cur = q.top().second;
				q.pop();
			} while (!q.empty() && visited[i][cur]);
			if (visited[i][cur])break;
			visited[i][cur] = true;
			for (auto& j : nodes[cur]) {
				nxt = j.first, ndist = j.second;
				if (dist[i][nxt] > dist[i][cur] + ndist) {    // 최단 시간 갱신해야 하는 경우
					dist[i][nxt] = dist[i][cur] + ndist;
					q.push({ dist[i][nxt],nxt });
				}
			}
		}
	}

	for (int i = 1; i <= V; ++i) {
		if (i == location[0] || i == location[1]) continue;
		tmp = dist[0][i] + dist[1][i];
		if (sum > tmp) {    // 최소 합을 갱신해야 하는 경우
			sum = tmp; ansNode.clear(); 
			if (dist[0][i] <= dist[1][i]) ansNode.push_back(i);    // 지헌이가 성하보다 늦게 도착하지 않는 경우
		}
		else if (sum == tmp && dist[0][i] <= dist[1][i]) ansNode.push_back(i);
	}

	if (ansNode.empty()) cout << -1;    // 조건을 만족하는 약속 장소가 없는 경우
	else {
		ans.first = 2e9;
		for (auto& i : ansNode) {
			if (ans.first > dist[0][i]) {    // 지헌이로부터 가장 가까운 거리를 갱신해야 하는 경우
				ans.first = dist[0][i], ans.second = i;
			}
			else if(ans.first == dist[0][i] && ans.second > i) ans.second = i;    // 지헌이로부터 가까우면서, 저장한 번호보다 작은 경우
		}
		cout << ans.second;
	}
}