#include <iostream>
using namespace std;

int num[1030][1030], sum[1030][1030];

int main() {
	ios::sync_with_stdio(0), cin.tie(0);
	int N, M, x1, y1, x2, y2, ans;
	cin >> N >> M; 
	for (int i = 1; i <= N; ++i) {
		for (int j = 1; j <= N; ++j) {
			cin >> num[i][j];
			sum[i][j] = num[i][j] + sum[i - 1][j] + sum[i][j - 1] - sum[i - 1][j - 1];    // 누적 합 계산
		}
	}
	while (M--) {
		cin >> x1 >> y1 >> x2 >> y2;
		cout << sum[x2][y2] - sum[x1 - 1][y2] - sum[x2][y1 - 1] + sum[x1 - 1][y1 - 1] << '\n';
	}
}