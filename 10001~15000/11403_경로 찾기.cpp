#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, n, vis[110][110], dir4[2][4]{ {1,-1,0,0},{0,0,-1,1} };
vector<int> adj[110];

void dfs(int u, int v) {
	vis[u][v] = 1;  //  간선이 존재하는 경우라고 저장
	for (int i : adj[v]) {
		if (!vis[u][i]) dfs(u, i);
	}
}

int main() {
	ios::sync_with_stdio(0), cin.tie(0);
	cin >> N;
	for (int i = 1; i <= N; ++i) {
		for (int j = 1; j <= N; ++j) {
			cin >> n; if (n) adj[i].push_back(j);
		}
	}
	for (int i = 1; i <= N; ++i) {
		for (int j : adj[i]) {
			if (!vis[i][j]) dfs(i, j);
		}
	}
	for (int i = 1; i <= N; ++i) {
		for (int j = 1; j <= N; ++j) cout << vis[i][j] << ' ';
		cout << '\n';
	}
}