#include <iostream>
#include <vector>
using namespace std;

int V, vertex, cnt, sum;
vector<pair<int, int>> v[100010];

void dfs(int a, int par) {
	for (auto& i : v[a]) {
		if (i.first == par) continue;
		cnt += i.second;
		dfs(i.first, a);
		cnt -= i.second;
	}
	if (sum < cnt) {  // 가장 긴 길이와 해당 지점 갱신
		sum = cnt; vertex = a;
	}
}

int main() {
	ios::sync_with_stdio(0), cin.tie(0);
	cin >> V;
	for (int i = 0; i < V; ++i) {
		int a, b, c; cin >> a;
		while (1) {
			cin >> b; if (b == -1) break;
			cin >> c; v[a].push_back({ b,c });
		}
	}
	dfs(1, 0); cnt = sum = 0;  // 임의의 점에서 dfs 실행
	dfs(vertex, 0); cout << sum;  // 임의의 점으로부터 가장 먼 지점에서 dfs 실행
}