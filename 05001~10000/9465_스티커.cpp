#include <iostream>
#include <algorithm>
using namespace std;

int T, n, mp[2][100010], d[2][100010];

void dp(int a) {
	if (a == n) {
		for (int i = 0; i < 2; ++i) d[i][a] = mp[i][a]; return;
	}
	if (~d[0][a]) return;

	dp(a + 1);
	d[0][a] = max(d[1][a + 1], d[1][a + 2]) + mp[0][a];  // 윗줄인 경우
	d[1][a] = max(d[0][a + 1], d[0][a + 2]) + mp[1][a];  // 아랫줄인 경우
}

int main() {
	ios::sync_with_stdio(0), cin.tie(0);
	cin >> T; while (T--) {
		cin >> n;
		for (int i = 0; i < 2; ++i) fill(d[i], d[i] + n + 2, -1);
		for (int i = 0; i < 2; ++i) {
			for (int j = 1; j <= n; ++j) cin >> mp[i][j];
		}
		dp(1); cout << max(d[0][1], d[1][1]) << '\n';
	}
}