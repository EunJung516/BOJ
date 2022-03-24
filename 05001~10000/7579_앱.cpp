#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

int n, m, a[101], c, d[10001], an = 2e9;

int main() {
	ios::sync_with_stdio(0), cin.tie(0);
	cin >> n >> m; memset(d, -1, sizeof(d)); d[0] = 0;
	for (int i = 0; i < n; ++i) cin >> a[i];
	for (int i = 0; i < n; ++i) {
		cin >> c; for (int j = 10000; j >= c; --j) {
			if (~d[j - c]) d[j] = max(d[j], d[j - c] + a[i]);
			if (d[j] >= m) an = min(an, j);
		}
	}
	cout << an;
}