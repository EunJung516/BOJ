#include <iostream>
#include <algorithm>
using namespace std;

int N, c = 1, a[320], d[320][100010];

int main() {
	ios::sync_with_stdio(0), cin.tie(0);
	cin >> N; for (; c * c <= N; ++c) a[c] = c * c;
	for (int i = 1; i <= c; ++i) {
		for (int j = 0; j <= N; ++j) d[i][j] = 1e9;
	}
	for (int i = 1; i <= c; ++i) {
		d[i][0] = 0;
		for (int j = 0; j <= N; ++j) {
			d[i + 1][j] = min(d[i + 1][j], d[i][j]);
			int jj = j + a[i];
			if (jj <= N) d[i][jj] = min(d[i][jj], d[i][j] + 1);  // 더한 게 N을 넘지 않는 경우
		}
	}
	cout << d[c][N];
}