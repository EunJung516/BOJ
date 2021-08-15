#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
const int MAX = 100010;

int N, M, A, B, cnt, scc, ans;
int num[MAX], chk[MAX], res[MAX];
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
	cin >> N >> M; while (M--) {
		cin >> A >> B; v[A].push_back(B);
	}
	for (int i = 0; i < N; ++i) {
		if (!num[i]) dfs(i);
	}

	for (int i = 0; i < N; ++i) {
		for (int j : v[i]) {
			if (chk[i] != chk[j]) ++res[chk[j]];  // 다른 시설에 의해 감염될 수 있는 경우
		}
	}
	for (int i = 1; i <= scc; ++i) {
		if (!res[i]) ++ans;
	}
	cout << ans;  // 생산해야 할 바이러스 최소 개수 출력
}