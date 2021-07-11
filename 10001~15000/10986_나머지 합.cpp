#include <iostream>
using namespace std;

long long N, M, ans;
long long num[1000010], sum[1000010], cnt[1010];

int main() {
	ios::sync_with_stdio(0), cin.tie(0);
	cin >> N >> M;
	for (int i = 1; i <= N; ++i) {
		cin >> num[i]; sum[i] = num[i] + sum[i - 1];
		++cnt[sum[i] % M];    // 누적 합을 M으로 나눈 나머지의 해당 개수 증가
	}
	ans = cnt[0];    // M으로 나누어 떨어지는 개수 저장
	for (int i = 0; i < M; ++i)    // M으로 나누어 떨어지는 구간의 개수 더하기
		ans += cnt[i] * (cnt[i] - 1) / 2;
	cout << ans;
}