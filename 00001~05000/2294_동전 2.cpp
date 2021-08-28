#include <iostream>
#include <algorithm>
using namespace std;

int n, k, m[110], d[110][10010];

int dp(int a, int b) {
	if (a > n) return (b ? 1e9 : 0);  // 불가능한 경우
	if (~d[a][b]) return d[a][b];

	d[a][b] = dp(a + 1, b);
	if (b >= m[a]) d[a][b] = min(d[a][b], dp(a, b - m[a]) + 1);
	return d[a][b];
}

int main() {
	ios::sync_with_stdio(0), cin.tie(0);
	cin >> n >> k; for (int i = 1; i <= n; ++i) cin >> m[i];
	for (int i = 1; i <= n; ++i) fill(d[i], d[i] + k + 1, -1);
	if (dp(1, k) == 1e9) cout << "-1";  // 불가능한 경우
	else cout << d[1][k];  // 가능한 경우
}