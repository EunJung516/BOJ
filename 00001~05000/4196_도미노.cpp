#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
const int MAX = 100010;

int T, N, M, x, y, cnt, ans, scc, num[MAX], chk[MAX], res[MAX];
vector<int> st, v[MAX];

int dfs(int a) {
	num[a] = ++cnt; int mn = cnt;
	st.push_back(a);
	for (int i : v[a]) {
		if (!num[i]) mn = min(mn, dfs(i));
		else if (!chk[i]) mn = min(mn, num[i]);
	}
	if (mn == num[a]) {
		++scc;
		while (1) {
			int tmp = st.back(); st.pop_back();
			chk[tmp] = scc;
			if (tmp == a) break;
		}
	}
	return mn;
}

int main() {
	ios::sync_with_stdio(0), cin.tie(0);
	cin >> T; while (T--) {
		cin >> N >> M; cnt = ans = scc = 0;
		fill(num, num + N + 1, 0); fill(res, res + N + 1, 0); fill(chk, chk + N + 1, 0);  // 초기화
		st.clear();
		for (int i = 1; i <= N; ++i) v[i].clear();

		while (M--) {
			cin >> x >> y; v[x].push_back(y);
		}
		for (int i = 1; i <= N; ++i) {
			if (!num[i]) dfs(i);
		}

		for (int i = 1; i <= N; ++i) {
			for (int j : v[i]) {
				if (chk[i] != chk[j]) ++res[chk[j]];  // 다른 도미노에 의해 쓰러질 수 있는 경우
			}
		}
		for (int i = 1; i <= scc; ++i) {
			if (!res[i]) ++ans;
		}
		cout << ans << '\n';  // 넘어뜨려야 하는 도미노 최소 개수 출력
	}
}