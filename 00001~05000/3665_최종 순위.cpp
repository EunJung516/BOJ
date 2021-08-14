#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <algorithm>
using namespace std;

string ans;
int T, n, m, a, b, cur, cnt, chk;
int t[505], idx[505], dg[505], vis[505][505], ansA[505];
vector<int> v[505];
priority_queue<int, vector<int>, greater<int>> q;

int main() {
	ios::sync_with_stdio(0), cin.tie(0);
	cin >> T; while (T--) {
		cin >> n; fill(dg, dg + n + 1, 0); fill(ansA, ansA + n + 1, 0);  // 초기화
		ans = ""; cnt = chk = 0;
		for (int i = 1; i <= n; ++i) {
			v[i].clear(); fill(vis[i], vis[i] + n + 1, 0);
			for (int j = 1; j < i; ++j) {
				v[j].push_back(i); ++dg[i];
			}
		}
		for (int i = 1; i <= n; ++i) {
			cin >> t[i]; idx[t[i]] = i;  // 인덱스별 원소와, 원소별 인덱스 저장
		}
		cin >> m; while (m--) {
			cin >> a >> b; vis[idx[a]][idx[b]] = vis[idx[b]][idx[a]] = 1;  // 변경됐음을 저장
			if (idx[a] < idx[b]) {  // 원래 b의 인덱스가 a의 인덱스보다 클 경우
				v[idx[b]].push_back(idx[a]); ++dg[idx[a]]; --dg[idx[b]];
			}
			else {  // 원래 a의 인덱스가 b의 인덱스보다 클 경우
				v[idx[a]].push_back(idx[b]); ++dg[idx[b]]; --dg[idx[a]];
			}
		}
		for (int i = 1; i <= n; ++i) {
			if (!dg[i]) q.push(i);  // 앞에 올 원소가 없는 경우
		}
		while (q.size()) {
			cur = q.top(); q.pop();
			for (int i : v[cur]) {
				--dg[i]; if (!dg[i]) q.push(i);
			}
			ans += to_string(t[cur]) + ' ';
			ansA[t[cur]] = ++cnt;  // 변경된 원소의 인덱스(순위) 저장
		}

		for (int i = 1; i <= n; ++i) {
			for (int j : v[i]) {
				if (!vis[i][j] && ansA[t[i]] > ansA[t[j]]) {  // 뒤에 있어야 할 원소가, 순위가 더 높은 경우
					chk = 1; break;
				}
			}
			if (chk) break;
		}
		if (chk || ans == "" || cnt != n) cout << "IMPOSSIBLE\n";  // 불가능한 경우
		else cout << ans << '\n';  // 가능한 경우, 순위 순서대로 출력
	}
}