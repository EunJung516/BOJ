#include <iostream>
using namespace std;

int N, M, i, j;
int num[100010], sum[100010];

int main() {
	ios::sync_with_stdio(0), cin.tie(0);
	cin >> N >> M; 
	for (int i = 1; i <= N; ++i) {    // 누적 합 계산
		cin >> num[i]; sum[i] = num[i] + sum[i - 1];
	}
	while (M--) {
		cin >> i >> j;
		cout << sum[j] - sum[i - 1] << '\n';
	}
}