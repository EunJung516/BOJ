#include <iostream>
#include <cmath>
using namespace std;

int N, Q, i, j, a[1010], b[1010];

int main() {
	ios::sync_with_stdio(0), cin.tie(0);
	cin >> N >> Q; for (int i = 1; i <= N; ++i) {
		cin >> a[i]; b[i] = abs(a[i] - a[i - 1]) + b[i - 1];  // 앞 박자와의 차이에 대한 누적합 계산
	}
	while (Q--) {
		cin >> i >> j; cout << b[j] - b[i] << '\n';
	}
}