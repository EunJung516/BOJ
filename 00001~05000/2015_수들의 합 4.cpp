#include <iostream>
#include <map>
using namespace std;

long long N, K, ans;
long long A[200010], sum[200010];
map<long long, long long> cnt;

int main() {
	ios::sync_with_stdio(0), cin.tie(0);
	cin >> N >> K; cnt[0] = 1;
	for (int i = 1; i <= N; ++i) {
		cin >> A[i]; sum[i] = A[i] + sum[i - 1];   // 누적 합 계산
		ans += cnt[sum[i] - K];    // 앞에서 현재 위치까지의 부분합이 K인 경우의 수 더하기
		++cnt[sum[i]];
	}
	cout << ans;
}