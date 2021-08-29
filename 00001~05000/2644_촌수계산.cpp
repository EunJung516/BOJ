#include <iostream>
#include <cmath>
#include <queue>
#include <vector>
using namespace std;

int n, a, b, m, x, y, vis[110];
queue<int> q;
vector<int> adj[110];

int main() {
	ios::sync_with_stdio(0), cin.tie(0);
	cin >> n >> a >> b >> m; while (m--) {
		cin >> x >> y; adj[x].push_back(y); adj[y].push_back(x);
	}
	q.push(a); while (q.size()) {  // a로부터 시작에서 b까지의 거리 계산
		int cur = q.front(); q.pop();
		for (int j : adj[cur]) {
			if (!vis[j]) {
				vis[j] = vis[cur] + 1;
				q.push(j);
			}
		}
	}
	cout << (vis[b] ? vis[b] : -1);
}