#include <iostream>
using namespace std;

int R, C, Q, mp[1010][1010], r1, r2, c1, c2;

int main() {
	ios::sync_with_stdio(0), cin.tie(0);
	cin >> R >> C >> Q;
	for (int i = 1; i <= R; ++i) {
		for (int j = 1; j <= C; ++j) {
			cin >> mp[i][j]; mp[i][j] += mp[i - 1][j] + mp[i][j - 1] - mp[i - 1][j - 1];  // 누적합 계산
		}
	}
	while (Q--) {
		cin >> r1 >> c1 >> r2 >> c2;
		cout << (mp[r2][c2] - mp[r2][c1 - 1] - mp[r1 - 1][c2] + mp[r1 - 1][c1 - 1]) / ((r2 - r1 + 1) * (c2 - c1 + 1)) << '\n';  // 밝기 평균 출력
	}
}