#include <iostream>
using namespace std;

int N, Q, s, e, ans, tmp;
int num[1000010], sum[1000010];

int main() {
	ios::sync_with_stdio(0), cin.tie(0);
	cin >> N >> Q; 
	cin >> num[1]; sum[1] = num[1];
	for (int i = 2; i <= N; ++i) {    // 누적 배타 논리합 계산
		cin >> num[i]; sum[i] = num[i] ^ sum[i - 1];
	}
	for (int i = 1; i <= Q; ++i) {
		cin >> s >> e;
		if (s == 1) tmp = sum[e];
		else tmp = sum[e] ^ sum[s - 1];

		if (i == 1) ans = tmp;
		else ans = ans ^ tmp;
	}
	cout << ans;
}