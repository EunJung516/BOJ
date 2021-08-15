#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int V, E, A, B, K, cnt, num[10010], chk[10010];
vector<int> st, v[10010];
vector<vector<int>> ans;

int dfs(int a) {
	num[a] = ++cnt; int mn = cnt;
	st.push_back(a);
	for (int b : v[a]) {
		if (!num[b]) mn = min(mn, dfs(b));
		else if (!chk[b]) mn = min(mn, num[b]);
	}
	if (mn == num[a]) {
		vector<int> tmp; ++K;
		while (1) {
			int b = st.back(); st.pop_back();
			tmp.push_back(b);
			chk[b] = 1;
			if (b == a)break;
		}
		sort(tmp.begin(), tmp.end()); ans.push_back(tmp);
	}
	return mn;
}

int main() {
	ios::sync_with_stdio(0), cin.tie(0);
	cin >> V >> E; while (E--) {
		cin >> A >> B; v[A].push_back(B);
	}
	for (int i = 1; i <= V; ++i) {
		if (!num[i]) dfs(i);
	}
	sort(ans.begin(), ans.end());

	cout << K << '\n';  // SCC 개수 출력
	for (auto& i : ans) {  // 속한 정점 번호 출력
		for (int j : i) cout << j << ' ';
		cout << "-1\n";
	}
}