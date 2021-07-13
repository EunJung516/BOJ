#include <iostream>
#include <algorithm>
using namespace std;

int N, K, sum, ptr1, ptr2, a[1000010];
int ans = 1000010;

int main() {
	ios::sync_with_stdio(0), cin.tie(0);
	cin >> N >> K;
	for (int i = 0; i < N; ++i) cin >> a[i];
	sum = (a[0] == 1);
	while (1) {    // 투포인터 활용
		if (sum >= K) ans = min(ans, ptr2 - ptr1 + 1);

		if (ptr1 == N - 1 && ptr2 == N - 1) break;
		if (ptr1 == ptr2) {
			sum += (a[++ptr2] == 1);    // 라이언인 경우 1 더하기
			continue;
		}
		if (ptr2 == N - 1) {
			sum -= (a[ptr1++] == 1);    // 라이언인 경우 1 빼주기
			continue;
		}
		if (sum < K) {
			sum += (a[++ptr2] == 1);    // 라이언인 경우 1 더하기
			continue;
		}
		if (sum >= K) {
			sum -= (a[ptr1++] == 1);    // 라이언인 경우 1 빼주기
			continue;
		}
	}
	cout << (ans == 1000010 ? -1 : ans);
}