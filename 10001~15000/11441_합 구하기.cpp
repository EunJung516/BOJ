#include <iostream>
using namespace std;

int N, A[100010], M, i, j;

int main() {
	ios::sync_with_stdio(0), cin.tie(0);
	cin >> N;
	for (int i = 1; i <= N; ++i) {
		cin >> A[i]; A[i] += A[i - 1];
	}
	cin >> M; while (M--) {
		cin >> i >> j; cout << A[j] - A[i - 1] << '\n';  // 구간합을 출력
	}
}