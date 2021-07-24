#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> PI;

ll N, M, K, S, p, q, tmp1, tmp2, cur, cnt, nxt, ndist;
ll dist[100010], visited[100010], check[100010];
priority_queue<PI, vector<PI>, greater<PI>> pq;

int main() {
	ios::sync_with_stdio(0), cin.tie(0);
	cin >> N >> M >> K >> S >> p >> q; fill(dist, dist + N + 1, LLONG_MAX);
	vector<ll> nodes(N + 1, p), zombie; vector<vector<ll>> edges(N + 1);
	while (K--) {
		cin >> tmp1; zombie.push_back(tmp1); check[tmp1] = S + 1;
	}
	while (M--) {
		cin >> tmp1 >> tmp2;
		edges[tmp1].push_back(tmp2); edges[tmp2].push_back(tmp1);
	}

	for (auto& i : zombie) {    // 위험한 도시 결정
		queue<PI> z; z.push({ i,S });
		while (!z.empty()) {
			cur = z.front().first, cnt = z.front().second;
			if (cnt > 0) {
				for (auto& j : edges[cur]) {
					if (check[j] >= cnt) continue;
					check[j] = cnt; nodes[j] = q;
					z.push({ j,cnt - 1 });
				}
			}
			z.pop();
		}
	}

	dist[1] = 0; pq.push({ 0,1 });
	while (!pq.empty()) {
		do {
			cur = pq.top().second;
			pq.pop();
		} while (!pq.empty() && visited[cur]);
		if (visited[cur]) break;
		visited[cur] = true;
		for (auto& i : edges[cur]) {
			nxt = i; ndist = nodes[i];
			if (check[nxt] != (S + 1) && dist[nxt] > dist[cur] + ndist) {
				dist[nxt] = dist[cur] + ndist;
				pq.push({ dist[nxt],nxt });
			}
		}
	}
	cout << dist[N] - nodes[N];    // 최단 비용 출력
}