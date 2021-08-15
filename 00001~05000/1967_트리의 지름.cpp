#include <iostream>
#include <vector>
using namespace std;

int n, vertex, cnt, ans;
vector<pair<int, int>> v[10010];

void dfs(int a, int par) {
	for (auto& i : v[a]) {
		if (i.first == par) continue;
		cnt += i.second;
		dfs(i.first, a);
		cnt -= i.second;
	}
	if (ans < cnt) {  // 가장 긴 길이와 해당 지점 갱신
		ans = cnt; vertex = a;
	}
}

int main() {
	ios::sync_with_stdio(0), cin.tie(0);
	cin >> n;
	for (int i = 1; i < n; ++i) {
		int a, b, c; cin >> a >> b >> c;
		v[a].push_back({ b,c }); v[b].push_back({ a,c });
	}
	dfs(1, 0); cnt = ans = 0;  // 루트에서 dfs 실행
	dfs(vertex, 0); cout << ans;  // 루트로부터 가장 먼 지점에서 dfs 실행
}