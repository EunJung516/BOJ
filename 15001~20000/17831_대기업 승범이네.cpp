#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, A, a[200010], dp[200010][2];
vector<int> adj[200010];

void dfs(int v, int par) {
	for (int i : adj[v]) {
		if (i == par) continue;
		dfs(i, v);
		dp[v][0] += max(dp[i][0], dp[i][1]);    // v가 멘토가 아닌 경우
	}
	for (int i : adj[v]) {
		if (i == par) continue;
		dp[v][1] = max(dp[v][0] - max(dp[i][0], dp[i][1]) + a[v] * a[i] + dp[i][0], dp[v][1]);    // v가 멘토인 경우
	}
}

int main() {
	ios::sync_with_stdio(0), cin.tie(0);
	cin >> N;
	for (int i = 2; i <= N; ++i) {
		cin >> A;
		adj[i].push_back(A); adj[A].push_back(i);
	}
	for (int i = 1; i <= N; ++i) cin >> a[i];
	dfs(1, 0); cout << max(dp[1][0], dp[1][1]);
}