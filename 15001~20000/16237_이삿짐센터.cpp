#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;

int ans, a[6];

int main() {
	ios::sync_with_stdio(0), cin.tie(0);
	for (int i = 1; i <= 5; ++i) cin >> a[i];
	ans += a[5];  // 5kg 물건 처리

	ans += a[4];  // 4kg 물건 처리
	a[1] = max(0, a[1] - a[4]);

	ans += a[3];  // 3kg 물건 처리
	if (a[2] < a[3]) {
		a[3] -= a[2];
		a[1] = max(0, a[1] - a[3] * 2);
		a[2] = 0;
	}
	else a[2] = max(0, a[2] - a[3]);


	ans += a[2] / 2;  // 2kg 물건 처리
	a[1] = max(0, a[1] - a[2] / 2);

	if (a[2] % 2) {
		++ans; a[1] = max(0, a[1] - 3);
	}

	ans += ceil(a[1] / 5.0);  // 1kg 물건 처리

	cout << ans;
}