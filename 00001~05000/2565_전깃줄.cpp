#include <iostream>
#include <algorithm>
using namespace std;

int N, ans, d[1010];
pair<int, int> A[1010];

void dp(int v) {
	d[v] = 1;
	for (int i = v + 1; i < N; ++i) {
		if (A[v].second < A[i].second) {    // 위치의 번호가 증가하는 경우
			if (!d[i]) dp(i);
			d[v] = max(d[v], 1 + d[i]);
		}
	}
	ans = max(d[v], ans);    // 두번째 위치의 번호가 증가하는 가장 많은 전깃줄의 개수 저장
}

int main() {
	ios::sync_with_stdio(0), cin.tie(0);
	cin >> N;
	for (int i = 0; i < N; ++i) cin >> A[i].first >> A[i].second;    // 전깃줄 저장
	sort(A, A + N);
	for (int i = 0; i < N; ++i) {
		if (!d[i]) dp(i);
	}
	cout << N - ans;    // 없애야 하는 전깃줄의 최소 개수 출력
}