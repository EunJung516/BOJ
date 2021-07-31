#include <iostream>
#include <algorithm>
using namespace std;

int N, ans;
int d[1010][2], A[1010];
// d의 첫번재 열은 해당 원소부터의 바이토닉 수열의 가장 긴 길이
// d의 두번째 열은 해당 원소부터의 감소하는 수열의 가장 긴 길이

void dp(int v) {
	d[v][0] = d[v][1] = 1;
	for (int i = v + 1; i <= N; ++i) {
		if (A[v] < A[i]) {    // 다음 원소가 큰 경우
			if (!d[i][0]) dp(i);
			d[v][0] = max(d[v][0], max(d[i][0], d[i][1]) + 1);
		}
		if (A[v] > A[i]) {    // 다음 원소가 작은 경우
			if (!d[i][1]) dp(i);
			d[v][1] = max(d[v][1], d[i][1] + 1);
		}
	}
	ans = max(ans, max(d[v][0], d[v][1]));    // 가장 긴 바이토닉 수열의 길이 갱신
}

int main() {
	ios::sync_with_stdio(0), cin.tie(0);
	cin >> N;
	for (int i = 1; i <= N; ++i) cin >> A[i];
	for (int i = 1; i <= N; ++i) {
		if (!d[i][0]) dp(i);
	}
	cout << ans;
}