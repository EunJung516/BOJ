#include <iostream>
#include <algorithm>
using namespace std;

int n, ans = -1010, a[100010], d[100010];

void dp(int v) {
	if (v > n) return;
	dp(v + 1);
	d[v] = max(a[v], a[v] + d[v + 1]);    // 다음 원소를 포함할지 결정
	ans = max(ans, d[v]);    // 연속합의 최댓값 갱신
}

int main() {
	ios::sync_with_stdio(0), cin.tie(0);
	cin >> n; d[n + 1] = -1010;
	for (int i = 1; i <= n; ++i) cin >> a[i];
	dp(1); cout << ans;
}