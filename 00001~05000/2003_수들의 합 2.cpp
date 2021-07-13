#include <iostream>
using namespace std;

int N, M, sum, ans, ptr1, ptr2, A[10010];

int main() {
	ios::sync_with_stdio(0), cin.tie(0);
	cin >> N >> M;
	for (int i = 0; i < N; ++i) cin >> A[i];
	sum = A[0];
	while (1) {    // 투포인터 활용
		if (sum == M) ++ans;

		if (ptr1 == N - 1 && ptr2 == N - 1) break;
		if (ptr1 == ptr2) {
			sum += A[++ptr2];
			continue;
		}
		if (ptr2 == N - 1) {
			sum -= A[ptr1++];
			continue;
		}
		if (sum > M) {
			sum -= A[ptr1++];
			continue;
		}
		if (sum <= M) {
			sum += A[++ptr2];
			continue;
		}
	}
	cout << ans;
}