#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> PI;
typedef pair<ll, pair<ll, ll>> PII;

long long N, M, K, p1, p2, p3, cur, nxt, ndist, cnt, ans = LLONG_MAX;
long long dist[25][10010], visited[25][10010];
vector<vector<PI>> nodes;
priority_queue<PII, vector<PII>, greater<PII>> q;

int main() {
	ios::sync_with_stdio(0), cin.tie(0);
	cin >> N >> M >> K; nodes.resize(N + 1);
	for (int i = 0; i <= K; ++i) fill(dist[i], dist[i] + N + 1, LLONG_MAX);
	while (M--) {
		cin >> p1 >> p2 >> p3;
		nodes[p1].push_back({ p2,p3 }); nodes[p2].push_back({ p1,p3 });
	}
	for (int i = 0; i <= K; ++i) dist[i][1] = 0;
	q.push({ 0,{ 0,1 } });
	while (!q.empty()) {
		do {
			cnt = q.top().first;
			cur = q.top().second.second;
			q.pop();
		} while (!q.empty() && visited[cnt][cur]);
		if (visited[cnt][cur]) continue;
		visited[cnt][cur] = true;
		for (auto& i : nodes[cur]) {
			nxt = i.first; ndist = i.second;
			if (dist[cnt][nxt] > dist[cnt][cur] + ndist) {    // 현재 도로를 포장하지 않는 경우
				dist[cnt][nxt] = dist[cnt][cur] + ndist;
				q.push({ cnt,{ dist[cnt][nxt],nxt } });
			}
			if (cnt + 1 <= K && dist[cnt + 1][nxt] > dist[cnt][cur]) {    // 현재 도로를 포장하는 경우
				dist[cnt + 1][nxt] = dist[cnt][cur];
				q.push({ cnt + 1,{dist[cnt + 1][nxt],nxt} });
			}
		}
	}
	for (int i = 0; i <= K; ++i) {
		ans = min(ans, dist[i][N]);
	}
	cout << ans;
}