#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using ll = long long;
using pll = pair<ll, ll>;

int N;
ll res;
vector<pll> adj[100010];

void dfs(ll v, ll par, ll w) {
	res = max(res, w);    // 최대 거리 저장
	for (pll i : adj[v]) {
		ll ch = i.second, weight = i.first;
		if (ch == par) continue;
		dfs(ch, v, w + weight);
	}
}

int main() {
	ios::sync_with_stdio(0), cin.tie(0);
	cin >> N;
	for (int i = 0; i < N - 1; ++i) {
		int a, b, c; cin >> a >> b >> c;
		adj[a].push_back({ c,b }); adj[b].push_back({ c,a });
	}
	dfs(1, -1, 0);
	cout << res;
}