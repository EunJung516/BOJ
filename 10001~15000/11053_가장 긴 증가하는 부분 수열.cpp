#include <iostream>
#include <algorithm>
using namespace std;

int N, ans;
int d[1010], A[1010];

void dp(int v) {
	d[v] = 1;
	for (int i = v + 1; i <= N; ++i) {
		if (A[v] < A[i]) {    // 다음 원소가 큰 경우
			if (!d[i]) dp(i);
			d[v] = max(d[v], 1 + d[i]);
		}
	}
	ans = max(d[v], ans);    // 가장 긴 증가하는 부분 수열의 길이 갱신
}

int main() {
	ios::sync_with_stdio(0), cin.tie(0);
	cin >> N;
	for (int i = 1; i <= N; ++i) cin >> A[i];
	for (int i = 1; i <= N; ++i) {
		if (!d[i]) dp(i);
	}
	cout << ans;
}